/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-cecc <fdi-cecc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:48:05 by fdi-cecc          #+#    #+#             */
/*   Updated: 2024/05/16 23:14:51 by fdi-cecc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_processflags(t_flags *flag, const char *str, int *i)
{
	if (str[1] == '#')
		flag->hash = 1;
	else if (str[1] == ' ')
		flag->space = 1;
	else if (str[1] == '+')
		flag->plus = 1;
	else if (str[1] == '0')
	{
		flag->zerofill = ft_atoiptr(str + 2, i);
		flag->zero = 0;
	}
	else if (str[1] == '-')
	{
		flag->left = ft_atoiptr(str + 2, i);
		flag->minus = 1;
	}
	else if (str[1] == '.')
	{
		flag->precision = ft_atoiptr(str + 2, i);
		flag->minus = 1;
	}
}

int	ft_processfmt(const char *str, va_list *args, t_flags flag)
{
	int	len;

	len = 0;
	if (str[1] == 'c')
		len += ft_printchar(va_arg (*args, int), flag);
	else if (str[1] == 's')
		len += ft_printstr(va_arg (*args char *), flag);
	else if (str[1] == 'p')
		len += ft_printptr(va_arg(*args, void *), flag);
	else if (str[1] == 'd' || str[1] == 'i')
		len += ft_printnum(va_arg(*args, int), flag);
	else if (str[1] == 'u')
		len += ft_printuns(va_arg(*args, unsigned int), flag);
	else if (str[1] == 'x')
		len += ft_printhex(va_arg(*args, int), 0, flag);
	else if (str[1] == 'X')
		len += ft_printhex(va_arg(*args, int), 1, flag);
	else if (str[1] == '%')
	{
		ft_putchar('%');
		len++;
	}
	return (len);
}

int	ft_parse(const char *str, va_list *args, int *i)
{
	int		len;
	t_flags	flag;

	len = 0;
	ft_initflags(&flag);
	while (ft_checkflags(str[*i + 1], "01234567890# +-."))
	{
		if (ft_checkflags(str[*i + 1], "# +0-."))
			ft_processflags(&flag, str + (*i), i);
		else
		{
			flag.width = ft_atoiptr(str + (*i) + 1, i);
			(*i)--;
		}
		(*i)++;
	}
	len += ft_processfmt(str + (*i), args, flag);
	(*i)++;
	return (len);
}
