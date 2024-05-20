/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-cecc <fdi-cecc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:34:18 by fdi-cecc          #+#    #+#             */
/*   Updated: 2024/05/20 12:28:33 by fdi-cecc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_minus(long *n, int *len, t_flags flag)
{
	ft_putchar('-');
	(*n) = (*n) * -1;
	(*len)--;
	if (flag.dot)
		(*len)--;
	return (1);
}

static int	ft_diglen(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
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
	if (n < 0 && flag->zerofill > len && flag->precision > len)
		(*preclen)++;
	if (n < 0 && flag->dot && flag->precision < flag->zerofill)
		len++;
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

static int	ft_printdec(int len, long n, t_flags flag)
{
	int	i;

	i = 0;
	if (n == 0 && flag.width && flag.width < len)
		i += ft_putcharlen(' ');
	else if (n == 0 && flag.dot && !flag.precision && flag.width >= len)
		i += ft_putcharlen(' ');
	else if (!(n == 0 && flag.dot && !flag.precision))
		i += ft_putnbrlen(n);
	return (i);
}

int	ft_printnum(long n, t_flags flag)
{
	int		i;
	int		len;
	char	pref;
	int		preclen;

	i = 0;
	len = ft_runflags(&pref, &preclen, &flag, n);
	while (pref == ' ' && preclen + i < flag.width)
		i += ft_putcharlen(' ');
	if (n < 0)
		i += ft_minus(&n, &len, flag);
	else if (flag.space && n >= 0 && !flag.plus && !flag.dot)
		i += ft_putcharlen(' ');
	else if (flag.plus && n >= 0 && !flag.dot)
		i += ft_putcharlen('+');
	while (len + i < flag.width)
		i += ft_putcharlen('0');
	i += ft_printdec(len, n, flag);
	while (i < flag.left)
		i += ft_putcharlen(' ');
	return (i);
}
