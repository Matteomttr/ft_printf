/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 08:58:02 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/03 11:19:15 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	printer(const char *format, va_list args, int i)
{
	if (format[i + 1] == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (format[i + 1] == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (format[i + 1] == 'p')
		ft_putptr_fd(va_arg(args, void *), 1);
	else if (format[i + 1] == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (format[i + 1] == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (format[i + 1] == 'u')
		ft_putunbr_fd(va_arg(args, unsigned int), 1);
	else if (format[i + 1] == 'x')
		ft_puthexa_fd(va_arg(args, unsigned int), 1, "0123456789abcdef");
	else if (format[i + 1] == 'X')
		ft_puthexa_fd(va_arg(args, unsigned int), 1, "0123456789ABCDEF");
	else
		ft_putchar_fd('%', 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_list	args_count;
	int		i;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	va_copy(args_count, args);
	i = 0;
	count = ft_countargs(format, &args_count);
	while (format[i])
	{
		if (format[i] == '%')
		{
			printer(format, args, i);
			i++;
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args_count);
	va_end(args);
	return (count);
}
