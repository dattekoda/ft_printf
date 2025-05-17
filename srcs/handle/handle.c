#include "ft_handle.h"
#include "libft.h"

int	handle_char(char c, const t_fmt *f)
{
	int	len;

	len = 0;
	if (f->width > 1 && !(f->flags & FLAG_MINUS))
		ft_putnchar(' ', f->width - 1, &len);
	len += write(1, &c, 1);
	if (f->width > 1 && f->flags & FLAG_MINUS)
		ft_putnchar(' ', f->width - 1, &len);
	return (len);
}

int	handle_str(char *s, const t_fmt *f)
{
	int	len;
	int	slen;

	if (!s)
		return (handle_null(f));
	len = 0;
	slen = (int)ft_strlen(s);
	if (f->flags & FLAG_DOT && f->prec < slen)
		slen = f->prec;
	if (f->width > slen && !(f->flags & FLAG_MINUS))
		ft_putnchar(' ', f->width - slen, &len);
	len += write(1, s, slen);
	if (f->width > slen && f->flags & FLAG_MINUS)
		ft_putnchar (' ', f->width - slen, &len);
	return (len);
}

int	handle_null(const t_fmt *f)
{
	int	len;

	len = 0;
	if (6 <= f->prec || !(f->flags & FLAG_DOT))
	{
		if (6 <= f->width && !(f->flags & FLAG_MINUS))
			ft_putnchar(' ', f->width - 6, &len);
		len += write(1, "(null)", 6);
		if (6 <= f->width && f->flags & FLAG_MINUS)
			ft_putnchar(' ', f->width - 6, &len);
	}
	else
		ft_putnchar(' ', f->width, &len);
	return (len);
}

int	handle_uint(unsigned long n, t_fmt *f, unsigned int base)
{
	char	*num;
	int		len;

	len = 0;
	num = ready_uint(n, f, base);
	if (!num)
		return (-1);
	if (f->flags & FLAG_MINUS)
		output_left(num, f, &len);
	else
		output_right(num, f, &len);
	return (free(num), len);
}

int	handle_sint(long n, t_fmt *f)
{
	char	*num;
	int		len;

	len = 0;
	num = ready_sint(n, f);
	if (!num)
		return (-1);
	if (f->flags & FLAG_MINUS)
		output_left(num, f, &len);
	else
		output_right(num, f, &len);
	return (free(num), len);
}
