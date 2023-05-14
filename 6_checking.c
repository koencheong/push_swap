/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_checking.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheong <kcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:30:41 by kcheong           #+#    #+#             */
/*   Updated: 2023/05/14 17:30:41 by kcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **stack)
{
    if (stack == NULL)
		return (1);
	
	t_stack *prev;
    t_stack *curr;
    
	prev = *stack;
	curr = (*stack)->next;
    while (curr != NULL)
	{
        if ((prev->num) > (curr->num))
            return 0;
        prev = curr;
        curr = curr->next;
    }
    return (1);
}

int has_duplicates(t_stack **stack)
{
    t_stack *current;
	t_stack *traverse;

	current = *stack;
	traverse = *stack;
    while (current != NULL)
    {
		traverse = current->next;
		while (traverse != NULL)
		{
			if (current->num == traverse->num)
				return (1);
			traverse = traverse->next;
		}
		current = current->next;
	}
    return (0);
}