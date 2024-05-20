/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-cecc <fdi-cecc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:34:43 by fdi-cecc          #+#    #+#             */
/*   Updated: 2024/05/19 18:00:55 by fdi-cecc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	ft_printf("Test %20s\n", "string");
	printf("Test %20s\n", "string");
	printf("\n");
	// Test 1: Right-justified with Minimum Width
    ft_printf("Test %20d\n", 123);
    printf("Test %20d\n", 123);
	printf("\n");
    // Test 2: Left-justified with Minimum Width
    ft_printf("Test %-20d\n", 123);
    printf("Test %-20d\n", 123);
	printf("\n");
    // Test 3: Zero-padded with Minimum Width
    ft_printf("Test %020d\n", 123);
    printf("Test %020d\n", 123);
	printf("\n");
    // Test 4: Precision Specified
    ft_printf("Test %.5d\n", 123);
    printf("Test %.5d\n", 123);
	printf("\n");
    // Test 5: Minimum Width and Precision Specified
    ft_printf("Test %10.5d\n", 123);
    printf("Test %10.5d\n", 123);
	printf("\n");
    // Test 6: Plus Sign for Positive Numbers
    ft_printf("Test %+d\n", 123);
    printf("Test %+d\n", 123);
	printf("\n");
    // Test 7: Space for Positive Numbers
    ft_printf("Test % d\n", 123);
    printf("Test % d\n", 123);
	printf("\n");
	return (0);
}
// cc -Wall -Wextra -Werror -Ilibft/includes -I. test.c -L. -lftprintf -o test.o
