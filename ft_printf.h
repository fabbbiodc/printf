/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-cecc <fdi-cecc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:36:33 by fdi-cecc          #+#    #+#             */
/*   Updated: 2024/05/20 16:13:26 by fdi-cecc         ###   ########.fr       */
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

int		ft_printf(const char *fmt, ...);

int		ft_parse(const char *str, va_list *args, int *i);
int		ft_processfmt(const char *str, va_list *args, t_flags flag);
void	ft_processflags(t_flags *flag, const char *str, int *i);

int		ft_printchar(char c, t_flags flag);

int		ft_printstr(const char *str, t_flags flag);
int		ft_printstrlen(const char *str);

int		ft_atoiptr(const char *str, int *adv);
void	ft_initflags(t_flags *flag);
int		ft_checkflags(char c, char *str);
int		ft_putcharlen(char c);

int		ft_printnum(long n, t_flags flag);
int		ft_putnbrlen(long n);

int		ft_printuns(unsigned long n, t_flags flag);

int		ft_printhex(int n, int upcase, t_flags flag);

int		ft_printptr(void *ptr, t_flags flag);

#endif