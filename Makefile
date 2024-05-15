# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdi-cecc <fdi-cecc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 09:17:33 by fdi-cecc          #+#    #+#              #
#    Updated: 2024/05/15 12:11:46 by fdi-cecc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SOURCES
FT_PRINTF_SRCS = ft_printf.c
FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:.c=.o)
FT_PRINTF_NAME = libftprintf.a

# LIBFT SOURCES
LIBFT_NAME = libft.a
LIBFT_SRCS_DIR = libft/srcs
LIBFT_INCLUDES_DIR = libft/includes
LIBFT_SRCS = $(shell find $(LIBFT_SRCS_DIR) -name "ft_*.c")
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

# LIBRARY NAME
NAME = libftprintf.a

# COMPILER AND FLAGS
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_INCLUDES_DIR) -I.

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






# SRCS		= ft_printf.c
# OBJS		= ${SRCS:.c=.o}
# NAME		= libftprintf.a
# CC			= gcc -Wall -Wextra -Werror

# %.o: %.c ft_printf.h
# 			${CC} -I. -c $< -o ${<:.c=.o}

# all:		${NAME}

# $(NAME):	${OBJS} ft_printf.h
# 			ar rcs ${NAME} ${OBJS}

# bonus:		${OBJS} ft_printf.h
# 			ar rcs ${NAME} ${OBJS}

# clean:
# 			rm -f ${OBJS}

# fclean:		clean
# 			rm -f ${NAME}

# re:			fclean all

# .PHONY:		all clean fclean re