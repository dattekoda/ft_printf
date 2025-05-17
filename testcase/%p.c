#include <stdio.h>
#include "ft_printf.h"

int	main()
{
	char	*str = "abc123";
	printf("%d\n", printf("|%#p|\n", str - 4200000 - 6595));
    printf("%d\n", ft_printf("|%#p|\n", str - 4200000 - 6595));
}