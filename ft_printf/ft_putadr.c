/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad <sbaghdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:27:41 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/01/08 21:28:59 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_putadr(unsigned long nbr, int *count)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (nbr >= 16)
		ft_putadr(nbr / 16, count);
	*count += ft_putchar(hexa[nbr % 16]);
}
