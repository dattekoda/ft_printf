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

# include <stdlib.h>
# include <stddef.h>
# include "ft_fmt.h"

void	ft_putnchar(char c, int n, int *len);
char	*ft_utoa_base(unsigned long n, const t_fmt *f, unsigned base);
int		ft_putstr_len(const char* s, int *len);
int		print_num_prefix(long sign, t_fmt *f, int *len);
int		handle_char(char c, const t_fmt *f);
int		handle_str(char *s, const t_fmt *f);
int		handle_uint(unsigned long n, const t_fmt *f, unsigned base);
int		handle_int(const char *s, const t_fmt *f);
void	output_left(const char *s, const t_fmt *f, int nlen, int *len);
void	output_right(const char *s, const t_fmt *f, int nlen, int *len);

#endif