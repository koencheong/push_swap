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

t_list	*sort_three_num(t_list **stackA, t_list *top, t_list *mid, t_list *btm)
{
	if (is_sorted(stackA))
		return (*stackA);
	else if (top->num > mid->num && top->num < btm->num)
		swap_first_two(stackA, 'a');
	else if (top->num > mid->num && mid->num > btm->num)
	{
		swap_first_two(stackA, 'a');
		last_to_first(stackA, 'a');
	}
	else if (top->num > mid->num && mid->num < btm->num)
		first_to_last(stackA, 'a');
	else if (top->num < btm->num && mid->num > btm->num)
	{
		last_to_first(stackA, 'a');
		swap_first_two(stackA, 'a');
	}
	else if (top->num < mid->num && top->num > btm->num)
		last_to_first(stackA, 'a');
	return (*stackA);
}

t_list	*sort_four_num(t_list **stackA, t_list **stackB)
{
	t_list	*top;
	t_list	*mid;
	t_list	*btm;

	top = *stackA;
	if (top->index == 0)
	{
		push(stackB, stackA, 'b');
		top = *stackA;
		mid = (*stackA)->next;
		btm = mid->next;
		*stackA = sort_three_num(stackA, top, mid, btm);
		push(stackA, stackB, 'a');
	}
	if (top->index == 1)
	{
		push(stackB, stackA, 'b');
		top = *stackA;
		mid = (*stackA)->next;
		btm = mid->next;
		*stackA = sort_three_num(stackA, top, mid, btm);
		push(stackA, stackB, 'a');
		swap_first_two(stackA, 'a');
	}
	if (top->index == 2)
	{
		push(stackB, stackA, 'b');
		top = *stackA;
		mid = (*stackA)->next;
		btm = mid->next;
		*stackA = sort_three_num(stackA, top, mid, btm);
		first_to_last(stackA, 'a');
		push(stackA, stackB, 'a');
		swap_first_two(stackA, 'a');
		last_to_first(stackA, 'a');
	}
	if (top->index == 3)
	{
		push(stackB, stackA, 'b');
		top = *stackA;
		mid = (*stackA)->next;
		btm = mid->next;
		*stackA = sort_three_num(stackA, top, mid, btm);
		push(stackA, stackB, 'a');
		first_to_last(stackA, 'a');
	}
	return (*stackA);
}

void	small_sort(t_list **stackA, t_list **stackB, int size)
{
	t_list	*top;
	t_list	*mid;
	t_list	*btm;

	top = *stackA;
	mid = (*stackA)->next;
	btm = (*stackA)->next->next;
	if (size == 2)
		swap_first_two(stackA, 'a');
	if (size == 3)
		*stackA = sort_three_num(stackA, top, mid, btm);
	if (size == 4)
		*stackA = sort_four_num(stackA,  stackB);
	if (size == 5)
	{
		while (top != NULL)
		{
			if (top->index != 0)
			{
				top = (*stackA)->next;
				first_to_last(stackA, 'a');
			}
			else
				break ;
		}
		push(stackB, stackA, 'b');
		while (top != NULL)
		{
			if (top->index != 1)
			{
				top = (*stackA)->next;
				first_to_last(stackA, 'a');
			}
			else
				break ;
		}
		push(stackB, stackA, 'b');
		top = *stackA;
		mid = (*stackA)->next;
		btm = (*stackA)->next->next;
		sort_three_num(stackA, top, mid, btm);
		push(stackA, stackB, 'a');
		push(stackA, stackB, 'a');
	}
}