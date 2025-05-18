#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int    ft_printf(const char *fmt, ...);

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0); /// バッファリング機能をなくすやつ
    close(1);
    int rev = printf("%cBCDEF", 'A');
	int rev2 = ft_printf("%cBCDEF", 'A');
    dprintf(2, "rev: %d\n", rev);
	dprintf(2, "rev2: %d\n", rev2);
}
