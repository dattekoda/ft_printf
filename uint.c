 #include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	unsigned	n = 2147483647 * 2 + 1;

	// printf("real: %d\n", printf("%u\n", n));
	// printf("ft  : %d\n", ft_printf("%u\n", n));

	// printf("real: %d\n", printf("%20u\n", n));
	// printf("ft  : %d\n", ft_printf("%20u\n", n));

	// printf("real: %d\n", printf("%.20u\n", n));
	// printf("ft  : %d\n", ft_printf("%.20u\n", n));

	// printf("real: %d\n", printf("%- 40.20u\n", n));
	// printf("ft  : %d\n", ft_printf("%- 40.20u\n", n));

	printf("real: %d\n", printf("%-30.20u\n", n));
	printf("ft  : %d\n", ft_printf("%-30.20u\n", n));

	// printf("real: %d\n", printf("%020u\n", n));
	// printf("ft  : %d\n", ft_printf("%020u\n", n));

	// printf("real: %d\n", printf("%-12.11u\n", n));
	// printf("ft  : %d\n", ft_printf("%-12.11u\n", n));

    // printf("%d\n", printf("%0 5.3x\n", 0));
    // printf("%d\n", ft_printf("% 05.3x\n", 0));
}