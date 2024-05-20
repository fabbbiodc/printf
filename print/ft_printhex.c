/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-cecc <fdi-cecc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:35:59 by fdi-cecc          #+#    #+#             */
/*   Updated: 2024/05/20 15:26:30 by fdi-cecc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printbase(int n, char *base)
{
	unsigned int	baselen;
	unsigned int	nbr;
	int				i;

	i = 0;
	nbr = n;
	baselen = ft_strlen(base);
	if (nbr >= baselen)
	{
		i += ft_printbase(nbr / baselen, base);
		i += ft_printbase(nbr % baselen, base);
	}
	else
		i += ft_putcharlen(base[nbr]);
	return (i);
}

static int	ft_hexlen(int n)
{
	int				i;
	unsigned int	nbr;

	i = 0;
	nbr = n;
	if (nbr >= 16)
	{
		i += ft_hexlen(nbr / 16);
		i += ft_hexlen(nbr % 16);
	}
	else
		i++;
	return (i);
}

static int	ft_runflags(char *pref,	int *preclen, t_flags *flag, int n)
{
	int	len;

	len = ft_hexlen(n);
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

static int	ft_printx(int upcase, int len, int n, t_flags flag)
{
	int	i;

	i = 0;
	if (n == 0 && flag.width && flag.width < len)
		i += ft_putcharlen(' ');
	else if (n == 0 && flag.dot && !flag.precision && flag.width >= len)
		i += ft_putcharlen(' ');
	else if (!(n == 0 && flag.dot && !flag.precision))
	{
		if (upcase)
			i += ft_printbase(n, "0123456789ABCDEF");
		else
			i += ft_printbase(n, "0123456789abcdef");
	}
	return (i);
}

int	ft_printhex(int n, int upcase, t_flags flag)
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
	if (flag.hash && n != 0)
	{
		if (upcase)
			i += ft_printstrlen("0X");
		else
			i += ft_printstrlen("0x");
	}
	i += ft_printx(upcase, len, n, flag);
	while (i < flag.left)
		i += ft_putcharlen(' ');
	return (i);
}
