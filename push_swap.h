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

# define INT_MIN -2147483647 
# define INT_MAX 2147483647

void	swap_first_two(t_list **stack, char c);
void	first_to_last(t_list **stack, char c);
void	last_to_first(t_list **stack, char c);
void	push(t_list **to, t_list **from, char c);

// void	insertion_sort(t_list **stackA, t_list **stackB);

int		is_sorted(t_list **stack);
int 	has_duplicates(t_list **stack);
void	check_valid(char **argv, int i, int j);
void	add_to_list(t_list **stackA, char **argv, int i);

int 	stack_len(t_list *stack, int len);
void	printlist(t_list *stack, char c);
void	print_index_list(t_list *stack, char c);

int		find_max_bits(int max_num);
int 	find_max_index(t_list *stack);
t_list	*rescaling(t_list *stack, int i);
void    exec_radix_sort(t_list **stackA, t_list **stackB);
void    radix_sort(t_list **stackA, t_list **stackB, int max_index, int max_bits);

void 	free_list(t_list *stack);
void	free_2darray(char **array);
void	exit_function(char *message, int status);

void	small_sort(t_list **stackA, t_list **stackB, int size);
void	push_swap(t_list **stackA, t_list **stackB);

#endif
