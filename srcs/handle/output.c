#include "ft_fmt.h"
#include "ft_handle.h"
#include "libft.h"

static int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

void	output_left(char *s, const t_fmt *f, int *len)
{
	int	m;
	int	nlen;

	nlen = ft_strlen(s);
	m = max(nlen, f->prec);
	if (f->flags & FLAG_DOT && f->prec > nlen)
		ft_putnchar('0', f->prec - nlen, len);
	ft_putstr_len(s, len);
	if (f->width > m)
		ft_putnchar(' ', f->width - m, len);
}

void	output_right(char *s, const t_fmt *f, int *len)
{
	int	m;
	int	nlen;

	nlen = ft_strlen(s);
	m = max(nlen, f->prec);
	if (f->width > m && !(f->flags & FLAG_ZERO))
		ft_putnchar('0', f->width - m, len);
	else if (f->width > m && f->flags & FLAG_ZERO)
		ft_putnchar(' ', f->width - m, len);
	if (f->flags & FLAG_DOT && f->prec > nlen)
		ft_putnchar('0', f->prec - nlen, len);
	ft_putstr_len(s, len);
}
