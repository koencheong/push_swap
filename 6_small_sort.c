/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_small_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheong <kcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:04:02 by kcheong           #+#    #+#             */
/*   Updated: 2023/05/14 19:04:02 by kcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort_three_num(t_list **stack_a, t_list *top, t_list *mid, t_list *btm)
{
	top = *stack_a;
	mid = (*stack_a)->next;
	btm = mid->next;
	if (is_sorted(stack_a))
		return (*stack_a);
	else if (top->num > mid->num && top->num < btm->num)
		swap_first_two(stack_a, 'a');
	else if (top->num > mid->num && mid->num > btm->num)
	{
		swap_first_two(stack_a, 'a');
		last_to_first(stack_a, 'a');
	}
	else if (top->num > mid->num && mid->num < btm->num)
		first_to_last(stack_a, 'a');
	else if (top->num < btm->num && mid->num > btm->num)
	{
		last_to_first(stack_a, 'a');
		swap_first_two(stack_a, 'a');
	}
	else if (top->num < mid->num && top->num > btm->num)
		last_to_first(stack_a, 'a');
	return (*stack_a);
}

void	sort_four_num2(t_list **stack_a, t_list **stack_b)
{
	t_list	*top;
	t_list	*mid;
	t_list	*btm;

	top = NULL;
	mid = NULL;
	btm = NULL;
	if ((*stack_a)->index == 2)
	{
		push(stack_b, stack_a, 'b');
		*stack_a = sort_three_num(stack_a, top, mid, btm);
		first_to_last(stack_a, 'a');
		push(stack_a, stack_b, 'a');
		swap_first_two(stack_a, 'a');
		last_to_first(stack_a, 'a');
	}
	if ((*stack_a)->index == 3)
	{
		push(stack_b, stack_a, 'b');
		*stack_a = sort_three_num(stack_a, top, mid, btm);
		push(stack_a, stack_b, 'a');
		first_to_last(stack_a, 'a');
	}
}

t_list	*sort_four_num(t_list **stack_a, t_list **stack_b)
{
	t_list	*top;
	t_list	*mid;
	t_list	*btm;

	top = NULL;
	mid = NULL;
	btm = NULL;
	if ((*stack_a)->index == 0)
	{
		push(stack_b, stack_a, 'b');
		*stack_a = sort_three_num(stack_a, top, mid, btm);
		push(stack_a, stack_b, 'a');
	}
	if ((*stack_a)->index == 1)
	{
		push(stack_b, stack_a, 'b');
		*stack_a = sort_three_num(stack_a, top, mid, btm);
		push(stack_a, stack_b, 'a');
		swap_first_two(stack_a, 'a');
	}
	else
		sort_four_num2(stack_a, stack_b);
	return (*stack_a);
}

void	sort_five_num2(t_list **stack_a, t_list **stack_b)
{
	t_list	*top;
	t_list	*mid;
	t_list	*btm;

	top = *stack_a;
	mid = NULL;
	btm = NULL;
	while (top != NULL)
	{
		if (top->index != 1)
		{
			top = (*stack_a)->next;
			first_to_last(stack_a, 'a');
		}
		else
			break ;
	}
	push(stack_b, stack_a, 'b');
	sort_three_num(stack_a, top, mid, btm);
	push(stack_a, stack_b, 'a');
	push(stack_a, stack_b, 'a');
}

t_list	*sort_five_num(t_list **stack_a, t_list **stack_b)
{
	t_list	*top;
	t_list	*mid;
	t_list	*btm;

	top = *stack_a;
	mid = (*stack_a)->next;
	btm = (*stack_a)->next->next;
	while (top != NULL)
	{
		if (top->index != 0)
		{
			top = (*stack_a)->next;
			first_to_last(stack_a, 'a');
		}
		else
			break ;
	}
	push(stack_b, stack_a, 'b');
	sort_five_num2(stack_a, stack_b);
	return (*stack_a);
}
