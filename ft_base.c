#include "libft.h"
#include <stdio.h>

char	ft_base(int n, char *base)
{
	int	blen;

	blen = ft_strlen(base);
	if (blen <= n && n < 0)
		return ('\0');
	return base[n];
}

// int main(void)
// {
// 	printf("%c\n", ft_base(9, "0123456789"));
// }