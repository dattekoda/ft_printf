#include "libft.h"

size_t ft_strlen(const char *s)
{
	const char *h;

	if (!s)
		return (0);
	h = s;
	while (*s)
		s++;
	return ((size_t)(s - h));
}

char	*ft_strdup(const char *s)
{
	char		*dup;
	size_t		slen;

	slen = ft_strlen(s);
	dup = malloc(slen + 1);
	if (!dup)
		return (NULL);
	dup[slen] = '\0';
	while (slen--)
		dup[slen] = s[slen];
	return (dup);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	slen;

	if (!dst || !src)
		return (0);
	slen = -1;
	while (src[++slen] && size-- > 1)
		dst[slen] = src[slen];
	dst[slen] = '\0';
	while (src[slen])
		slen++;
	return (slen);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = malloc(len1 + len2 + 1);
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, len1 + 1);
	ft_strlcpy(join + len1, s2, len2 + 1);
	return (join);
}

