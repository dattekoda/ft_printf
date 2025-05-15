#include "ft_fmt.h"
#include "ft_handle.h"

static int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

void	output_left(const char *s, const t_fmt *f, int nlen, int *len)
{
	int	m;

	m = max(nlen, f->prec);
	if (f->flags & FLAG_DOT && f->prec > nlen)
		ft_putnchar('0', f->prec - nlen, len);
	ft_putstr_len(s, len);
	if (f->width > m)
		ft_putnchar(' ', f->width - m, len);
}

void	output_right(const char *s, const t_fmt *f, int nlen, int *len)
{
	int	m;

	if (f->flags & FLAG_HASH)
		nlen -= ft_putstr_len("0x", len);
	m = max(nlen, f->prec);
	if (f->width > m)
		ft_putnchar(' ', f->width - m, len);
	if (f->flags & FLAG_DOT && f->prec > nlen)
		ft_putnchar('0', f->prec - nlen, len);
	ft_putstr_len(s, len);
}
