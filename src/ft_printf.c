/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:48:00 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/07 18:22:53 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

/* Loops through the format string and prints the corresponding argument */
static int	loop(char c, va_list *args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_fd(va_arg(*args, int), 1);
	else if (c == 's')
		count += ft_putstr_fd(va_arg(*args, char *), 1);
	else if (c == 'p')
		count += ft_putptr_fd(va_arg(*args, void *), 1);
	else if (c == 'd' || c == 'i')
		count += ft_putnbr_fd(va_arg(*args, int), 1);
	else if (c == 'u')
		count += ft_putunbr_fd(va_arg(*args, unsigned int), 1);
	else if (c == 'x')
		count += ft_puthexa_fd(va_arg(*args, unsigned int), 1, HEX_LOW);
	else if (c == 'X')
		count += ft_puthexa_fd(va_arg(*args, unsigned int), 1, HEX_UP);
	else if (c == '%')
		count += ft_putchar_fd('%', 1);
	else
		count += ft_putchar_fd('%', 1) + ft_putchar_fd(c, 1);
	return (count);
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
