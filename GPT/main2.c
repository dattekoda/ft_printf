#include "gpt_printf.h"
#include <stdio.h>

int	main(void)
{
	int	num = 42;
	printf("%03d\n",num);
	gpt_printf("%03d\n",num);
}