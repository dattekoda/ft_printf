/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.h                                        :+:      :+:    :+:   */
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

int		max(int a, int b);
int		count_ditit(unsigned long n, unsigned base);
void	ft_putnchar(char c, int n, int *len);
void	ft_utoa_base(unsigned long n, t_fmt *f, unsigned base, char *num);
int		ft_putstr_len(const char* s, int *len);
int		print_num_prefix(long sign, t_fmt *f, int *len);
int		handle_char(char c, const t_fmt *f);
int		handle_str(char *s, const t_fmt *f);
char	*ready_uint(unsigned long n, t_fmt *f, unsigned base);
int		handle_uint(unsigned long n, t_fmt *f, unsigned base);
int		handle_int(const char *s, const t_fmt *f);
void	output_left(char *s, const t_fmt *f, int *len);
void	output_right(char *s, const t_fmt *f, int *len);

#endif