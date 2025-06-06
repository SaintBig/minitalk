/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:50:21 by jleal             #+#    #+#             */
/*   Updated: 2025/06/06 16:04:56 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	write(1, str, ft_strlen_new(str));
	return (ft_strlen_new(str));
}

static int	ft_findf(va_list args, const char format)
{
	if (format == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (format == 'c')
		return (ft_printchar((va_arg(args, int))));
	else if (format == 'd')
		return (ft_putnbr_base((va_arg(args, int)), "0123456789"));
	else if (format == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789"));
	else if (format == 'i')
		return (ft_putnbr_base(va_arg(args, int), "0123456789"));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (format == 'p')
		return (print_ptr(va_arg(args, void *)));
	else if (format == '%')
		return (ft_printchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			tot;

	if (!format || (*format == '%' && *(format + 1) == '\0'))
		return (-1);
	va_start(args, format);
	i = 0;
	tot = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			tot += ft_findf(args, format[i + 1]);
			i++;
		}
		else
			tot += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (tot);
}
