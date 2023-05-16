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
	(void)stackB;

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
	len = stack_len(stackA, len);
	stackA = rescaling(stackA, len);

	// print_index_list(stackA, 'a');
	int	fd;
	const char *str;

	fd = 0;
	str = get_next_line(fd);
	while (str)
	{
		if ((!ft_strncmp(str, "sa\n", 3)))
		{
			swap_first_two(&stackA, '0');
			// print_index_list(stackA, 'a');
		}
		else if ((!ft_strncmp(str, "sb\n", 3)))
			swap_first_two(&stackB, '0');
		else if ((!ft_strncmp(str, "ss\n", 3)))
		{
			swap_first_two(&stackA, '0');
			swap_first_two(&stackB, '0');
		}
		else if ((!ft_strncmp(str, "ra\n", 3)))
			first_to_last(&stackA, '0');
		else if ((!ft_strncmp(str, "rb\n", 3)))
			first_to_last(&stackB, '0');
		else if ((!ft_strncmp(str, "rr\n", 3)))
		{
			first_to_last(&stackA, '0');
			first_to_last(&stackB, '0');
		}
		else if ((!ft_strncmp(str, "rra\n", 4)))
		{
			last_to_first(&stackA, '0');
			// print_index_list(stackA, 'a');
		}
		else if ((!ft_strncmp(str, "rrb\n", 4)))
		{
			last_to_first(&stackB, '0');
			// print_index_list(stackA, 'a');
		}
		else if ((!ft_strncmp(str, "rrr\n", 4)))
		{
			last_to_first(&stackA, '0');
			last_to_first(&stackB, '0');
		}
		else if ((!ft_strncmp(str, "pa\n", 3)))
		{	
			push(&stackA, &stackB, '0');
			// print_index_list(stackA, 'a');
		}
		else if ((!ft_strncmp(str, "pb\n", 3)))
			push(&stackB, &stackA, '0');
		else
		{
			exit_function("Error\n", 1);
		}
		free((void*)str);
		str = get_next_line(fd);
	}
	// print_index_list(stackA, 'a');
	if (is_sorted(&stackA) && (stackB == NULL))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}