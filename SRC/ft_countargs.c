/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countargs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:00:31 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/02 19:20:25 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_nbrlen(int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
		len++;
	if (nb == 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		i += 6;
		return (i);
	}
	while (s[i])
		i++;
	return (i);
}

static int	counter(const char *format, va_list args, int i)
{
	int	count;

	count = 0;
	if (format[i + 1] == 'c')
		count ++;
	else if (format[i + 1] == 's')
		count += ft_strlen(va_arg(args, char *));
	else if (format[i + 1] == 'p')
		count += va_arg(args, void *);
	else if (format[i + 1] == 'd')
		count += ft_nbrlen(va_arg(args, int));
	else if (format[i + 1] == 'i')
		count += ft_nbrlen(va_arg(args, int));
	else if (format[i + 1] == 'u')
		count += ft_nbrlen(va_arg(args, unsigned int));
	else if (format[i + 1] == 'x')
		count += ft_nbrlen(va_arg(args, unsigned int));
	else if (format[i + 1] == 'X')
		count += ft_nbrlen(va_arg(args, unsigned int));
	else
		count++;
	return (count);
}

int	ft_countargs(const char *format, va_list args)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += counter(format, args, i);
			i++;
		}
		else
			count++;
		i++;
	}
	return (count);
}
