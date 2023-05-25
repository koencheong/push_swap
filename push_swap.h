/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheong <kcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 12:46:13 by kcheong           #+#    #+#             */
/*   Updated: 2023/05/07 12:46:13 by kcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./libft/ft_printf/ft_printf.h"
# include "./libft/get_next_line/get_next_line_bonus.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

// main
void	push_swap(t_list **stack_a, t_list **stack_b);

// operations
void	swap_first_two(t_list **stack, char c);
void	first_to_last(t_list **stack, char c);
void	last_to_first(t_list **stack, char c);
void	push(t_list **to, t_list **from, char c);

// checking
int		is_sorted(t_list **stack);
int		has_duplicates(t_list **stack);
void	parse_input(int argc, char **argv, t_list **stack_a);
void	helper(char **input, int i, int j, t_list **stack_a);
void	add_to_list(t_list **stack_a, char **argv, int i);

// utils
int		stack_len(t_list *stack, int len);
void	printlist(t_list *stack, char c);
void	print_index_list(t_list *stack, char c);
void	free_list(t_list *stack);
void	free_2darray(char **array);
void	error_exit(void);

// radix sort
int		find_max_bits(int max_num);
int		find_max_index(t_list *stack);
t_list	*rescaling(t_list **stack, int i);
void	exec_radix_sort(t_list **stack_a, t_list **stack_b);
void	radix_sort(t_list **stack_a, t_list **stack_b,
			int max_index, int max_bits);

// small sort
void	small_sort(t_list **stack_a, t_list **stack_b, int size);
t_list	*sort_three_num(t_list **stack_a);
void	sort_three_num2(t_list **stack_a, t_list *top,
			t_list *mid, t_list *btm);
t_list	*sort_four_num(t_list **stack_a, t_list **stack_b);
void	sort_four_num2(t_list **stack_a, t_list **stack_b);
t_list	*sort_five_num(t_list **stack_a, t_list **stack_b, int len);

#endif
