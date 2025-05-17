#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	unsigned int	i;
	unsigned int	total;
	va_list			ap;
	t_fmt			f;
	int				tmp;

	i = 0;
	total = 0;
	va_start(ap, fmt);
	while (fmt && fmt[i])
	{
		if (fmt[i] == '%')
		{
			tmp = ft_vprintf(fmt, &ap, &i, &f);
			if (tmp == -1)
				return (-1);
			total += tmp;
		}
		else
			total += write(1, &fmt[i], 1);
		i++;
	}
	va_end(ap);
	return (total);
}

int	ft_vprintf(const char *fmt, va_list *ap, unsigned int *i, t_fmt *f)
{
	(*i)++;
	f_init(f);
	f_parse_flags(fmt, i, f);
	f_parse_width_prec(fmt, i, f);
	f->spec = fmt[(*i)];
	return (dispatch(f, ap));
}
