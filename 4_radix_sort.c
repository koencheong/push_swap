/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_merge_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheong <kcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:40:05 by kcheong           #+#    #+#             */
/*   Updated: 2023/05/09 22:40:05 by kcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *find_max_unindexed(t_stack *stack)
{
    t_stack *max_node;
    int     max_num;

    max_node = NULL;
    max_num = INT_MIN;
    while (stack != NULL)
    {
        if (stack->num == max_num && (stack->index == 0))
            return (NULL);
        if (stack->index == 0 && stack->num > max_num)
        {
            max_num = stack->num;
            max_node = stack;
        }
        stack = stack->next;
    }
    return (max_node);
}

t_stack	*rescaling(t_stack *stack, int size)
{
	t_stack	*current;
	t_stack	*largest_num;

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

int find_max_index(t_stack *stack)
{
    t_stack *current;
    int     max_num;

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

int find_max_bits(int max_index)
{
    int max_bits;

    max_bits = 0;
    while (max_index != 0)
    {
        max_bits++;
        max_index = max_index >> 1;
    }
    return (max_bits);
}

void    radix_sort(t_stack **stackA, t_stack **stackB)
{
    int max_index;
    int max_bits;
    int i;
    int j;
    int num;

    max_index = find_max_index(*stackA);
    max_bits = find_max_bits(max_index);
    i = 0;
    while (*stackA != NULL && i < max_bits)
    {
        j = 0;
        while (j <= max_index)
        {
            num = (*stackA)->index;
            if ((num >> i) & 1)
                first_to_last(stackA, 'a');
            else
                push(stackB, stackA, 'b');
            j++;
        }
        while (*stackB != NULL)
                push(stackA, stackB, 'a');
        i++;
    }
}
