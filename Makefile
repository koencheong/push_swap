NAME = push_swap
SRC = 1_push_swap.c 2_operations.c 3_insertion_sort.c 4_radix_sort.c 5_utils.c 6_checking.c 7_small_sort.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = -L./libft -lft -L./libft/ft_printf -lftprintf -L./libft/get_next_line -lftgnl
# LIB = ./libft/libft.a ./libft/ft_printf/libftprintf.a ./libft/get_next_line/libftgnl.a

all: libft1 printf gnl $(NAME)

libft1: libft
	make -C libft

printf:
	make -C libft/ft_printf

gnl: 
	make -C libft/get_next_line

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIB)  

clean:
	rm -f *.o
	rm -f libft/ft_printf/*.o libft/get_next_line/*.o libft/*.o

fclean: clean
	rm -f *.a
	rm -f -f libft/ft_printf/*.a libft/get_next_line/*.a libft/*.a

re: fclean all