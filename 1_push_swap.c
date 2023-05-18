/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheong <kcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:36:36 by kcheong           #+#    #+#             */
/*   Updated: 2023/05/18 17:38:29 by kcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	helper(char **input, int i, int j, t_list **stack_a)
{
	i = 0;
	if (input[i] == NULL)
	{
		free_2darray(input);
		exit_function("Error\n", 1);
	}
	while (input[i] != NULL)
	{
		check_valid(input, i, j);
		add_to_list(stack_a, input, i);
		i++;
	}
}

void	parse_input(int argc, char **argv, t_list **stack_a)
{
	int		i;
	int		j;
	char	**input;

	i = 1;
	j = 0;
	if (argc > 2)
	{
		while (i < argc)
		{
			check_valid(argv, i, j);
			add_to_list(stack_a, argv, i);
			i++;
		}
	}
	else if (argc == 2)
	{
		input = ft_split(argv[1], ' ');
		helper(input, i, j, stack_a);
	}
	else
		exit_function("", 1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = malloc(sizeof(t_list));
	stack_a = NULL;
	stack_b = malloc(sizeof(t_list));
	stack_b = NULL;
	parse_input(argc, argv, &stack_a);
	push_swap(&stack_a, &stack_b);
	free_list(stack_a);
	free_list(stack_b);
}

	// printlist(stack_a, 'a');
	// print_index_list(stack_a, 'a');
	// if (is_sorted(&stack_a))
	// 	ft_printf("Sorted :)\n");
	// else
	// 	ft_printf("Not sorted :(\n");