#include "ft_fmt.h"
#include "ft_handle.h"

static char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

static int	atoi_move(const char *fmt, unsigned int *i)
{
	int	n;

	n = 0;
	if (!('0' <= fmt[*i] && fmt[*i] <= '9'))
		return (-1);
	while ('0' <= fmt[*i] && fmt[*i] <= '9')
	{
		n = n * 10 + (fmt[*i] - '0');
		(*i)++;
	}
	return (n);
}

void	f_init(t_fmt	*f)
{
	f->flags = 0;
	f->width = 0;
	f->prec = 0;
	f->spec = '\0';
}

void	f_parse_flags(const char *fmt, unsigned int *i, t_fmt *f)
{
	while (ft_strchr("-+ 0#", fmt[*i]))
	{
		if (fmt[*i] == '-')
			f->flags += FLAG_MINUS;
		else if (fmt[*i] == '+')
			f->flags += FLAG_PLUS;
		else if (fmt[*i] == ' ')
			f->flags += FLAG_SPACE;
		else if (fmt[*i] == '0')
			f->flags += FLAG_ZERO;
		else if (fmt[*i] == '#')
			f->flags += FLAG_HASH;
		(*i)++;
	}
	if (FLAG_MINUS)
		f->flags ^= FLAG_ZERO;
}

void	f_parse_width_prec(const char *fmt, unsigned int *i, t_fmt *f)
{
	f->width = atoi_move(fmt, i);
	if (fmt[*i] == '.')
	{
		(*i)++;
		f->flags += FLAG_DOT;
		f->prec = atoi_move(fmt, i);
		if (f->prec < 0)
			f->flags ^= FLAG_DOT;
	}
}

int	dispatch(const t_fmt *f, va_list *ap)
{
	if (f->spec == 'c')
		return (handle_char((char)va_arg(*ap, int), f));
	if (f->spec == 's')
		return (handle_str(va_arg(*ap, char *), f));
	// if (f->spec == 'p')
	// 	return (handle_uint(va_arg(*ap, unsigned), f, 16));
	// if (f->spec == 'd' || f->spec == 'i')
	// 	return (handle_int);
	if (f->spec == 'u')
		return (handle_uint(va_arg(*ap, unsigned), f, 10));
	if (f->spec == 'x')
		return (handle_uint(va_arg(*ap, unsigned), f, 16));
	if (f->spec == 'X')
		return (handle_uint(va_arg(*ap, unsigned), f, 16));
	if (f->spec == '%')
		return (handle_str("%", f));
	return (0);
}