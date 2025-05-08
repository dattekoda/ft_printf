#include <stdarg.h>
#include <stdio.h>

void	sum_and_print(int count, ...)
{
	va_list	ap;
	int		sum = 0;
	int		i;

	va_start(ap, count);
	va_list	ap_copy;
	va_copy(ap_copy, ap);
	i = 0;
	while (i < count)
	{
		int value = va_arg(ap, int);
		sum += value;
		i++;
	}
	printf("Sum of %d values = %d\n", count, sum);
	printf("Values forward: ");
	i = 0;
	while (i < count)
	{
		int	value = va_arg(ap_copy, int);
		printf("%d ", value);
		i++;
	}
	printf("\n");
}

int	main(void)
{
	sum_and_print(6, 3, 1, 4, 1, 11, 12);
	return (0);
}
