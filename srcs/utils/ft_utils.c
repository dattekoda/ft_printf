#include "ft_handle.h"
#include "libft.h"

void	ft_putnchar(char c, int n, int *len)
{
	while (n--)
		*len += write(1, &c, 1);
}

void	ft_putstr_len(const char* s, int *len)
{
	while (*s)
		*len += write(1, s++, 1);
}

char *ft_utoa_base(unsigned long n, const t_fmt *f, unsigned base)
{
	char	num[32];
	char	base_set[17];
	int		i;

	ft_strlcpy(base_set, "0123456789abcdef", 17);
	if (f->spec == 'X')
		ft_strlcpy(base_set, "0123456789ABCDEF", 17);
	i = 31;
	num[31] = '\0';
	if (n == 0)
		num[--i] = '0';
	while (n > 0)
	{
		num[--i] = base_set[n % base];
		n /= base;
	}
	return (ft_strdup(num + i));
}