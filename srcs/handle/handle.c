#include "ft_handle.h"

static size_t ft_strlen(const char *s)
{
	const char *h;

	if (!s)
		return (0);
	h = s;
	while (*s)
		s++;
	return ((size_t)(s - h));
}

static void	ft_putnchar(char c, int n, int *len)
{
	while (n--)
		*len += write(1, &c, 1);
}

static char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t		slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	dup = malloc(slen + 1);
	if (!dup)
		return (NULL);
	dup[slen] = '\0';
	while (slen--)
		dup[slen] = s[slen];
	return (dup);
}

// int print_num_prefix(long sign, t_fmt *f, int *len)
// {
// }

int	handle_char(char c, const t_fmt *f)
{
	int	len;

	len = 0;
	if (!(f->flags & FLAG_MINUS))
		ft_putnchar(' ', f->width - 1, &len);
	len += write(1, &c, 1);
	if (f->flags & FLAG_MINUS)
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
	if (!(f->flags & FLAG_MINUS))
		ft_putnchar(' ', f->width - slen, &len);
	len += write(1, s, slen);
	if (f->flags & FLAG_MINUS)
		ft_putnchar (' ', f->width - slen, &len);
	return (len);
}