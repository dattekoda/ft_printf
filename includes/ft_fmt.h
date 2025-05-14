/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-12 08:53:17 by khanadat          #+#    #+#             */
/*   Updated: 2025-05-12 08:53:17 by khanadat         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FMT_H
# define FT_FMT_H

# include <stddef.h>
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

# define FLAG_ZERO	0x01 //ビットマスクでフラグ設定
# define FLAG_MINUS	0x02
# define FLAG_PLUS	0x04
# define FLAG_SPACE	0x08
# define FLAG_HASH	0x10
# define FLAG_DOT	0x20

typedef struct s_fmt //フォーマット解析用構造体
{
	uint8_t 	flags;
	int			width;
	int			prec;
	char		spec;
}	t_fmt;

void	f_init(t_fmt *fmt);
void	f_parse_flags(const char *fmt, unsigned int *i, t_fmt *f);
void	f_parse_width_prec(const char *fmt, unsigned int *i, t_fmt *f);
int		dispatch(const t_fmt *fmt, va_list *ap);
 
#endif