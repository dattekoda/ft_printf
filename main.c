#include <stdio.h>
#include "ft_printf.h"
int	main(void)
{
	char	*s = "hello";
	printf("\ntotal = %d\n", ft_printf("%20.13p", s));
	printf("\ntotal = %d\n", printf("%20.13p", s));
}