 #include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	unsigned	n = -1;

	// printf("real: %d\n", printf("%u\n", n));
	// printf("ft  : %d\n", ft_printf("%u\n", n));

	// printf("real: %d\n", printf("% 20u\n", n));
	// printf("ft  : %d\n", ft_printf("% 20u\n", n));

	// printf("real: %d\n", printf("%.20u\n", n));
	// printf("ft  : %d\n", ft_printf("%.20u\n", n));

	// printf("real: %d\n", printf("% 40.20u\n", n));
	// printf("ft  : %d\n", ft_printf("% 40.20u\n", n));

	printf("real: %d\n", printf("%30.15u\n", n));
	printf("ft  : %d\n", ft_printf("%30.15u\n", n));

	// printf("real: %d\n", printf("%020u\n", n));
	// printf("ft  : %d\n", ft_printf("%020u\n", n));

	// printf("real: %d\n", printf("|% 20.13u|\n", n));
	// printf("ft  : %d\n", ft_printf("|% 20.13u|\n", n));

	// printf("real: %d\n", printf("|%++00--20.5u|\n", n));
	// printf("ft  : %d\n", ft_printf("|%++00--20.5u|\n", n));

	// printf("real: %d\n", printf("|%2147483647u|\n", 317));
	// printf("ft  : %d\n", ft_printf("|%2147483647.u|\n", 317));

    // printf("%d\n", printf("% 05.3x\n", 0));
    // printf("%d\n", ft_printf("% 05.3x\n", 0));
}