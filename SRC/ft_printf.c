/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:48:00 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/04 20:02:00 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

/* Loops through the format string and prints the corresponding argument */
static int	loop(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(*args, int), 1));
	if (c == 's')
		return (ft_putstr_fd(va_arg(*args, char *), 1));
	if (c == 'p')
		return (ft_putptr_fd(va_arg(*args, void *), 1));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(*args, int), 1));
	if (c == 'u')
		return (ft_putunbr_fd(va_arg(*args, unsigned int), 1));
	if (c == 'x')
		return (ft_puthexa_fd(va_arg(*args, unsigned int), 1, HEX_LOW));
	if (c == 'X')
		return (ft_puthexa_fd(va_arg(*args, unsigned int), 1, HEX_UP));
	if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (ft_putchar_fd('%', 1) + ft_putchar_fd(c, 1));
}

/* Prints the formatted string and returns the number of characters printed */
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += loop(format[i], &args);
		}
		else
			count += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
