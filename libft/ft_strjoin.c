/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:25:45 by jleal             #+#    #+#             */
/*   Updated: 2025/06/06 16:08:45 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*str;
	unsigned int	l1;
	unsigned int	l2;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = (char *)ft_calloc(l1 + l2 + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, (const void *)s1, l1);
	ft_memcpy(str + l1, (const void *)s2, l2);
	return (str);
}
