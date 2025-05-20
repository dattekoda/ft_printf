#include <stdio.h>
#include <limits.h>
#include "../main/includes/ft_printf.h"

// int	ft_printf(const char *format, ...);

int	main()
{
	char	*str = "abc123";
	int		ncm_p = 10;
	// printf("%d\n", printf("|%#p|\n", str - 4200000 - 6595));
    // printf("%d\n", ft_printf("|%#p|\n", str - 4200000 - 6595));
	// ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
	// printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);

	// printf("|%15p|\n", NULL);
	// ft_printf("|%15p|\n", NULL);

	// printf("|%-p|\n", &ncm_p);
	// ft_printf("|%-p|\n", &ncm_p);

	void *p = "a";
	ft_printf("|%p|\n", p);
	printf("|%p|\n", p);
}
