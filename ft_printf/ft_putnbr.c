/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:33:54 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/01/08 12:27:49 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_putnbr(int nb, int *count)
{
	if (nb == -2147483648)
	{
		*count += ft_putstr("-2147483648");
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		*count += ft_putchar('-');
	}
	if (nb > 9)
		ft_putnbr(nb / 10, count);
	*count += ft_putchar(nb % 10 + 48);
}
