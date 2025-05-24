#include "../main/includes/ft_printf.h"
#include <printf.h>

int	main(void)
{
	printf("%d\n", printf(0));
	printf("%d\n", ft_printf(0));
}