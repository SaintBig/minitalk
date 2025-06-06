/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:25:56 by jleal             #+#    #+#             */
/*   Updated: 2025/06/06 16:09:17 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_cmp(const char c, const char *set)
{
	if (!set)
		return (0);
	while (*set)
	{
		if (c == *set)
			return (*set);
		set++;
	}
	return (0);
}

static char	*make_trim(const char *s, size_t start, size_t len)
{
	char	*new;

	if (!s || len <= 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
	new = (char *)ft_calloc(len + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_memcpy(new, &s[start], len);
	return (new);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	len;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	if (len == 0)
		return (ft_strdup(""));
	j = len - 1;
	while (set_cmp(s1[i], set))
		i++;
	while (j >= 0 && set_cmp(s1[j], set))
		j--;
	return (make_trim(s1, i, j - (i - 1)));
}
