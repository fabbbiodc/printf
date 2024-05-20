/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-cecc <fdi-cecc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:10:26 by fdi-cecc          #+#    #+#             */
/*   Updated: 2024/05/20 12:27:58 by fdi-cecc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunslen(unsigned long n)
{
	int				i;
	unsigned long	nbr;

	i = 0;
	nbr = n;
	if (nbr >= 10)
		i += ft_putunslen(nbr / 10);
	i += ft_putcharlen((nbr % 10) + '0');
	return (i);
}

static int	ft_diglen(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_runflags(char *pref,	int *preclen, t_flags *flag, long n)
{
	int	len;

	len = ft_diglen(n);
	*preclen = len;
	if (flag->precision > len)
		*preclen = flag->precision;
	*pref = '0';
	if (flag->zero && flag->dot && flag->zerofill > flag->precision)
		*pref = ' ';
	if (!flag->zero)
		*pref = ' ';
	if (flag->zero)
		flag->width = flag->zerofill;
	if (flag->precision > flag->width)
		flag->width = flag->precision;
	return (len);
}

static int	ft_printudec(int len, long n, t_flags flag)
{
	int	i;

	i = 0;
	if (n == 0 && flag.width && flag.width < len)
		i += ft_putcharlen(' ');
	else if (n == 0 && flag.dot && !flag.precision && flag.width >= len)
		i += ft_putcharlen(' ');
	else if (!(n == 0 && flag.dot && !flag.precision))
		i += ft_putunslen(n);
	return (i);
}

int	ft_printuns(unsigned long n, t_flags flag)
{
	int		i;
	int		len;
	char	pref;
	int		preclen;

	i = 0;
	len = ft_runflags(&pref, &preclen, &flag, n);
	while (preclen + i < flag.width)
		i += ft_putcharlen(pref);
	while (len + i < flag.width)
		i += ft_putcharlen('0');
	i += ft_printudec(len, n, flag);
	while (i < flag.left)
		i += ft_putcharlen(' ');
	return (i);
}
