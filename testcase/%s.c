#include <stdio.h>
#include <stddef.h>
#include "../main/includes/ft_printf.h"

int	main(void)
{
	printf("%d\n", printf(" NULL %s NULL ", NULL));
	printf("%d\n", ft_printf(" NULL %s NULL ", NULL));

	printf("%d\n", printf(" %s ", ""));
	printf("%d\n", ft_printf(" %s ", ""));

	printf("%d\n", printf(" %s ", "1234567890"));
	printf("%d\n", ft_printf(" %s ", "1234567890"));

	printf("%d\n", printf(" %s ", "123456789012345678901234567890"));
	printf("%d\n", ft_printf(" %s ", "123456789012345678901234567890"));
}