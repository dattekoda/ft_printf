#include "ft_handle.h"
#include "libft.h"

static int	count_digit_u(uintptr_t n, unsigned int base)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

static int	count_digit(long n, unsigned int base)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

static	void	count_flen(long n, t_fmt *f)
{
	int	c;

	c = count_digit(n, 10);
	if (f->prec <= c)
		f->len = c + ((f->flags & FLAG_PLUS) || n < 0);
	else if (f->flags & FLAG_ZERO && c < f->width && !(f->flags & FLAG_DOT))
		{f->len = f->width;
			printf("%d\n%d\n%d\n", f->flags & FLAG_ZERO, c < f->width, !(f->flags & FLAG_DOT));}
	else
		f->len = f->prec + ((f->flags & FLAG_PLUS) || n < 0);
}

char	*ready_uint(unsigned long n, t_fmt *f, unsigned int base)
{
	char	*ready;

	if (f->flags & FLAG_DOT && f->prec == 0 && n == 0 && !(f->width))
		ready = ft_strdup("");
	else if (f->spec == 'p' && n == 0)
		ready = ft_strdup("(nil)");
	else
	{
		f->len = 2 * (f->flags & FLAG_HASH && n != 0 && f->spec != 'u')
			+ ft_max(count_digit_u(n, base), f->prec);
		ready = malloc(f->len + 1);
		if (!ready)
			return (NULL);
		ready[f->len] = '\0';
		ft_utoa_base(n, f, base, ready);
	}
	return (ready);
}

char	*ready_sint(long n, t_fmt *f)
{
	char	*ready;

	if (f->flags & FLAG_DOT && f->prec == 0 && n == 0)
	{
		if (f->flags & FLAG_PLUS)
			ready = ((f->len)++, ft_strdup("+"));
		else
			ready = ft_strdup("");
	}
	else
	{
		count_flen(n, f);
		ready = malloc(f->len + 1);
		if (!ready)
			return (NULL);
		ready[f->len] = '\0';
		ft_sitoa(n, f, ready);
	}
	return (ready);
}
