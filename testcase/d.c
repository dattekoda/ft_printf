#include <stdio.h>
#include "../main/includes/ft_printf.h"

int	main(void)
{
	// printf("real:%d\n",   printf("|%d|\n", -10) - 3);
	// printf("ft  :%d\n",ft_printf("|%d|\n", -10) - 3);

	// printf("real:%d\n",   printf("|%.0d|\n", 0) - 3);
	// printf("ft  :%d\n",ft_printf("|%.0d|\n", 0) - 3);

	// printf("real:%d\n",   printf("|%10.0d|\n", 0) - 3);
	// printf("ft  :%d\n",ft_printf("|%10.0d|\n", 0) - 3);

	// printf("real:%d\n",   printf("|%10.0d|\n", 4) - 3);
	// printf("ft  :%d\n",ft_printf("|%10.0d|\n", 4) - 3);

	// printf("real:%d\n",   printf("|%+7.3d|\n", 4) - 3);
	// printf("ft  :%d\n",ft_printf("|%+7.3d|\n", 4) - 3);

	// printf("real:%d\n",   printf("|%0+7.0d|\n", 0) - 3);
	// printf("ft  :%d\n",ft_printf("|%0+7.0d|\n", 0) - 3);

	// printf("real:%d\n",   printf("|%07d|\n", -54) - 3);
	// printf("ft  :%d\n",ft_printf("|%07d|\n", -54) - 3);

	// printf("|%-----------7i|\n", 33);
	// ft_printf("|%-----------7i|\n", 33);

	// printf("|%08.5i|\n", 33);
	// ft_printf("|%08.5i|\n", 33);

	// printf("|% +010.0d|\n", 1074329);
	// ft_printf("|% +10.0d|\n", 1074329);

	// printf("|%05i|\n", 43);
	// ft_printf("|%05i|\n", 43);

	// printf("|%05i|\n", -43);
	// ft_printf("|%05i|\n", -43);

	// printf("|%05u|\n", 43);
	// ft_printf("|%05u|\n", 43);

	// printf("|%02.6i|\n", 4312);
	// ft_printf("|%02.6i|\n", 4312);
	// printf("|%06.2i|\n", 4312);
	// ft_printf("|%06.2i|\n", 4312);

	// printf("|%07i|\n", -54);
	// ft_printf("|%07i|\n", -54);

	// printf("|%0d|\n", 0);
	// ft_printf("|%0d|\n", 0);

	printf("%d\n", printf("%d\n", NULL));
	printf("%d\n", ft_printf("%d\n", NULL));
}