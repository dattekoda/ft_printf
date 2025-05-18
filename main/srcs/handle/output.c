/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:27:54 by khanadat          #+#    #+#             */
/*   Updated: 2025/05/18 11:12:25 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fmt.h"
#include "ft_handle.h"
#include "libft.h"

void	output_left(char *s, const t_fmt *f, int *len)
{
	ft_putstr_len(s, len);
	if (f->width > f->len)
		ft_putnchar(' ', f->width - f->len, len);
}

void	output_right(char *s, const t_fmt *f, int *len)
{
	if (f->width > f->len)
		ft_putnchar(' ', f->width - f->len, len);
	ft_putstr_len(s, len);
}
