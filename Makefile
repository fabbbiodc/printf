# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdi-cecc <fdi-cecc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 09:17:33 by fdi-cecc          #+#    #+#              #
#    Updated: 2024/05/08 11:50:03 by fdi-cecc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS 		= 	ft_printf.c

OBJS		=	$(SRCS:.c=.o)

CC			=	cc

CFLAGS		= 	-Wall -Wextra -Werror -Ilibft/includes

LIBFT_DIR	= 	libft

LIBFT		= $(LIBFT_DIR)/libft.a

all:		$(LIBFT) $(NAME)

$(NAME):	$(OBJS) $(LIBFT)
				ar rcs $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean:		clean
				rm -f $(NAME)
				$(MAKE) fclean -C $(LIBFT_DIR)

re:			fclean all

.PHONY:		all clean fclean re