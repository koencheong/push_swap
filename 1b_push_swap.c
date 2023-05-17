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

void	push_swap(t_list **stackA, t_list **stackB)
{
	int	len;

	len = 0;
	if (has_duplicates(stackA))
		exit_function("Error\n", 1);
	else
	{
		len = stack_len(*stackA, len);
		if (is_sorted(stackA))
			exit_function("", 1);
		else
		{
			*stackA = rescaling(*stackA, len);
			if (len  <= 5)
				small_sort(stackA, stackB, len);
			else
				exec_radix_sort(stackA, stackB);
		}
	}
}
