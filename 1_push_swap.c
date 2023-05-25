/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheong <kcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:36:36 by kcheong           #+#    #+#             */
/*   Updated: 2023/05/25 18:46:48 by kcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		exit (0);
	stack_a = NULL;
	stack_b = NULL;
	parse_input(argc, argv, &stack_a);
	push_swap(&stack_a, &stack_b);
}

	// system("leaks push_swap");
	// printlist(stack_a, 'a');
	// print_index_list(stack_a, 'a');
	// exit(0);
	// if (is_sorted(&stack_a))
	// 	ft_printf("Sorted :)\n");
	// else
	// 	ft_printf("Not sorted :(\n");
	// printlist(stack_a, 'a');
	// print_index_list(stack_a, 'a');
	// if (is_sorted(&stack_a))
	// 	ft_printf("Sorted :)\n");
	// else
	// 	ft_printf("Not sorted :(\n");