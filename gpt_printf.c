/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpt_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <your@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:00:00 by yourlogin         #+#    #+#             */
/*   Updated: 2025/05/07 00:00:00 by yourlogin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* ************************************************************************** */
/*                                                                            */
/*                             utils.c                                        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t   ft_strlen(const char *s)
{
	size_t i = 0;
	while (s && s[i])
		i++;
	return (i);
}

static void ft_putnchar(char c, int n, int *len)
{
	while (n-- > 0)
		*len += write(1, &c, 1);
}

static char *ft_strdup(const char *s)
{
	size_t  i = 0;
	char	*dup;
	if (!s)
		return (NULL);
	dup = (char *)malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static char *ft_utoa_base(unsigned long n, unsigned int base, int upper)
{
	char			buf[32];
	const char	  *tbl = upper ? "0123456789ABCDEF" : "0123456789abcdef";
	char			*res;
	int			 i = 30;
	if (n == 0)
		buf[i--] = '0';
	while (n > 0)
	{
		buf[i--] = tbl[n % base];
		n /= base;
	}
	res = ft_strdup(&buf[i + 1]);
	return (res);
}

static char *ft_itoa_long(long n)
{
	unsigned long   tmp;
	char			*digits;
	char			*str;
	int			 neg;

	neg = (n < 0);
	tmp = neg ? -(unsigned long)n : (unsigned long)n;
	digits = ft_utoa_base(tmp, 10, 0);
	if (!digits)
		return (NULL);
	if (!neg)
		return (digits);
	str = (char *)malloc(ft_strlen(digits) + 2);
	if (!str)
		return (free(digits), NULL);
	str[0] = '-';
	for (size_t i = 0; digits[i]; ++i)
		str[i + 1] = digits[i];
	str[ft_strlen(digits) + 1] = '\0';
	free(digits);
	return (str);
}

/* ************************************************************************** */
/*						  printer helpers								   */
/* ************************************************************************** */

static int  max(int a, int b)
{
	return (a > b ? a : b);
}

static void init_format(t_format *f)
{
	f->flag_minus = 0;
	f->flag_zero = 0;
	f->flag_hash = 0;
	f->flag_space = 0;
	f->flag_plus = 0;
	f->width = 0;
	f->precision = 0;
	f->dot = 0;
	f->spec = '\0';
}

static void parse_flags(const char *s, int *i, t_format *f)
{
	while (s[*i] == '-' || s[*i] == '0' || s[*i] == '#' ||
		   s[*i] == ' ' || s[*i] == '+')
	{
		if (s[*i] == '-')
			f->flag_minus = 1;
		if (s[*i] == '0')
			f->flag_zero = 1;
		if (s[*i] == '#')
			f->flag_hash = 1;
		if (s[*i] == ' ')
			f->flag_space = 1;
		if (s[*i] == '+')
			f->flag_plus = 1;
		(*i)++;
	}
	if (f->flag_minus)
		f->flag_zero = 0;
}

static int  atoi_move(const char *s, int *i)
{
	int n = 0;
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		n = n * 10 + (s[*i] - '0');
		(*i)++;
	}
	return (n);
}

static void parse_width_prec(const char *s, int *i, t_format *f, va_list *ap)
{
	if (s[*i] == '*')
	{
		f->width = va_arg(*ap, int);
		if (f->width < 0)
		{
			f->flag_minus = 1;
			f->width = -f->width;
		}
		(*i)++;
	}
	else
		f->width = atoi_move(s, i);
	if (s[*i] == '.')
	{
		(*i)++;
		f->dot = 1;
		if (s[*i] == '*')
		{
			f->precision = va_arg(*ap, int);
			(*i)++;
		}
		else
			f->precision = atoi_move(s, i);
		if (f->precision < 0)
			f->dot = 0;
	}
}

/* ----------------------------- output core --------------------------------- */

static void print_number_prefix(long sign, t_format *f, int *len)
{
	if (sign < 0)
		*len += write(1, "-", 1);
	else if (f->flag_plus)
		*len += write(1, "+", 1);
	else if (f->flag_space)
		*len += write(1, " ", 1);
}

static int  handle_str(char *str, t_format *f)
{
	int len = 0;
	int str_len;

	if (!str)
		str = "(null)";
	str_len = (int)ft_strlen(str);
	if (f->dot && f->precision < str_len)
		str_len = f->precision;
	if (!f->flag_minus)
		ft_putnchar(' ', f->width - str_len, &len);
	len += write(1, str, str_len);
	if (f->flag_minus)
		ft_putnchar(' ', f->width - str_len, &len);
	return (len);
}

static int  handle_uint(unsigned long n, t_format *f, unsigned base, int upper)
{
	char	*num;
	int	 num_len;
	int	 pad_zero;
	int	 len = 0;

	if (f->spec == 'p' && n == 0 && f->dot && f->precision == 0)
		num = ft_strdup("");
	else
		num = ft_utoa_base(n, base, upper);
	if (!num)
		return (0);
	num_len = (int)ft_strlen(num);
	if (f->dot && f->precision == 0 && n == 0 && f->spec != 'p')
		num_len = 0;
	if (f->spec == 'p' || (f->flag_hash && n != 0 && (f->spec == 'x' || f->spec == 'X')))
		num_len += 2;
	pad_zero = f->precision - (int)ft_strlen(num);
	if (!f->dot && f->flag_zero && !f->flag_minus)
		pad_zero = max(pad_zero, f->width - num_len);
	if (!f->flag_minus)
		ft_putnchar(' ', f->width - num_len - max(0, pad_zero), &len);
	if (f->spec == 'p')
		len += write(1, "0x", 2);
	else if (f->flag_hash && n != 0 && f->spec == 'x')
		len += write(1, "0x", 2);
	else if (f->flag_hash && n != 0 && f->spec == 'X')
		len += write(1, "0X", 2);
	ft_putnchar('0', pad_zero, &len);
	if (!(f->dot && f->precision == 0 && n == 0 && f->spec != 'p'))
		len += write(1, num, ft_strlen(num));
	if (f->flag_minus)
		ft_putnchar(' ', f->width - num_len - max(0, pad_zero), &len);
	return (free(num), len);
}

static int  handle_int(long n, t_format *f)
{
	char	*num;
	int	 num_len;
	int	 pad_zero;
	int	 len = 0;
	long	sign = (n < 0) ? -1 : 1;

	num = ft_itoa_long(n);
	if (!num)
		return (0);
	num_len = (int)ft_strlen(num);
	if (f->dot && f->precision == 0 && n == 0)
		num_len = (sign < 0 || f->flag_plus || f->flag_space);
	pad_zero = f->precision - (int)ft_strlen(num) + (sign < 0);
	if (!f->dot && f->flag_zero && !f->flag_minus)
		pad_zero = max(pad_zero, f->width - num_len);
	if (!f->flag_minus)
		ft_putnchar(' ', f->width - num_len - max(0, pad_zero), &len);
	print_number_prefix(sign, f, &len);
	ft_putnchar('0', pad_zero, &len);
	if (!(f->dot && f->precision == 0 && n == 0))
		len += write(1, (sign < 0) ? num + 1 : num, ft_strlen(num) - (sign < 0));
	if (f->flag_minus)
		ft_putnchar(' ', f->width - num_len - max(0, pad_zero), &len);
	return (free(num), len);
}

static int  dispatch(t_format *f, va_list *ap)
{
	if (f->spec == 'c')
	{
		char c = (char)va_arg(*ap, int);
		return (handle_str((char[]){c, '\0'}, f));
	}
	if (f->spec == 's')
		return (handle_str(va_arg(*ap, char *), f));
	if (f->spec == 'p')
		return (handle_uint((unsigned long)va_arg(*ap, void *), f, 16, 0));
	if (f->spec == 'd' || f->spec == 'i')
		return (handle_int((long)va_arg(*ap, int), f));
	if (f->spec == 'u')
		return (handle_uint((unsigned long)va_arg(*ap, unsigned int), f, 10, 0));
	if (f->spec == 'x')
		return (handle_uint((unsigned long)va_arg(*ap, unsigned int), f, 16, 0));
	if (f->spec == 'X')
		return (handle_uint((unsigned long)va_arg(*ap, unsigned int), f, 16, 1));
	if (f->spec == '%')
		return (handle_str("%", f));
	return (0);
}

/* ************************************************************************** */
/*							gpt_printf.c									 */
/* ************************************************************************** */

int gpt_printf(const char *fmt, ...)
{
	int		 i = 0;
	int		 total = 0;
	va_list	 ap;
	t_format	f;

	va_start(ap, fmt);
	while (fmt && fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			init_format(&f);
			parse_flags(fmt, &i, &f);
			parse_width_prec(fmt, &i, &f, &ap);
			f.spec = fmt[i];
			total += dispatch(&f, &ap);
		}
		else
			total += write(1, &fmt[i], 1);
		i++;
	}
	va_end(ap);
	return (total);
}
// #include <stdio.h>
// int main(void)
// {
// 	char a[10] = "abc";
// 	printf("%d\n", gpt_printf("%pohayo%1d%i\n", a, 123, 45));
// }