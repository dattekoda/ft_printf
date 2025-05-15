#include <stdio.h>
#include "ft_printf.h"
int	main(void)
{
	printf("\ntotal = %d\n", ft_printf("%-10.21u", 324));
	printf("\ntotal = %d\n", printf("%-10.21u", 324));
}