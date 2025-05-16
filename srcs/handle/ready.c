#include "ft_handle.h"
#include "libft.h"

char	*ready_uint(unsigned long n, t_fmt *f, unsigned base)
{
	char	*re;
	char	*tmp;

	if (f->flags & FLAG_DOT && f->prec == 0 && n == 0)
		re = ft_strdup("");
	else if (f->spec == 'p' && n == 0)
		re = ft_strdup("(nil)");
	else
	{
		re = ft_utoa_base(n, f, base);
		if (f->flags & FLAG_HASH && n != 0)
		{
			if (f->spec == 'X')
				tmp = ft_strjoin("0X", re);
			else
				tmp = ft_strjoin("0x", re);
			free(re);
			re = tmp;
		}
	}
	return (re);
}


