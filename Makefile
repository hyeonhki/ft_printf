# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/15 13:38:25 by hyeonhki          #+#    #+#              #
#    Updated: 2021/02/15 13:38:27 by hyeonhki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft
LIBFT_LIB = libft.a

SRCS = ./ft_printf.c ./utils.c\
		./info.c ./pt_char.c ./pt_nbr.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	ar rcs $@ $(OBJS)
#libft를 안에서 make한 후, libft.a를 복사 시키는 듯

clean :
	rm -f $(OBJS) $(OBJS_BON)

fclean : clean
	rm -f $(NAME)

re : fclean all