/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-cecc <fdi-cecc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:11:35 by fdi-cecc          #+#    #+#             */
/*   Updated: 2024/05/19 17:33:50 by fdi-cecc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstrlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i += ft_putcharlen(str[i]);
	return (i);
}

static int	ft_printprecision(const char *str, int precision)
{
	int	i;

	if (precision == -1)
		return (ft_printstrlen(str));
	i = 0;
	while (str[i] && i < precision)
		i += ft_putcharlen(str[i]);
	return (i);
}

int	ft_printstr(const char *str, t_flags flag)
{
	int	i;
	int	len;

	i = 0;
	if (!str)
		len = 6;
	else
		len = ft_strlen(str);
	while (len + i < flag.width)
		i += ft_putcharlen(' ');
	if (!flag.dot)
		flag.precision = -1;
	if (!str)
		i += ft_printprecision("(null)", flag.precision);
	else
		i += ft_printprecision(str, flag.precision);
	while (i < flag.left)
		i += ft_putcharlen(' ');
	return (i);
}
