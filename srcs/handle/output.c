#include "ft_fmt.h"
#include "ft_handle.h"
#include "libft.h"

void	output_left(char *s, const t_fmt *f, int *len)
{
	int	nlen;

	nlen = ft_strlen(s);
	if (f->width > nlen && f->flags & FLAG_SPACE)
		ft_putnchar(' ', f->width - nlen, len);
	else if (f->width > nlen)
		ft_putnchar('0', f->width - nlen, len);
	ft_putstr_len(s, len);
	if (f->width > f->len)
		ft_putnchar(' ', f->width - f->len, len);
}

void	output_right(char *s, const t_fmt *f, int *len)
{
	int	nlen;

	nlen = ft_strlen(s);
	if (f->width > f->len && f->flags & FLAG_SPACE)
		ft_putnchar(' ', f->width - f->len, len);
	else if (f->width > f->len)
		ft_putnchar('0', f->width - f->len, len);
	if (f->flags & FLAG_DOT && f->prec > nlen)
		ft_putnchar('0', f->prec - nlen, len);
	ft_putstr_len(s, len);
}
