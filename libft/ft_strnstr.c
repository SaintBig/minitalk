/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:33:28 by jleal             #+#    #+#             */
/*   Updated: 2025/06/06 16:09:08 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Locate substring in a string
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needlelen;

	if (!needle[0])
		return ((char *)haystack);
	needlelen = ft_strlen(needle);
	while (*haystack && len >= needlelen)
	{
		if (*haystack == *needle && !ft_strncmp(haystack, needle, needlelen))
		{
			return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
