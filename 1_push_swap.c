/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheong <kcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:36:36 by kcheong           #+#    #+#             */
/*   Updated: 2023/05/18 00:24:24 by kcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void helper(char **input, int i, int j, t_list **stackA)
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
		add_to_list(stackA, input, i);
		i++;
	}
}

void	parse_input(int argc, char **argv, t_list **stackA)
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
			add_to_list(stackA, argv, i);
			i++;
		}
	}
	else if (argc == 2)
	{
		input = ft_split(argv[1], ' ');
		helper(input, i, j, stackA);
	}
	else
		exit_function("", 1);
}

int	main(int argc, char **argv)
{
	t_list	*stackA;
	t_list	*stackB;
	
	stackA = malloc(sizeof(t_list));
	stackA = NULL;
	stackB = malloc(sizeof(t_list));
	stackB = NULL;
	parse_input(argc, argv, &stackA);
	push_swap(&stackA, &stackB);
	// printlist(stackA, 'a');
	// print_index_list(stackA, 'a');
	// if (is_sorted(&stackA))
	// 	ft_printf("Sorted :)\n");
	// else
	// 	ft_printf("Not sorted :(\n");
	free_list(stackA);
	free_list(stackB);
}
