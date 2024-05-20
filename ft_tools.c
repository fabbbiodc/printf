/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-cecc <fdi-cecc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 23:09:59 by fdi-cecc          #+#    #+#             */
/*   Updated: 2024/05/20 12:30:32 by fdi-cecc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkflags(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_putnbrlen(long n)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = n;
	if (n < 0)
	{
		i += ft_putcharlen('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		i += ft_putnbrlen(nbr / 10);
	i += ft_putcharlen((nbr % 10) + '0');
	return (i);
}

void	ft_initflags(t_flags *flag)
{
	flag->hash = 0;
	flag->space = 0;
	flag->dot = 0;
	flag->plus = 0;
	flag->zero = 0;
	flag->minus = 0;
	flag->left = 0;
	flag->width = 0;
	flag->zerofill = 0;
	flag->precision = 0;
}

int	ft_atoiptr(const char *str, int *adv)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
		(*adv)++;
	}
	return (result);
}

int	ft_putcharlen(char c)
{
	write(1, &c, 1);
	return (1);
}
