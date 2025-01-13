/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad <sbaghdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:27:36 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/01/08 21:28:55 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static int	is_var(char c)
{
	char	*s;

	s = "csdxXuip%";
	if (c == 0)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

static	void	print_format(char c, int *count, va_list args)
{
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (c == 'c')
		*count += ft_putchar(va_arg(args, int));
	else if (c == 'x')
		ft_putnbrbase(va_arg(args, unsigned int), "0123456789abcdef", count);
	else if (c == 'X')
		ft_putnbrbase(va_arg(args, unsigned int), "0123456789ABCDEF", count);
	else if (c == 's')
		*count += ft_putstr(va_arg(args, char *));
	else if (c == 'u')
		ft_putnbrbaseunsigned(va_arg(args, unsigned int), "0123456789", count);
	else if (c == 'p')
	{
		*count += ft_putstr("0x");
		ft_putadr(va_arg(args, unsigned long), count);
	}
	else
		*count += ft_putchar(c);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	args;

	va_start(args, format);
	(1) && (i = 0, count = 0);
	if (write(1, "", 0) == -1)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && is_var(format[i + 1]) && format[i + 1])
		{
			print_format(format[++i], &count, args);
			i++;
		}
		else if (format[i] == '%' && !is_var(format[i + 1]))
			i++;
		else
		{
			count += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
