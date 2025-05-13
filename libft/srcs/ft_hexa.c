
#include "libft.h"
#include <stdio.h>

char	*ft_hexa(unsigned long	n)
{
	int			count;
	long long	max;
	int			i;
	char		*output;

	count = ft_count_digit(n, 16);
	max = ft_max_digit(count, 16);
	output = (char *)malloc(count + 1);
	if (!output)
		return (NULL);
	i = 0;
	while (max > 0)
	{
		output[i++] = (char) ft_base(n / max, "0123456789abcdef");
		n %= max;
		max /= 16;
	}
	output[i] = '\0';
	return (output);
}

// int main(int argc, char *argv[])
// {
// 	char	*hex_num;
// 	if (argc > 1)
// 	{
// 		hex_num = ft_HEXA(atoi(argv[1]));
// 		printf("%s\n", hex_num);
// 		free(hex_num);
// 	}
// 	return (0);
// }