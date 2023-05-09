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

int	is_sorted(t_stack **stack)
{
    if (stack == NULL)
		return (1);
	
	t_stack *prev;
    t_stack *curr;
    
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

void	printlist(t_stack *stack, char c)
{
	t_stack *current;

	current = stack;
	if (c == 'a')
		ft_printf("Stack A:\n");
	else if (c == 'b')
		ft_printf("\nStack B:\n");
	
	if (stack == NULL)
	{
		ft_printf("Linked list is empty.\n");
		return ;
	}
	while (current != NULL)
	{
		ft_printf("%d\n", current->num);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		num;
	t_stack	*top;
	t_stack	*stackA;
	t_stack	*stackB;
	int		len;
	
	len = 0;
	i = 1;
	top = NULL;
	stackB = malloc(sizeof(t_stack));
	stackB = NULL;
	if (argc > 1)
	{
		while (i < argc)
		{
			stackA = malloc(sizeof(t_stack));
			num = atoi(argv[i]);
			stackA->num = num;
			stackA->next = top;
			top = stackA;
			i++;
		}
		printlist(stackA, 'a');
		printlist(stackB, 'b');
	}
	// insertion_sort(&stackA, &stackB);
	merge_sort(&stackA, &stackB, len);
	printlist(stackA, 'a');
	printlist(stackB, 'b');
	// if (is_sorted(stackA))
	// 	ft_printf("Sorted :)\n");
	// else
	// 	ft_printf("Not sorted :(\n");
	// push(&stackB, &stackA, 'b');
	// printlist(stackA, 'a');
	// printlist(stackB, 'b');
	// first_to_last(&stackA, 'a');
	// printlist(stackA, 'a');
	// last_to_first(&stackB, 'b');
	// printlist(stackB, 'b');
	// free(stackA);
	// free(stackB);
}