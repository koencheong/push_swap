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

void	push(t_list **to, t_list **from, char c)
{
	if (*from == NULL)
		return ;

	t_list	*newtopFrom;

	newtopFrom = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = newtopFrom;

	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");

}

// sa, sb
void	swap_first_two(t_list **stack, char c)
{
	t_list *temp1;
	t_list *temp2;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;

	temp1 = *stack;
	temp2 = (*stack)->next;

	temp1->next = temp2->next;
	temp2->next = temp1;
	*stack = temp2;

	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
}

// rra, rrb
void	last_to_first(t_list **stack, char c)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	
	t_list	*current;
	t_list	*last;

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
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}

// ra, rb
void	first_to_last(t_list **stack, char c)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;

	t_list	*ori_first;
	t_list	*new_first;
	t_list	*last;

	ori_first = *stack;
	new_first = (*stack)->next;
	last = *stack;
	while (last->next != NULL)
		last = last->next;

	last->next = ori_first;
	ori_first->next = NULL;
	*stack = new_first;
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}
