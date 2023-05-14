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

int	main(int argc, char **argv)
{
	int		i;
	int		num;
	t_stack	*top;
	t_stack	*stackA;
	t_stack	*stackB;
	int		len;
	int		j;
	
	len = 0;
	i = 1;
	top = NULL;
	stackB = malloc(sizeof(t_stack));
	stackB = NULL;
	if (argc > 1)
	{
		while (i < argc)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				if (argv[i][j] != '-' && (argv[i][j] < '0' || argv[i][j] > '9'))
					exit_function("Error", 1);
				j++;
			}
			stackA = malloc(sizeof(t_stack));
			num =  atoi(argv[i]);
			stackA->num = num;
			stackA->next = top;
			top = stackA;
			i++;
		}
		if (has_duplicates(&stackA))
			exit_function("Error", 1);
		len = stack_len(stackA, len);
	}
	else
	{
		free(stackB);
		exit_function("Error", 1);
	}
	stackA = rescaling(stackA, len);
	radix_sort(&stackA, &stackB);
	// printlist(stackA, 'a');
	// print_index_list(stackA, 'a');
	// if (is_sorted(&stackA))
	// 	ft_printf("Sorted :)\n");
	// else
	// 	ft_printf("Not sorted :(\n");
	free_list(stackA);
	free_list(stackB);
}
