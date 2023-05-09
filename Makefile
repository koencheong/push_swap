NAME = push_swap
SRC = 1_push_swap.c 2_operations.c 3_insertion_sort.c 4_merge_sort.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = ./ft_printf/ft_printf.a

all: printf $(NAME)

printf:
	make -C ./ft_printf

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)

clean:
	rm -f *.o
	rm -f ./ft_printf/*.o

fclean: clean
	rm -f *.a
	rm -f ./ft_printf.a

re: fclean all