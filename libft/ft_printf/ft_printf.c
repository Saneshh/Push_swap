/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:30:00 by hsolet            #+#    #+#             */
/*   Updated: 2024/02/15 08:09:19 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_conv(const char format, va_list arg)
{
	int	l;

	l = 0;
	if (format == 'c')
		l += ft_putchar(va_arg(arg, int), 1);
	else if (format == 's')
		l += ft_putstr(va_arg(arg, char *), 1);
	else if (format == 'p')
		l += ft_void_hexa(va_arg(arg, unsigned long), "0123456789abcdef", 1);
	else if (format == 'd')
		l += ft_putnbr(va_arg(arg, int), 1);
	else if (format == 'i')
		l += ft_putnbr(va_arg(arg, int), 1);
	else if (format == 'u')
		l += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789", 1);
	else if (format == 'x')
		l += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef", 1);
	else if (format == 'X')
		l += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF", 1);
	else if (format == '%')
		l += ft_putchar('%', 1);
	return (l);
}

int	check_format(char format)
{
	int		i;
	char	*str;

	i = 0;
	str = "cspdiuxX%";
	while (str[i])
	{
		if (str[i] == format)
			return (1);
		else
			i++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if ((format[i] != '%' && format))
			len += ft_putchar(format[i++], 1);
		else if (check_format(format[i + 1]) == 0 || !format[i + 1])
			return (-1);
		else if (format[i + 1] && format[i] == '%')
		{
			len += format_conv(format[i + 1], args);
			i += 2;
		}
	}
	va_end(args);
	return (len);
}
