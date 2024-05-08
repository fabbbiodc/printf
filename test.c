/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-cecc <fdi-cecc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:23:45 by fdi-cecc          #+#    #+#             */
/*   Updated: 2024/05/08 12:14:48 by fdi-cecc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	ft_printf("ciao ciao");
	return (0);
}

/* run test with this:
cc -Wall -Wextra -Werror -I/home/fdi-cecc/printf/libft test.c -L/home/fdi-cecc/printf/libft -L/home/fdi-cecc/
printf -lftprintf -lft -o test */