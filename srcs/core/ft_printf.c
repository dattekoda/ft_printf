#include "ft_printf.h"
#include "ft_fmt.h"

int	ft_printf(const char *fmt, ...)
{
	unsigned int	i;
	unsigned int	total;
	va_list			ap;
	t_fmt			f;
	int				d;

	i = 0;
	total = 0;
	va_start(ap, fmt);
	while (fmt && fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			f_init(&f);
			f_parse_flags(fmt, &i, &f);
			f_parse_width_prec(fmt, &i, &f);
			f.spec = fmt[i];
			d = dispatch(&f, &ap);
			if (d == -1)
				return (-1);
			total += dispatch(&f, &ap);
		}
		else
			total += write(1, &fmt[i], 1);
		i++;
	}
	va_end(ap);
	return (total);
}
