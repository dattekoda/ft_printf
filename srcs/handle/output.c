#include "ft_fmt.h"
#include "ft_handle.h"
#include "libft.h"

void	output_left(char *s, const t_fmt *f, int *len)
{
	int	nlen;

	nlen = ft_strlen(s);
	ft_putstr_len(s, len);
	if (f->width > f->len)
		ft_putnchar(' ', f->width - f->len, len);
}

void	output_right(char *s, const t_fmt *f, int *len)
{
	int	nlen;

	nlen = ft_strlen(s);
	if (f->width > f->len)
		ft_putnchar(' ', f->width - f->len, len);
	ft_putstr_len(s, len);
}
