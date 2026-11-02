/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 13:29:42 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/02 11:23:29 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_puthexa_fd(unsigned long long n, int fd, char *base)
{
	if (fd < 0)
		return ;
	if (n >= 16)
		ft_puthexa_fd(n / 16, fd, base);
	ft_putchar_fd(base[n % 16], fd);
}
