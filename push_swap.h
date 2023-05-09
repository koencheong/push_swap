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

typedef	struct s_stack
{
	int				num;
	struct	s_stack	*next;
}	t_stack;

void	swap_first_two(t_stack **stack, char c);
void	first_to_last(t_stack **stack, char c);
void	last_to_first(t_stack **stack, char c);
void	push(t_stack **to, t_stack **from, char c);

void	insertion_sort(t_stack **stackA, t_stack **stackB);
int		is_sorted(t_stack **stack);

void	merge_sort(t_stack **stackA, t_stack **stackB, int len);

#endif

// void	push(struct stack *stack, int num)
// {
// 	struct stackNode *newNode = malloc(sizeof(struct stackNode));
// 	newNode->num = num;
// 	newNode->next = stack->top;
// 	stack->top = newNode;
// }
