# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcope <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/04 20:53:06 by jcope             #+#    #+#              #
#    Updated: 2019/02/04 20:53:08 by jcope            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = ./*.c
OBJS = ./*.o
HDR = ./fillit.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)
	
$(NAME):
	gcc $(SRCS) $(FLAGS) -I $(HDR)

clean: 
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all