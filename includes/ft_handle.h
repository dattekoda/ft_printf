/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-11 22:27:58 by khanadat          #+#    #+#             */
/*   Updated: 2025-05-11 22:27:58 by khanadat         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HANDLE_H
# define FT_HANDLE_H

# include "stdlib.h"
# include "stddef.h"
# include "ft_fmt.h"

int	print_num_prefix(long sign, t_fmt *f, int *len);
int	handle_char(char c, const t_fmt *f);
int	handle_str(char *s, const t_fmt *f);
int	handle_uint(const char *s, t_fmt *f, unsigned base, int upper);
int	handle_int(const char *s, t_fmt *f);

#endif