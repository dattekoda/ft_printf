/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-28 05:21:44 by khanadat          #+#    #+#             */
/*   Updated: 2025-04-28 05:21:44 by khanadat         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		len;

	len = ft_count_digit(n, 10);
	if (n == INT_MIN)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= (-1);
		len--;
	}
	while (len > 0)
		ft_putchar_fd((n / ft_max_digit(len--, 10) % 10) + '0', fd);
}

// #include <stdio.h>
// int main(int argc, char *argv[])
// {
// 	ft_putnbr_fd(2147483647, 1);
// }
