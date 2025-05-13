#include "libft.h"

char	*ft_HEXA(unsigned long	n)
{
	char	*output;
	char	*o;

	output = ft_hexa(n);
	if (!output)
		return (NULL);
	o = output;
	while (*output)
	{
		*output = ft_toupper(*output);
		output++;
	}
	return (o);
}