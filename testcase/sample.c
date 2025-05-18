#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    // printf(" %s %d \n", "abc", 123);
    // ft_printf(" %s \n", "abc");
    printf("|%05d|\n", -1111111);
    ft_printf("|%05d|\n", -1111111);
}