/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:15:26 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/01/13 12:14:53 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdarg.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

int		ft_atoi(char *s);
char	*ft_strchr(const char *s, int c);
//printf
int		ft_printf(const char *format, ...);
void	ft_putnbrbase(long long nbr, char *base, int *count);
int		ft_putstr(char *str);
int		ft_putchar(char c);
size_t	ft_strlen(const char *str);
void	ft_putnbrbaseunsigned(unsigned int nbr, char *base, int	*count);
void	ft_putnbr(int nb, int *count);
void	ft_putadr(unsigned long nbr, int *count);

#endif