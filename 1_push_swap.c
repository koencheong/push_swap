/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheong <kcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:36:36 by kcheong           #+#    #+#             */
/*   Updated: 2023/05/07 14:36:36 by kcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_valid(char **argv, int i)
{
	int	j;
	
	j = 0;
	while (argv[i][j] != '\0')
	{
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

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stackA;
	t_list	*stackB;
	int		len;
	char	**input;
	
	len = 0;
	stackA = malloc(sizeof(t_list));
	stackA = NULL;
	stackB = malloc(sizeof(t_list));
	stackB = NULL;

	i = 1;
	if (argc > 2)
	{
		while (i < argc)
		{
			check_valid(argv, i);
			add_to_list(&stackA, argv, i);
			i++;
		}
	}
	else if (argc == 2)
	{
		i = 0;
		input = ft_split(argv[1], ' ');
		if (input[0] == NULL)
		{
			free_2darray(input);
			exit_function("", 1);
		}
		while (input[i] != NULL)
		{
			check_valid(input, i);
			add_to_list(&stackA, input, i);
			i++;
		}
	}
	else
		exit_function("", 1);
	if (has_duplicates(&stackA))
		exit_function("Error\n", 1);
	else
	{
		len = stack_len(stackA, len);
		if (is_sorted(&stackA))
			exit_function("", 1);
		else
		{
			stackA = rescaling(stackA, len);
			if (len == 2 || len == 3 || len == 5)
				small_sort(&stackA, &stackB, len);
			else
				radix_sort(&stackA, &stackB);
		}
	}
	// printlist(stackA, 'a');
	// print_index_list(stackA, 'a');
	// if (is_sorted(&stackA))
	// 	ft_printf("Sorted :)\n");
	// else
	// 	ft_printf("Not sorted :(\n");
	free_list(stackA);
	free_list(stackB);
}
