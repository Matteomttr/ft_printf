/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter@student.42angouleme.fr            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 10:21:48 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/01 10:21:53 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void	loop(const char *format, va_list args, int i)
{
	if (format[i + 1] == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (format[i + 1] == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (format[i + 1] == 'p')
		return ;
	else if (format[i + 1] == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (format[i + 1] == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (format[i + 1] == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
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
	int		i;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			loop(format, args, i);
			i++;
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}

#include <stdio.h>

int	main()
{
	char			c = 'c';
	char			*str = "Matteo";
	int				d = 17;
	int				i = 18;
	unsigned int	ui = 16;
	char			hexaL = 'Z';
	char			hexaU = 'Z';
	void			*p = "c le pointeur";

	ft_printf("coucou %c moi je m'apelle %s j'ai %d bientot %i ma copine a %u \n lower hexa de c : %x et upper hexa de a : %X \n c juste a 100%z \n  %p et %c \n", c, str, d, i, ui, hexaL, hexaU, p);
	printf("coucou %c moi je m'apelle %s j'ai %d bientot %i ma copine a %u \n lower hexa de c : %x et upper hexa de a : %X \n c juste a 100%% \n %p\n", c, str, d, i, ui, hexaL, hexaU, p);
}
