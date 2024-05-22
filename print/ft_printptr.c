/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-cecc <fdi-cecc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:36:32 by fdi-cecc          #+#    #+#             */
/*   Updated: 2024/05/20 19:02:28 by fdi-cecc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printaddr(long unsigned address)
{
	char			c;
	int				i;
	const char		*base;

	base = "0123456789abcdef";
	i = 0;
	if (address >= 16)
	{
		i += ft_printaddr(address / 16);
		i += ft_printaddr(address % 16);
	}
	else
	{
		c = base[address % 16];
		i += ft_putcharlen(c);
	}
	return (i);
}

static int	ft_hexlen(long unsigned n)
{
	int				i;

	i = 0;
	if (n >= 16)
	{
		i += ft_hexlen(n / 16);
		i += ft_hexlen(n % 16);
	}
	else
		i++;
	return (i);
}

int	ft_printptr(void *ptr, t_flags flag)
{
	long	address;
	int		i;
	int		len;

	i = 0;
	address = (long unsigned)ptr;
	len = ft_hexlen((address) + 2);
	if (ptr == 0)
	{
		return (ft_printstrlen("(nil)"));
	}
	while (len + i < flag.width)
		i += ft_putcharlen(' ');
	i += ft_printstrlen("0x");
	i += ft_printaddr(address);
	while (i < flag.left)
		i += ft_putcharlen(' ');
	return (i);
}
