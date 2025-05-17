#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	ft_printf("%5%\n");
	printf("%5%\n");

	ft_printf("|%.03s|\n", NULL);
	printf("|%.03s|\n", NULL);

	ft_printf("2\n");
	ft_printf("|%2s|\n", NULL);
	ft_printf("13\n");
	ft_printf("|%13s|\n", NULL);
	ft_printf("5.5\n");
	ft_printf("|%5.5s|\n", NULL);
	ft_printf(".6\n");
	ft_printf("|%.6s|\n", NULL);
	ft_printf("5.3\n");
	ft_printf("|%5.3s|\n", NULL);
	ft_printf("-5.\n");
	ft_printf("|%-5.s|\n", NULL);
	ft_printf("-20.20\n");
	ft_printf("|%-20.20s|\n", NULL);
	ft_printf("-6.3\n");
	ft_printf("|%-6.3s|\n", NULL);
	ft_printf(".4\n");
	ft_printf("|%.4s|\n", NULL);
	ft_printf("-6.4\n");
	ft_printf("|%-6.4s|\n", NULL);
	ft_printf("6.6\n");
	ft_printf("|%6.6s|\n", NULL);
	ft_printf("-6.5\n");
	ft_printf("|%-6.5s|\n", NULL);
	ft_printf("6.7\n");
	ft_printf("|%6.7s|\n", NULL);
	ft_printf("-6.7\n");
	ft_printf("|%-6.7s|\n", NULL);
	ft_printf("6.10\n");
	ft_printf("|%6.10s|\n", NULL);
	ft_printf("-7.\n");
	ft_printf("|%-7.s|\n", NULL);
}