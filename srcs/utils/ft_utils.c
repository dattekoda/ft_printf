#include "ft_handle.h"
#include "libft.h"

void	ft_putnchar(char c, int n, int *len)
{
	if (n == 0)
		return ;
	while (n--)
		*len += write(1, &c, 1);
}

int	ft_putstr_len(const char *s, int *len)
{
	int	start;

	start = *len;
	while (*s)
		*len += write(1, s++, 1);
	return (start - *len);
}

void	ft_utoa_base(unsigned long n, t_fmt *f, unsigned int base, char *num)
{
	char	base_set[17];
	int		i;

	ft_strlcpy(base_set, "0123456789abcdef", 17);
	if (f->spec == 'X')
		ft_strlcpy(base_set, "0123456789ABCDEF", 17);
	i = f->len;
	if (n == 0)
		num[--i] = '0';
	while (n > 0)
	{
		num[--i] = base_set[n % base];
		n /= base;
	}
	if (f->flags & FLAG_HASH && num[i] != '0' && f->spec != 'u')
	{
		if (f->spec == 'X')
			num[--i] = 'X';
		else
			num[--i] = 'x';
	}
	while (0 < i)
		num[--i] = '0';
}

void	ft_sitoa(long n, t_fmt *f, char *num)
{
	int		i;
	long	_n;

	_n = n;
	i = f->len;
	if (n == 0)
		num[--i] = '0';
	if (n < 0)
		n *= (-1);
	while (n > 0)
	{
		num[--i] = ('0' + n % 10);
		n /= 10;
	}
	while (0 < i)
		num[--i] = '0';
	if (_n < 0)
		num[i] = '-';
	else if (f->flags & FLAG_PLUS)
		num[i] = '+';
}
