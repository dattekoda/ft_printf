#include <stdio.h>
#include <stddef.h>
#include "ft_printf.h"

int	main(void)
{
	printf("%d\n", printf(" NULL %s NULL ", NULL));
	printf("%d\n", ft_printf(" NULL %s NULL ", NULL));	
}