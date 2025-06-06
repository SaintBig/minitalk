/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:46:45 by jleal             #+#    #+#             */
/*   Updated: 2025/06/06 16:05:16 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (c);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	tot;
	int	p;
	int	i;

	tot = 0;
	p = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		p = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		tot = (tot * 10) + str[i] - '0';
		i++;
	}
	return (tot * p);
}
