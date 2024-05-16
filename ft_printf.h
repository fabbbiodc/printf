/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-cecc <fdi-cecc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:36:33 by fdi-cecc          #+#    #+#             */
/*   Updated: 2024/05/16 18:39:24 by fdi-cecc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include "./libft/includes/libft.h"

typedef struct s_flags
{
	int	hash;
	int	space;
	int	dot;
	int	plus;
	int	zero;
	int	minus;
	int	left;
	int	zerofill;
	int	precision;
	int	width;
}	t_flags;

int	ft_printf(const char *fmt, ...);
int	ft_parse(const char *str, va_list *args, int *i);

#endif