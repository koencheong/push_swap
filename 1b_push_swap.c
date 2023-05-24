/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1b_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheong <kcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 00:07:29 by kcheong           #+#    #+#             */
/*   Updated: 2023/05/18 00:07:29 by kcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	helper(char **input, int i, int j, t_list **stack_a)
// {
// 	if (input[i][j] == '\0')
// 		error_exit();
// 	if ((input[i][j] == '0') && (input[i][j + 1] != '\0'))
// 		error_exit();
// 	while (input[i][j] != '\0')
// 	{
// 		if (input[i][j] == '+' || input[i][j] == '-')
// 		{
// 			if (!ft_isdigit(input[i][j + 1]))
// 				error_exit();
// 		}
// 		else if (!ft_isdigit(input[i][j]))
// 			error_exit();
// 		j++;
// 	}
// 	add_to_list(stack_a, input, i);
// }

void    helper(char **input, int i, int j, t_list **stack_a)
{
    if (input[i][j] == '\0')
        error_exit();
    if (input[i][j] == '+' || input[i][j] == '-')
    {
        j++;
        if (!ft_isdigit(input[i][j]))
            error_exit();
    }
    while (input[i][j] != '\0')
    {
        if ((input[i][j] >= 32 && input[i][j] <= 47)
            || (input[i][j] >= 58 && input[i][j] < 127))
            error_exit();
        if (!ft_isdigit(input[i][j]) && input[i][j] == '\n')
            error_exit();
        j++;
    }
    add_to_list(stack_a, input, i);
}

void	parse_input(int argc, char **argv, t_list **stack_a)
{
	int		i;
	int		j;
	char	**input;

	i = 0;
	j = 0;
	input = NULL;
	if (argc > 2)
	{
		while (++i < argc)
			helper(argv, i, j, stack_a);
	}
	else if (argc == 2)
	{
		i = -1;
		input = ft_split(argv[1], ' ');
		if (*input == NULL)
			exit(0);
		while (input[++i] != NULL)
			helper(input, i, j, stack_a);
	}
	free_2darray(input); 
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = 0;
	if (has_duplicates(stack_a))
		error_exit();
	else
	{
		len = stack_len(*stack_a, len);
		if (is_sorted(stack_a))
			exit(0);
		else
		{
			*stack_a = rescaling(*stack_a, len);
			if (len <= 5)
				small_sort(stack_a, stack_b, len);
			else
				exec_radix_sort(stack_a, stack_b);
		}
	}
}

void	small_sort(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	*top;
	t_list	*mid;
	t_list	*btm;

	top = *stack_a;
	mid = (*stack_a)->next;
	btm = (*stack_a)->next->next;
	if (size == 2)
		swap_first_two(stack_a, 'a');
	else if (size == 3)
		*stack_a = sort_three_num(stack_a, top, mid, btm);
	else if (size == 4)
		*stack_a = sort_four_num(stack_a, stack_b);
	else if (size == 5)
		*stack_a = sort_five_num(stack_a, stack_b);
}

void	exec_radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	max_index;
	int	max_bits;

	max_index = find_max_index(*stack_a);
	max_bits = find_max_bits(max_index);
	radix_sort(stack_a, stack_b, max_index, max_bits);
}
