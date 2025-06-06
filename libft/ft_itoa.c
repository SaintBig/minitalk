/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:12:37 by jordanschil       #+#    #+#             */
/*   Updated: 2025/06/06 16:06:38 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intl(int n)
{
	int	i;

	if (n == -2147483648)
		return (11);
	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*handle_intmin(char *str)
{
	ft_memcpy(str, &"-2147483648", 11);
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		i;

	len = ft_intl(n);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!(str))
		return (NULL);
	if (n == -2147483648)
		return (handle_intmin(str));
	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		i++;
	}
	while (len > i)
	{
		str[(len--) - 1] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
