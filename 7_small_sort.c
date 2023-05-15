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
	if (top->num > mid->num && top->num < btm->num)
		swap_first_two(stackA, 'a');
	else if (top->num > mid->num && mid->num > btm->num)
	{
		swap_first_two(stackA, 'a');
		last_to_first(stackA, 'a');
	}
	else if (top->num > mid->num && mid->num < btm->num)
		first_to_last(stackA, 'a');
	else if (top->num < mid->num && top->num < btm->num)
	{
		last_to_first(stackA, 'a');
		swap_first_two(stackA, 'a');
	}
	else if (top->num < mid->num && mid->num > btm->num)
		last_to_first(stackA, 'a');
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
	if (size == 5)
	{
		push(stackB, stackA, 'b');
		push(stackB, stackA, 'b');
		top = *stackA;
		mid = (*stackA)->next;
		btm = (*stackA)->next->next;
		*stackA = sort_three_num(stackA, top, mid, btm);
		printlist(*stackA, 'a');
	}
}