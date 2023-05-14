/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheong <kcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:29:22 by kcheong           #+#    #+#             */
/*   Updated: 2023/05/14 17:29:22 by kcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_len(t_stack *stack, int len)
{
	t_stack	*current;

	current = stack;
    len = 0;
	while (current != NULL)
	{
		current = current->next;
		len++;
    }
    return (len);
}

void	print_index_list(t_stack *stack, char c)
{
	t_stack *current;

	current = stack;
	if (c == 'a')
		ft_printf("Stack A:\n");
	else if (c == 'b')
		ft_printf("\nStack B:\n");
	
	if (stack == NULL)
	{
		ft_printf("Linked list is empty.\n");
		return ;
	}
	while (current != NULL)
	{
		ft_printf("%d\n", current->index);
		current = current->next;
	}
}

void	printlist(t_stack *stack, char c)
{
	t_stack *current;

	current = stack;
	if (c == 'a')
		ft_printf("Stack A:\n");
	else if (c == 'b')
		ft_printf("\nStack B:\n");
	
	if (stack == NULL)
	{
		ft_printf("Linked list is empty.\n");
		return ;
	}
	while (current != NULL)
	{
		ft_printf("%d\n", current->num);
		current = current->next;
	}
}

void free_list(t_stack *stack)
{
    t_stack *temp;

    while (stack != NULL)
	{
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}

void	exit_function(char *message, int status)
{
	ft_printf("%s\n", message);
	exit(status);
}