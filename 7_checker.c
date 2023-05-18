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

void	run_cmd2(t_list **stack_a, t_list **stack_b, const char *str)
{
	if ((!ft_strncmp(str, "rb\n", 3)))
		first_to_last(stack_b, '0');
	else if ((!ft_strncmp(str, "rr\n", 3)))
	{
		first_to_last(stack_a, '0');
		first_to_last(stack_b, '0');
	}
	else if ((!ft_strncmp(str, "rra\n", 4)))
		last_to_first(stack_a, '0');
	else if ((!ft_strncmp(str, "rrb\n", 4)))
		last_to_first(stack_b, '0');
	else if ((!ft_strncmp(str, "rrr\n", 4)))
	{
		last_to_first(stack_a, '0');
		last_to_first(stack_b, '0');
	}
	else if ((!ft_strncmp(str, "pa\n", 3)))
		push(stack_a, stack_b, '0');
	else if ((!ft_strncmp(str, "pb\n", 3)))
		push(stack_b, stack_a, '0');
	else
		exit_function("Error\n", 1);
}

void	run_cmd(t_list **stack_a, t_list **stack_b)
{
	int			fd;
	const char	*str;

	fd = 0;
	str = get_next_line(fd);
	while (str)
	{
		if ((!ft_strncmp(str, "sa\n", 3)))
			swap_first_two(stack_a, '0');
		else if ((!ft_strncmp(str, "sb\n", 3)))
			swap_first_two(stack_b, '0');
		else if ((!ft_strncmp(str, "ss\n", 3)))
		{
			swap_first_two(stack_a, '0');
			swap_first_two(stack_b, '0');
		}
		else if ((!ft_strncmp(str, "ra\n", 3)))
			first_to_last(stack_a, '0');
		else
			run_cmd2(stack_a, stack_b, str);
		free((void *)str);
		str = get_next_line(fd);
	}
}

void	helper(char **input, int i, int j, t_list **stack_a)
{
	i = 0;
	if (input[1] == NULL)
	{
		free_2darray(input);
		exit_function("", 1);
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
	input = NULL;
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
	int		len;

	len = 0;
	stack_a = malloc(sizeof(t_list));
	stack_a = NULL;
	stack_b = malloc(sizeof(t_list));
	stack_b = NULL;
	parse_input(argc, argv, &stack_a);
	if (has_duplicates(&stack_a))
		exit_function("", 1);
	len = stack_len(stack_a, len);
	stack_a = rescaling(stack_a, len);
	run_cmd(&stack_a, &stack_b);
	if (is_sorted(&stack_a) && (stack_b == NULL))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
