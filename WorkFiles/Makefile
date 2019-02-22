# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcope <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/04 20:53:06 by jcope             #+#    #+#              #
#    Updated: 2019/02/21 20:18:52 by cschulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillitTEST
SRCS = ../ProjectFiles/fillitproject/srcs/parser.c\
		./parsertest.c\
		./pieceprinter.c\
		../ProjectFiles/fillitproject/srcs/valid.c\
		../ProjectFiles/fillitproject/srcs/shifters.c
#		../ProjectFiles/libft/*.c 
OBJS = ../ProjectFiles/fillitproject/srcs/*.o\
	   ../ProjectFiles/libft/*.o\
	   ./*.o
HDR = ../ProjectFiles/fillitproject/includes/fillit.h 
LIBHDR = ../ProjectFiles/libft/libft.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)
	
$(NAME):
	gcc -o $(NAME) $(SRCS) $(FLAGS) -I $(HDR) -I $(LIBHDR) 

clean: 
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
