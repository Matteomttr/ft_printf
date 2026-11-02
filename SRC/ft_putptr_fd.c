/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 09:21:59 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/02 11:23:37 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putptr_fd(void *ptr, int fd)
{
	if (fd < 0)
		return ;
	write(fd, "0x", 2);
	ft_puthexa_fd((unsigned long long)(ptr), 1, "0123456789abcdef");
}
