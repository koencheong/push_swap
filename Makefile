NAME1 = push_swap
NAME2 = checker
SRC = 1_push_swap.c 1b_push_swap.c 2_operations.c 3_radix_sort.c 4_utils.c 5_checking.c 6_small_sort.c 
SRC2 = 1b_push_swap.c 2_operations.c 3_radix_sort.c 4_utils.c 5_checking.c 6_small_sort.c 7_checker.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
LIB = -L./libft -lft -L./libft/ft_printf -lftprintf -L./libft/get_next_line -lftgnl
AR = ar rcs
# LIB = ./libft/libft.a ./libft/ft_printf/libftprintf.a ./libft/get_next_line/libftgnl.a

all: libft1 printf gnl $(NAME1) $(NAME2)

libft1: libft
	make -C libft

printf:
	make -C libft/ft_printf

gnl: 
	make -C libft/get_next_line

$(NAME1): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME1) $(SRC) $(LIB)

$(NAME2): $(SRC2)
	$(CC) $(CFLAGS) -o $(NAME2) $(SRC2) $(LIB)

clean:
	rm -f *.o
	rm -f libft/ft_printf/*.o libft/get_next_line/*.o libft/*.o

fclean: clean
	rm -f $(NAME1) $(NAME2)
	rm -f -f libft/ft_printf/*.a libft/get_next_line/*.a libft/*.a

re: fclean all
