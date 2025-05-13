/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-12 08:53:07 by khanadat          #+#    #+#             */
/*   Updated: 2025-05-12 08:53:07 by khanadat         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BONUS_H
# define FT_BONUS_H

# include "ft_fmt.h"

int	ft_parse_bonus(t_fmt *fmt, const char **format);
int	ft_apply_width_prec(const t_fmt *fmt);

#endif