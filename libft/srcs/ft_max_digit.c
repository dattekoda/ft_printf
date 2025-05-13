/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-06 21:09:21 by khanadat          #+#    #+#             */
/*   Updated: 2025-05-06 21:09:21 by khanadat         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_max_digit(int count, int ary)
{
	long long	res;

	res = 1;
	count--;
	while (count--)
		res *= ary;
	return (res);
}

//INT_MAX超えたらばぐる
// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d", ft_max_digit(31, 2));
// }