/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-25 10:50:39 by khanadat          #+#    #+#             */
/*   Updated: 2025-04-25 10:50:39 by khanadat         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t maxlen)
{
	const char	*h;

	h = s;
	while (maxlen && *s)
	{
		maxlen--;
		s++;
	}
	return (s - h);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strnlen(dst, size);
	src_len = ft_strlen(src);
	dst += dst_len;
	size -= dst_len;
	while (1 < size && *src)
		*dst++ = (size--, *src++);
	if (size)
		*dst = 0;
	return (dst_len + src_len);
}

// #include <bsd/string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char dst[] = "012345678\0";
// 	char src[] = "abcdefghijk";

// 	dst[sizeof(dst) - 1] = 'a';
// 	size_t r_value = ft_strlcat(dst, src, sizeof(dst));
// 	printf("r_value:%zu\n", r_value);
// 	printf("%s\n", dst);
// 	return (0);
// }