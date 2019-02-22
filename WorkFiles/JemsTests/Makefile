# Jem's Tests Makefile

NAME = JemsTest
SRCS = ../../ProjectFiles/libft/*.c \
../../ProjectFiles/fillitproject/srcs/solver.c \
../../ProjectFiles/fillitproject/srcs/map.c \
../../ProjectFiles/fillitproject/srcs/shifters.c
OBJS = ../../ProjectFiles/libft/*.o \
../../ProjectFiles/fillitproject/srcs/solver.o\
../../ProjectFiles/fillitproject/srcs/map.o \
../../ProjectFiles/fillitproject/srcs/shifters.o
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

debug: 
	gcc -o debuggable ./main.c $(SRCS) $(FLAGS) -I $(HDR) -I $(LIBHDR) -g