/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbaseunsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:13:34 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/01/08 12:27:55 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_putnbrbaseunsigned(unsigned int nbr, char *base, int	*count)
{
	size_t	len;

	len = ft_strlen(base);
	if (nbr < 0)
	{
		*count += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= len)
	{
		ft_putnbrbaseunsigned(nbr / len, base, count);
	}
	*count += ft_putchar(base[nbr % len]);
}
