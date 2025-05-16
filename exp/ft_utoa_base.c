#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define FLAG_HASH 0b00010000

typedef struct s_fmt //フォーマット解析用構造体
{
	uint8_t 	flags;
	int			width;
	int			prec;
	char		spec;
	int			len;
}	t_fmt;

int	count_ditit(unsigned long n, unsigned base)
{
	int	count;

	count = 0;
	while (n > 0)
		(n /= base, count++);
	return (count);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

void	ft_utoa_base(unsigned long n, t_fmt *f, unsigned base, char *num)
{
	char	base_set[17];

	ft_strlcpy(base_set, "0123456789abcdef", 17);
	if (f->spec == 'X')
		ft_strlcpy(base_set, "0123456789ABCDEF", 17);
	if (n == 0)
		num[--(f->len)] = '0';
	while (n > 0)
	{
		num[--(f->len)] = base_set[n % base];
		n /= base;
	}
	if (f->flags & FLAG_HASH && n != 0)
	{
		if (f->spec == 'X')
			num[--(f->len)] = 'X';
		else
			num[--(f->len)] = 'x';
	}
	while (0 < f->len)
		num[--(f->len)] = '0';
}

int	main(void)
{
	t_fmt	f;
	char	*num;
	int		n = 123456789;
	int		base = 10;

	f.flags = 0;
	f.width = 0;
	f.prec = 16;
	f.spec = 'u';
	f.len = max(count_ditit(n, base), f.prec)
			+ 2 * (f.flags & FLAG_HASH && n != 0);
	printf("f.len: %d\n", f.len);
	num = malloc(f.len + 1);
	if (!num)
		return (1);
	num[f.len] = '\0';
	ft_utoa_base(n, &f, base, num);
	printf("%s\n", num);
	free(num);
	return (0);
}