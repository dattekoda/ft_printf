/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-07 18:19:46 by khanadat          #+#    #+#             */
/*   Updated: 2025-05-07 18:19:46 by khanadat         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr_fd(unsigned int n, int fd)
{
	int		len;

	len = ft_count_digit(n, 10);
	while (len > 0)
		ft_putchar_fd((n / ft_max_digit(len--, 10) % 10) + '0', fd);
}

// int main(void)
// {
// 	ft_putunbr_fd(-1, 1);
// }