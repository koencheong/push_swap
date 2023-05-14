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

# include "./ft_printf/ft_printf.h"
# include <stdlib.h>

# define INT_MIN -2147483647 
# define INT_MAX 2147483647
 
typedef	struct s_stack
{
	int				num;
	int				index;
	struct	s_stack	*next;
}	t_stack;

void	swap_first_two(t_stack **stack, char c);
void	first_to_last(t_stack **stack, char c);
void	last_to_first(t_stack **stack, char c);
void	push(t_stack **to, t_stack **from, char c);

void	insertion_sort(t_stack **stackA, t_stack **stackB);

int		is_sorted(t_stack **stack);
int 	has_duplicates(t_stack **stack);
int 	stack_len(t_stack *stack, int len);
void	printlist(t_stack *stack, char c);
void	print_index_list(t_stack *stack, char c);

int		find_max_bits(int max_num);
int 	find_max_index(t_stack *stack);
t_stack	*rescaling(t_stack *stack, int i);
void    radix_sort(t_stack **stackA, t_stack **stackB);

void 	free_list(t_stack *stack);
void	exit_function(char *message, int status);

#endif

// void	push(struct stack *stack, int num)
// {
// 	struct stackNode *newNode = malloc(sizeof(struct stackNode));
// 	newNode->num = num;
// 	newNode->next = stack->top;
// 	stack->top = newNode;
// }
