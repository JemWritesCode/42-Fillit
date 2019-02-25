# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcope <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/04 20:53:06 by jcope             #+#    #+#              #
#    Updated: 2019/02/24 21:36:42 by cschulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillitTEST
SRCS =	./valid.c\
		./validitychecker_test.c
OBJS =  ./*.o
HDR = ../../ProjectFiles/fillitproject/includes/fillit.h 
LIBHDR = ../../ProjectFiles/libft/libft.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)
	
$(NAME):
	gcc -o $(NAME) $(SRCS) $(FLAGS) -I $(HDR) -I $(LIBHDR) 

clean: 
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

lldb: 
	gcc -g $(SRCS) $(FLAGS) -I $(HDR) -I $(LIBHDR) -o fillitDEBUG
