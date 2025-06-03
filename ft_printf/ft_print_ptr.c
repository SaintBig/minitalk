/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:04:18 by jleal             #+#    #+#             */
/*   Updated: 2025/04/26 18:38:05 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_ulong(size_t nb)
{
	char	*base;
	char	output;
	int		tot;

	tot = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
		tot += print_ulong(nb / 16);
	output = base[nb % 16];
	tot += ft_printchar(output);
	return (tot);
}

int	print_ptr(void *ptr)
{
	int	tot;

	tot = 0;
	if (!ptr)
		return (tot += ft_printstr("(nil)"));
	tot += ft_printstr("0x");
	tot += print_ulong((size_t) ptr);
	return (tot);
}
