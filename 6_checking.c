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
    if (stack == NULL)
		return (1);
	
	t_list *prev;
    t_list *curr;
    
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

void	check_valid(char **argv, int i, int j)
{
	while (argv[i][j] != '\0')
	{
		if (*argv[1] == '\0')
			exit_function("Error\n", 1);
		if (argv[i][j] == '+' || argv[i][j] == '-')
		{
			if (j != 0)
				exit_function("Error\n", 1);
			if (argv[i][j + 1] == '0')
				exit_function("Error\n", 1);
		}
		if (argv[i][0] == '0')
		{
			if (argv[i][1] != '\0' && argv[i][1] != '0')
				exit_function("Error\n", 1);
			if (argv[i][1] != '\0' && (ft_isdigit(argv[i][0])))
				exit_function("Error\n", 1);
		} 
		if (!ft_isdigit(argv[i][j]))
			exit_function("Error\n", 1);
		j++;
	}
}

int has_duplicates(t_list **stack)
{
    t_list *current;
	t_list *traverse;

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

void	add_to_list(t_list **stackA, char **argv, int i)
{
	t_list	*temp;
	long	num;

	temp = NULL;
	num = 0;

	num = ft_atoi(argv[i]);
	if (num < INT_MIN || num > INT_MAX)
		exit_function("Error\n", 1);
	temp = ft_lstnew(num);
	ft_lstadd_back(stackA, temp);
}