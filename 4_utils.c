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

void	print_index_list(t_list *stack, char c)
{
	t_list	*current;

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

void	printlist(t_list *stack, char c)
{
	t_list	*current;

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

void	free_2darray(char **array)
{
	char	**tmp;

	tmp = array;
	while (tmp && *tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(array);
}

void	free_list(t_list *stack)
{
	t_list	*temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

void	error_exit(void)
{
	// system("leaks push_swap");
	write (2, "Error\n", 6);
	exit(0);
}
