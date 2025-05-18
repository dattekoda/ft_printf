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

	// printf("real: %d\n", printf("|% 030.17u|\n", n));
	// printf("ft  : %d\n", ft_printf("|% 030.17u|\n", n));

	// printf("real: %d\n", printf("|%020u|\n", n));
	// printf("ft  : %d\n", ft_printf("|%020u|\n", n));

	// printf("real: %d\n", printf("|% 20.13u|\n", n));
	// printf("ft  : %d\n", ft_printf("|% 20.13u|\n", n));

	// printf("real: %d\n", printf("|%++00--20.5u|\n", n));
	// printf("ft  : %d\n", ft_printf("|%++00--20.5u|\n", n));

	// printf("real: %d\n", printf("|%2147483647u|\n", 317));
	// printf("ft  : %d\n", ft_printf("|%2147483647.u|\n", 317));

    // printf("%d\n", printf("|%x|\n", 0));
    // printf("%d\n", ft_printf("|%x|\n", 0));

	// printf("%d\n", printf("|%#x|\n", 100));
    // printf("%d\n", ft_printf("|%#x|\n", 100));

	printf("real: %d\n",    printf("|%05.3u|\n", 1) - 3);
    printf("ft  : %d\n", ft_printf("|%05.3u|\n", 1) - 3);

	printf("|%06.u|\n", 4312);
	ft_printf("|%06.u|\n", 4312);
	printf("|%03.3u|\n", 4312);
	ft_printf("|%03.3u|\n", 4312);
	printf("|%5.0u|\n", 0);
	ft_printf("|%5.0u|\n", 0);
	printf("|%08.3x|\n", 8375);
	ft_printf("|%08.3x|\n", 8375);
	printf("|%-5.0x|\n", 0);
	ft_printf("|%-5.0x|\n", 0);
	printf("|%x|\n", 4294967295u);
	ft_printf("|%x|\n", 4294967295u);

	printf("|%-3u|\n", 0);
	ft_printf("|%-3u|\n", 0);

	printf("|a%ub%uc%ud|\n", 0, 55555, 100000);
	ft_printf("|a%ub%uc%ud|\n", 0, 55555, 100000);
}