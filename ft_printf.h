/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 08:58:02 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/02 13:07:14 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

/* Fonctions de conversion et d'affichage (Utilitaires) */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_puthexa_fd(unsigned long long n, int fd, char *base);
void	ft_putptr_fd(void *ptr, int fd);
int		ft_countargs(const char *format, va_list args);

/* Fonction principale */
int		ft_printf(const char *format, ...);

#endif
