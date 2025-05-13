#include "ft_fmt.h"

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
		*i++;
	}
	if (FLAG_MINUS)
		f->flags ^= FLAG_ZERO;
}

void	f_parse_width_prec(const char *fmt, unsigned int *i, t_fmt *f, va_list *ap)
{
	
}

int	dispatch(const t_fmt *f, va_list *ap)
{
	if (f->spec == 'c')
	{
		char c = (char)va_arg(*ap, int);
		return (write(1, 'c', 1));
	}
	if (f->spec == 's')
		return (write(1, 's', 1));
	if (f->spec == 'p')
		return (write(1, 'p', 1));
	if (f->spec == 'd' || f->spec == 'i')
		return (write(1, 'd', 1));
	if (f->spec == 'u')
		return (write(1, 'u', 1));
	if (f->spec == 'x')
		return (write(1, 'x', 1));
	if (f->spec == 'X')
		return (write(1, 'X', 1));
	if (f->spec == '%')
		return (write(1, '%', 1));
	return (0);
}