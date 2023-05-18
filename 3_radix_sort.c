/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_radix_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheong <kcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:39:14 by kcheong           #+#    #+#             */
/*   Updated: 2023/05/14 17:39:14 by kcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_max_unindexed(t_list *stack)
{
	t_list	*max_node;
	long	max_num;

	max_node = NULL;
	max_num = INT_MIN;
	while (stack != NULL)
	{
		// if (stack->num == max_num && (stack->index == 0))
		// 	return (NULL);
		if (stack->index == 0 && stack->num >= max_num)
		{
			max_num = stack->num;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_list	*rescaling(t_list *stack, int size)
{
	t_list	*current;
	t_list	*largest_num;

	current = stack;
	while (size-- > 0)
	{
		largest_num = find_max_unindexed(stack);
		if (largest_num == NULL)
			return (NULL);
		largest_num->index = size;
	}
	return (current);
}

int	find_max_index(t_list *stack)
{
	t_list	*current;
	int		max_num;

	current = stack;
	max_num = stack->index;
	while (current != NULL)
	{
		if (current->index > max_num)
			max_num = current->index;
		current = current->next;
	}
	return (max_num);
}

int	find_max_bits(int max_index)
{
	int	max_bits;

	max_bits = 0;
	while (max_index != 0)
	{
		max_bits++;
		max_index = max_index >> 1;
	}
	return (max_bits);
}

void	radix_sort(t_list **stack_a, t_list **stack_b
	, int max_index, int max_bits)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	while (*stack_a != NULL && i < max_bits)
	{
		j = 0;
		while (j <= max_index)
		{
			num = (*stack_a)->index;
			if ((num >> i) & 1)
				first_to_last(stack_a, 'a');
			else
				push(stack_b, stack_a, 'b');
			j++;
		}
		while (*stack_b != NULL)
			push(stack_a, stack_b, 'a');
		i++;
	}
}
