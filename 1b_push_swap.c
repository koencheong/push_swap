/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1b_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheong <kcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 00:07:29 by kcheong           #+#    #+#             */
/*   Updated: 2023/05/18 00:07:29 by kcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = 0;
	if (has_duplicates(stack_a))
		exit_function("Error\n", 1);
	else
	{
		len = stack_len(*stack_a, len);
		if (is_sorted(stack_a))
			exit_function("", 1);
		else
		{
			*stack_a = rescaling(*stack_a, len);
			if (len <= 5)
				small_sort(stack_a, stack_b, len);
			else
				exec_radix_sort(stack_a, stack_b);
		}
	}
}

void	small_sort(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	*top;
	t_list	*mid;
	t_list	*btm;

	top = *stack_a;
	mid = (*stack_a)->next;
	btm = (*stack_a)->next->next;
	if (size == 2)
		swap_first_two(stack_a, 'a');
	if (size == 3)
		*stack_a = sort_three_num(stack_a, top, mid, btm);
	if (size == 4)
		*stack_a = sort_four_num(stack_a, stack_b);
	if (size == 5)
		*stack_a = sort_five_num(stack_a, stack_b);
}

void	exec_radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	max_index;
	int	max_bits;

	max_index = find_max_index(*stack_a);
	max_bits = find_max_bits(max_index);
	radix_sort(stack_a, stack_b, max_index, max_bits);
}
