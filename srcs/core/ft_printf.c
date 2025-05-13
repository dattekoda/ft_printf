#include "ft_printf.h"
#include "ft_fmt.h"

int	ft_printf(const char *fmt, ...)
{
	unsigned int	i;
	unsigned int	total;
	va_list			ap;
	t_fmt			f;

	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			i++;
			f_init(&f);
			f_parse_flags(fmt, &i, &f);
			f_parse_width_prec(fmt, &i, &f, &ap);
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

int	main(void)
{
	ft_printf("hi");
}