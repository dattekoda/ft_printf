#include <stdio.h>
#include "../main/includes/ft_printf.h"

int	main(void)
{
	// printf("|% d|\n", 122);
	// ft_printf("output: %d\n", ft_printf("|% d|\n", 123) - 3);
	// printf("output: %d\n", printf("|%- 5d|\n", 123) - 3);
	// ft_printf("output: %d\n", ft_printf("|%- 5d|\n", 123) - 3);
	// printf("output: %d\n", printf("|%- 5u|\n", 123) - 3);
	// ft_printf("output: %d\n", ft_printf("|% -5u|\n", 123) - 3);
	printf("output: %d\n", printf("|% 3d|\n", 123) - 3);
	ft_printf("output: %d\n", ft_printf("|% 3d|\n", 123) - 3);
	return (0);
}