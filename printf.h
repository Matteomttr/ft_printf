/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prinft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter@student.42angouleme.fr            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 13:57:56 by mamatter          #+#    #+#             */
/*   Updated: 2026/10/31 13:58:26 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>

/* Fonctions de conversion et d'affichage (Utilitaires) */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_puthexa_fd(unsigned int n, int fd, char *base);
int		ft_tolower(int c);
int		ft_toupper(int c);

/* Fonction principale */
int		ft_printf(const char *format, ...);

#endif
