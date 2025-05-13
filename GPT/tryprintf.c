#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

int	try_printf(const char *format, ...)
{
	va_list	ap;
	int				i;
	char			c;
	char			*s;
	void			*p;
	unsigned long 	addr;
	int				d;
	unsigned int	u;
	int				len;
	int				sp;

	va_start(ap, format);
	i = 0;
	len = 0;
	sp = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				c =  va_arg(ap, int);
				ft_putchar_fd(c, 1);
				len++;
			}
			else if (format[i + 1] == 's')
			{
				s = va_arg(ap, char*);
				ft_putstr_fd(s, 1);
				len += ft_strlen(s);
			}
			else if (format[i + 1] == 'p')
			{
				p = va_arg(ap, void *);
				addr = (unsigned long)p;
				ft_putstr_fd("0x", 1);
				s = ft_hexa(addr);
				if (!s)
					return (-1);
				ft_putstr_fd(s, 1);
				free(s);
				len += 2 + ft_count_digit(addr, 16);
			}
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				d = va_arg(ap, int);
				ft_putnbr_fd(d, 1);
				len += ft_count_digit(d, 10);
			}
			else if (format[i + 1] == 'u')
			{
				u = va_arg(ap, unsigned int);
				ft_putunbr_fd(u, 1);
				len += ft_count_digit(u, 10);
			}
			else if (format[i + 1] == 'x')
			{
				d = va_arg(ap, unsigned int);
				s = ft_hexa((unsigned int) d);
				if (!s)
					return (-1);
				ft_putstr_fd(s, 1);
				free(s);
				len += ft_count_digit((unsigned int) d, 16);
			}
			else if (format[i + 1] == 'X')
			{
				d = va_arg(ap, unsigned int);
				s = ft_HEXA((unsigned int) d);
				if (!s)
					return (-1);
				ft_putstr_fd(s, 1);
				free(s);
				len += ft_count_digit((unsigned int) d, 16);
			}
			else if (format[i + 1] == '%')
			{
				ft_putchar_fd('%', 1);
				len++;
			}
			else
				return (-1);
			i += 2;
		}
		sp = 0;
		if (format[i] == '%')
			continue;
		ft_putchar_fd(format[i], 1);
		i++;
		len++;
	}
	return (len);
}