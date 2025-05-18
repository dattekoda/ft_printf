/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:27:58 by khanadat          #+#    #+#             */
/*   Updated: 2025/05/18 12:16:47 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HANDLE_H
# define FT_HANDLE_H

# include <stdlib.h>
# include "ft_fmt.h"

int		count_digit_p(uintptr_t n, unsigned int base);
int		count_digit_u(unsigned int n, unsigned int base);
int		count_digit(long n, unsigned int base);
void	count_flen_u(unsigned long n, t_fmt *f, unsigned int base);
void	count_flen(long n, t_fmt *f);
void	ft_putnchar(char c, int n, int *len);
void	ft_utoa_base(unsigned long n, t_fmt *f, unsigned int base, char *num);
void	ft_sitoa(long n, t_fmt *f, char *num);
int		ft_putstr_len(const char *s, int *len);
int		handle_char(char c, const t_fmt *f);
int		handle_str(char *s, const t_fmt *f);
int		handle_null(const t_fmt *f);
char	*ready_uint(unsigned long n, t_fmt *f, unsigned int base);
char	*ready_sint(long n, t_fmt *f);
int		handle_uint(unsigned long n, t_fmt *f, unsigned int base);
int		handle_sint(long n, t_fmt *f);
void	output_left(char *s, const t_fmt *f, int *len);
void	output_right(char *s, const t_fmt *f, int *len);

#endif