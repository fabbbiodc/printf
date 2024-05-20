# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdi-cecc <fdi-cecc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 09:17:33 by fdi-cecc          #+#    #+#              #
#    Updated: 2024/05/20 16:08:11 by fdi-cecc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SOURCES
FT_PRINTF_SRCS = 		ft_printf.c \
						ft_parse.c \
						ft_tools.c \
						print/ft_printchar.c \
						print/ft_printstr.c \
						print/ft_printnum.c \
						print/ft_printuns.c \
						print/ft_printhex.c \
						print/ft_printptr.c
						
FT_PRINTF_OBJS = 		$(FT_PRINTF_SRCS:.c=.o)
FT_PRINTF_NAME = 		libftprintf.a

# LIBFT SOURCES
LIBFT_NAME = 			libft.a
LIBFT_SRCS_DIR = 		libft/srcs
LIBFT_INCLUDES_DIR = 	libft/includes
LIBFT_SRCS = 			$(shell find $(LIBFT_SRCS_DIR) -name "ft_*.c")
LIBFT_OBJS = 			$(LIBFT_SRCS:.c=.o)

# LIBRARY NAME
NAME = 					libftprintf.a

# COMPILER AND FLAGS
CC = 					cc
CFLAGS = 				-Wall -Wextra -Werror -I$(LIBFT_INCLUDES_DIR) -I.

# COMPILING
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(FT_PRINTF_OBJS) $(LIBFT_OBJS)
	ar rcs $(NAME) $(FT_PRINTF_OBJS) $(LIBFT_OBJS)

bonus: $(FT_PRINTF_OBJS) $(LIBFT_OBJS)
	ar rcs $(NAME) $(FT_PRINTF_OBJS) $(LIBFT_OBJS)

clean:
	rm -f $(FT_PRINTF_OBJS) $(LIBFT_OBJS)

fclean: clean
	rm -f $(FT_PRINTF_NAME) $(LIBFT_NAME) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus