# Jem's Tests Makefile

NAME = JemsTest
SRCS = ../../ProjectFiles/fillitproject/srcs/solver.c \
../../ProjectFiles/fillitproject/srcs/map.c
OBJS = ../../ProjectFiles/fillitproject/srcs/solver.o\
../../ProjectFiles/fillitproject/srcs/map.o
HDR = ../../ProjectFiles/fillitproject/includes/fillit.h 
LIBHDR = ../../ProjectFiles/libft/libft.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)
	
$(NAME):
	gcc -o $(NAME) ./main.c $(SRCS) $(FLAGS) -I $(HDR) -I $(LIBHDR) 

clean: 
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all