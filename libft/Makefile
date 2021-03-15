# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonhki <hyeonhki@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/24 16:30:24 by hyeonhki          #+#    #+#              #
#    Updated: 2021/01/08 23:16:19 by hyeonhki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_memset.c\
	   ft_bzero.c\
	   ft_memcpy.c\
	   ft_memccpy.c\
	   ft_memmove.c\
	   ft_memchr.c\
	   ft_memcmp.c\
	   ft_strlen.c\
	   ft_strlcpy.c\
	   ft_strnlen.c\
	   ft_strlcat.c\
	   ft_strchr.c\
	   ft_strrchr.c\
	   ft_strnstr.c\
	   ft_strncmp.c\
	   ft_atoi.c\
	   ft_isalpha.c\
	   ft_isdigit.c\
	   ft_isalnum.c\
	   ft_isascii.c\
	   ft_isprint.c\
	   ft_toupper.c\
	   ft_tolower.c\
	   ft_calloc.c\
	   ft_strdup.c\
	   ft_strnlen.c\
	   ft_strjoin.c\
	   ft_strcpy.c\
	   ft_substr.c\
	   ft_strtrim.c\
	   ft_split.c\
	   ft_itoa.c\
	   ft_strmapi.c\
	   ft_putchar_fd.c\
	   ft_putchar.c\
	   ft_putstr_fd.c\
	   ft_putendl_fd.c\
	   ft_putnbr_fd.c\
	   ft_numlen.c\
	   ft_strcat.c\
	   ft_isspace.c\
	   ft_islower.c\
	   ft_isupper.c\
	   ft_putnbr_base.c

SRCS_BON = ft_lstnew.c\
		   ft_lstadd_front.c\
		   ft_lstsize.c\
		   ft_lstlast.c\
		   ft_lstadd_back.c\
		   ft_lstdelone.c\
		   ft_lstclear.c\
		   ft_lstiter.c\
		   ft_lstmap.c

OBJS = $(SRCS:.c=.o)
OBJS_BON = $(SRCS_BON:.c=.o)
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

 %.o : %.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

clean :
	rm -f $(OBJS) $(OBJS_BON)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : $(OBJS_BON)
	ar rcs $(NAME) $(OBJS_BON) 

.PHONY: all clean fclean re
