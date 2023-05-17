/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheong <kcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:01:09 by kcheong           #+#    #+#             */
/*   Updated: 2023/05/16 11:01:09 by kcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_cmd2(t_list **stackA, t_list **stackB, const char *str)
{
	if ((!ft_strncmp(str, "rb\n", 3)))
			first_to_last(stackB, '0');
	else if ((!ft_strncmp(str, "rr\n", 3)))
	{
		first_to_last(stackA, '0');
		first_to_last(stackB, '0');
	}
	else if ((!ft_strncmp(str, "rra\n", 4)))
		last_to_first(stackA, '0');
	else if ((!ft_strncmp(str, "rrb\n", 4)))
		last_to_first(stackB, '0');
	else if ((!ft_strncmp(str, "rrr\n", 4)))
	{
		last_to_first(stackA, '0');
		last_to_first(stackB, '0');
	}
	else if ((!ft_strncmp(str, "pa\n", 3)))
		push(stackA, stackB, '0');
	else if ((!ft_strncmp(str, "pb\n", 3)))
		push(stackB, stackA, '0');
	else
		exit_function("Error\n", 1);
}

void	run_cmd(t_list **stackA, t_list **stackB)
{
	int	fd;
	const char *str;

	fd = 0;
	str = get_next_line(fd);
	while (str)
	{
		if ((!ft_strncmp(str, "sa\n", 3)))
			swap_first_two(stackA, '0');
		else if ((!ft_strncmp(str, "sb\n", 3)))
			swap_first_two(stackB, '0');
		else if ((!ft_strncmp(str, "ss\n", 3)))
		{
			swap_first_two(stackA, '0');
			swap_first_two(stackB, '0');
		}
		else if ((!ft_strncmp(str, "ra\n", 3)))
			first_to_last(stackA, '0');
		else 
			run_cmd2(stackA, stackB, str);
		free((void*)str);
		str = get_next_line(fd);
	}
}

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
		helper(input, i, j ,stackA);
	}
	else
		exit_function("", 1);
}

int	main(int argc, char **argv)
{
	t_list	*stackA;
	t_list	*stackB;
	int		len;
	
	len = 0;
	stackA = malloc(sizeof(t_list));
	stackA = NULL;
	stackB = malloc(sizeof(t_list));
	stackB = NULL;
	parse_input(argc, argv, &stackA);
	if (has_duplicates(&stackA))
		exit_function("Error\n", 1);
	len = stack_len(stackA, len);
	stackA = rescaling(stackA, len);
	run_cmd(&stackA, &stackB);
	if (is_sorted(&stackA) && (stackB == NULL))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}