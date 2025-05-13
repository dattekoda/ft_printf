#include <stdio.h>
#include "gpt_printf.h"

// int	try_printf(const char *format, ...);
int	gpt_printf(const char *format, ...);

int	main(int argc, char *argv[])
{
	if (argc < 2)
		return (0);
	char a[10] = "def";
	int n = atoi(argv[1]);
	int real = printf("100%%yuuki, %s at %p, first chr is %c. And the number is d:%d, u:%u, hexa:%x, HEXA:%X\n", a, a, a[0], n, n, n, n);
	int gpt = gpt_printf("100%%yuuki, %s at %p, first chr is %c. And the number is d:%d, u:%u, hexa:%x, HEXA:%X\n", a, a, a[0], n, n, n, n);
	printf("real:%d, gpt:%d\n\n", real, gpt);

	int		num = 42;
	printf("%3d\n", num);
	gpt_printf("%3d\n", num);
	printf("%--3d\n",num);
	gpt_printf("%--3d\n",num);
	printf("%03d\n",num);
	gpt_printf("%03d\n",num);
	printf("%+3d\n",num);
	gpt_printf("%+3d\n",num);
	printf("% 3d\n",num);
	gpt_printf("% 3d\n",num);
	printf("%4.3d\n",num);
	gpt_printf("%4.3d\n",num);
	printf("%6.5d\n",num);
	gpt_printf("%6.5d\n",num);
	printf("%x\n",num);
	gpt_printf("%x\n",num);
	printf("%#x\n",num);
	gpt_printf("%#x\n",num);
	printf("%3s\n",a);
	gpt_printf("%3s\n",a);
	printf("%-3s\n",a);
	gpt_printf("%-3s\n",a);
	printf("%4.3s\n",a);
	gpt_printf("%4.3s\n",a);
	printf("%6.5s\n",a);
	gpt_printf("%6.5s\n",a);
	return (0);
}
