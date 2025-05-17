#include "ft_handle.h"
#include "libft.h"

// int print_num_prefix(long sign, t_fmt *f, int *len)
// {
// }

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

	len = 0;
	if (!s)
		s = ft_strdup("(null)");
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

int	handle_uint(unsigned long n, t_fmt *f, unsigned base)
{
	char	*num;
	int		len;

	len = 0;
	num = ready_uint(n, f, base);
	if (!num)
		return (0);
	// printf("f->len  : %d\n", f->len);
	// printf("f->width: %d\n", f->width);
	if (f->flags & FLAG_MINUS)
		output_left(num, f, &len);
	else
		output_right(num, f, &len);
	return (free(num), len);
}