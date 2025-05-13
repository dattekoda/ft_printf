/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comv_tbl.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-11 22:27:58 by khanadat          #+#    #+#             */
/*   Updated: 2025-05-11 22:27:58 by khanadat         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMV_TBL_H
# define FT_COMV_TBL_H

# include "ft_fmt.h"
# include <stdarg.h>

/*
 * Conversion function prototype:
 *  - fmt: 解析済みフォーマット情報
 *  - ap:  可変引数リスト
 *  - buf: 出力バッファ
 * 戻り値: 書き込んだ文字数またはエラーコード
 */
typedef int	(*t_conv_fn)(t_fmt *, va_list *ap);
/*
 * グローバル変換テーブル:
 * 変換指定子ごとに対応する関数へのポインタを並べた配列。
 * インデックスは t_specifier の値に対応。
 */
extern const t_conv_fn g_conv_tbl[];

#endif