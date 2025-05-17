#include "ft_handle.h"
#include "libft.h"

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
			+ ft_max(count_digit(n, base), f->prec);
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
		// printf("%d\n%d\n%d\n", f->flags & FLAG_PLUS || n < 0, count_digit(n, 10), f->prec);
		f->len = (f->flags & FLAG_PLUS || n < 0)
			+ ft_max(count_digit(n, 10), f->prec);
		ready = malloc(f->len + 1);
		if (!ready)
			return (NULL);
		ready[f->len] = '\0';
		ft_sitoa(n, f, ready);
	}
	return (ready);
}
