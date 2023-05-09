/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheong <kcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:27:06 by kcheong           #+#    #+#             */
/*   Updated: 2023/05/07 14:27:06 by kcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **to, t_stack **from, char c)
{
	if (*from == NULL)
	{
		ft_printf("\n[Nothing to be pushed.]\n");
		return ;
	}

	t_stack	*newtopFrom;

	newtopFrom = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = newtopFrom;

	if (c == 'a')
		ft_printf("\n[Executed pa...]\n");
	else if (c == 'b')
		ft_printf("\n[Executed pb...]\n");

}

// sa, sb
void	swap_first_two(t_stack **stack, char c)
{
	t_stack *temp1;
	t_stack *temp2;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		ft_printf("\n[Nothing to be swapped.]\n");
		return ;
	}
	temp1 = *stack;
	temp2 = (*stack)->next;

	temp1->next = temp2->next;
	temp2->next = temp1;
	*stack = temp2;

	if (c == 'a')
		ft_printf("\n[Executed sa...]\n");
	else if (c == 'b')
		ft_printf("\n[Executed sb...]\n");
}

// rra, rrb
void	last_to_first(t_stack **stack, char c)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		ft_printf("\n[Nothing to be reverse rotated.]\n");
		return ;
	}
	
	t_stack	*current;
	t_stack	*last;

	current = *stack;
	while (current->next != NULL)
		current = current->next;
	
	last = current;
	last->next = *stack;
	
	current = *stack;
	while (current->next != last)
		current = current->next;
	current->next = NULL;

	*stack = last;
	if (c == 'a')
		ft_printf("\n[Executed rra...]\n");
	else if (c == 'b')
		ft_printf("\n[Executed rrb...]\n");
}

// ra, rb
void	first_to_last(t_stack **stack, char c)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		ft_printf("\n[Nothing to be rotated.]\n");
		return ;
	}

	t_stack	*ori_first;
	t_stack	*new_first;
	t_stack	*last;

	ori_first = *stack;
	new_first = (*stack)->next;
	last = *stack;
	while (last->next != NULL)
		last = last->next;

	last->next = ori_first;
	ori_first->next = NULL;
	*stack = new_first;
	if (c == 'a')
		ft_printf("\n[Executed ra...]\n");
	else if (c == 'b')
		ft_printf("\n[Executed rb...]\n");
}