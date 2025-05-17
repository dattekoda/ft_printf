#include "ft_handle.h"
#include "libft.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	count_ditit(unsigned long n, unsigned base)
{
	int	count;

	count = 0;
	while (n > 0)
		(n /= base, count++);
	return (count);
}

void	ft_putnchar(char c, int n, int *len)
{
	while (n--)
		*len += write(1, &c, 1);
}

int	ft_putstr_len(const char* s, int *len)
{
	int	start;

	start = *len;
	while (*s)
		*len += write(1, s++, 1);
	return (start - *len);
}

void	ft_utoa_base(unsigned long n, t_fmt *f, unsigned base, char *num)
{
	char	base_set[17];
	int		i;

	ft_strlcpy(base_set, "0123456789abcdef", 17);
	if (f->spec == 'X')
		ft_strlcpy(base_set, "0123456789ABCDEF", 17);
	i = f->len;
	if (n == 0 && f->prec)
		num[--i] = '0';
	while (n > 0)
	{
		num[--i] = base_set[n % base];
		n /= base;
	}
	if (f->flags & FLAG_HASH && n != 0)
	{
		if (f->spec == 'X')
			num[--i] = 'X';
		else
			num[--i] = 'x';
	}
	while (0 < i)
		num[--i] = '0';
}
