/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_insertion_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheong <kcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:47:58 by kcheong           #+#    #+#             */
/*   Updated: 2023/05/08 11:47:58 by kcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_stack **stackA, t_stack **stackB)
{
	t_stack *temp;

    while (*stackA != NULL)
    {
        temp = *stackA;

		if (*stackB == NULL)
			push(stackB, stackA, 'b');
        if (temp->num < (*stackB)->num)
		{
			push(stackB, stackA, 'b');
			first_to_last(stackB, 'b');
		}
		else if (temp->num > (*stackB)->num)
			push(stackB, stackA, 'b');
		temp = *stackA;
    }
	if (*stackA == NULL)
	{
		while (*stackB != NULL)
			push(stackA, stackB, 'a');
	}
	
	if (is_sorted(stackA))
		return ;
	else
		insertion_sort(stackA, stackB);
}
