#include "ft_handle.h"
#include "libft.h"

char	*ready_uint(unsigned long n, t_fmt *f, unsigned base)
{
	char	*num;

	if (f->flags & FLAG_DOT && f->prec == 0 && n == 0 && !(f->width))
		num = ft_strdup("");
	else if (f->spec == 'p' && n == 0)
		num = ft_strdup("(nil)");
	else
	{
		f->len = max(count_ditit(n, base), f->prec)
			+ 2 * (f->flags & FLAG_HASH && n != 0);
		num = malloc(f->len + 1);
		if (!num)
			return (NULL);
		num[f->len] = '\0';
		ft_utoa_base(n, f, base, num);
	}
	return (num);
}

