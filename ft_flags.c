/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-cecc <fdi-cecc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 23:09:59 by fdi-cecc          #+#    #+#             */
/*   Updated: 2024/05/16 23:11:14 by fdi-cecc         ###   ########.fr       */
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
