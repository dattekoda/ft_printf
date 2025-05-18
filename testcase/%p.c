#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main()
{
	char	*str = "abc123";
	// printf("%d\n", printf("|%#p|\n", str - 4200000 - 6595));
    // printf("%d\n", ft_printf("|%#p|\n", str - 4200000 - 6595));
	ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
	// printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);

	printf("|%15p|\n", NULL);
	ft_printf("|%15p|\n", NULL);
}