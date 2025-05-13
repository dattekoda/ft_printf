#include <stdio.h>
#include <stddef.h>
#include "gpt_printf.h"

int	main(void)
{
	printf("%s", (void*)0);
	gpt_printf("%s", (void*)0);
}
