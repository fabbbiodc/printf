/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-cecc <fdi-cecc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:23:45 by fdi-cecc          #+#    #+#             */
/*   Updated: 2024/05/15 12:10:30 by fdi-cecc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	ft_printf("ciao ciao\n");
	ft_putchar('x');
	return (0);
}

/* run test with this:
cc -Wall -Wextra -Werror -I/home/fdi-cecc/printf/libft test.c -L/home/fdi-cecc/printf/libft -L/home/fdi-cecc/
printf -lftprintf -lft -o test

from home
cc -Wall -Wextra -Werror -Ilibft/includes -I. test.c -L. -lftprintf -o test.o
 */