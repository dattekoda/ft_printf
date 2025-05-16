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
	int		nlen;

	len = 0;
	if (f->flags & FLAG_DOT && f->prec == 0 && n == 0)
		num = ft_strdup("");
	else if (f->spec == 'p' && n == 0)
		num = ft_strdup("(nil)");
	else
		num = ft_utoa_base(n, f, base);
	if (!num)
		return (0);
	nlen = (int)ft_strlen(num);
	if (f->flags & FLAG_HASH && n == 0)
		f->flags ^= FLAG_HASH;
	else if (f->flags & FLAG_HASH)
		(nlen += 2, f->prec += 2);
	if (f->flags & FLAG_MINUS)
		output_left(num, f, nlen, &len);
	else
		output_right(num, f, nlen, &len);
	return (free(num), len);
}