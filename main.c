#include <stdio.h>
#include "libft.h"

int	try_printf(const char *format, ...);
int	gpt_printf(const char *format, ...);

int	main(int argc, char *argv[])
{
	if (argc < 2)
		return (0);
	char a[10] = "def";
	int n = atoi(argv[1]);
	int real = printf("100%%yuuki, %s at %p, first chr is %c. And the number is d:%d, u:%u, hexa:%x, HEXA:%X\n", a, a, a[0], n, n, n, n);
	int try = try_printf("100%%yuuki, %s at %p, first chr is %c. And the number is d:%d, u:%u, hexa:%x, HEXA:%X\n", a, a, a[0], n, n, n, n);
	printf("real:%d, try:%d\n", real, try);
	return (0);
}
