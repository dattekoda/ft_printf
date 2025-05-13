/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-06 19:44:03 by khanadat          #+#    #+#             */
/*   Updated: 2025-05-06 19:44:03 by khanadat         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_digit(long long n, int ary)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n == LLONG_MIN)
	{
		count += ft_count_digit(n / ary, ary);
		n %= ary;
		n *= (-1);
	}
	if (n < 0)
		n *= (count++, (-1));
	while (n > 0)
		n /= (count++, ary);
	return (count);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%d\n", ft_count_digit(INT_MIN, 2));
// 	return (0);
// }