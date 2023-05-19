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

int	is_sorted(t_list **stack)
{
	t_list	*prev;
	t_list	*curr;

	if (stack == NULL)
		return (1);
	prev = *stack;
	curr = (*stack)->next;
	while (curr != NULL)
	{
		if ((prev->num) > (curr->num))
			return (0);
		prev = curr;
		curr = curr->next;
	}
	return (1);
}

int	has_duplicates(t_list **stack)
{
	t_list	*current;
	t_list	*traverse;

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

void	add_to_list(t_list **stack_a, char **argv, int i)
{
	t_list	*temp;
	long	num;

	temp = NULL;
	num = 0;
	num = ft_atoi(argv[i]);
	if (num < INT_MIN || num > INT_MAX)
		exit_function("Error\n", 0);
	temp = ft_lstnew(num);
	ft_lstadd_back(stack_a, temp);
}

int	stack_len(t_list *stack, int len)
{
	t_list	*current;

	current = stack;
	len = 0;
	while (current != NULL)
	{
		current = current->next;
		len++;
	}
	return (len);
}
