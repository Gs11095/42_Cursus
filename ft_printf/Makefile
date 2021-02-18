# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsalvo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/18 19:00:09 by gsalvo            #+#    #+#              #
#    Updated: 2021/02/18 19:00:18 by gsalvo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c \
			ft_putstuff.c \
			ft_decimal.c \
			ft_printf_utils.c \
			ft_itoa.c \
			ft_itoa_base.c \
			ft_unsigned.c \
			ft_hexadecimal.c \
			ft_address.c 

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	= 	-Wall -Wextra -Werror

RM		=	rm -f

.c.o		:
				$(CC) $(CFLAGS) -c $<

$(NAME)		:	$(OBJS)
				ar rcs $(NAME) $(OBJS)

all			:	$(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME) 

re			:	fclean all

.PHONY		:	all clean fclean re
