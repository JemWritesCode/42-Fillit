# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcope <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/11 17:53:05 by jcope             #+#    #+#              #
#    Updated: 2018/09/11 17:55:32 by jcope            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ./*.c
OBJS = ./*.o
HDR = ./libft.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)
	
$(NAME):
	gcc $(SRCS) $(FLAGS) -I $(HDR) -c 
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean: 
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
