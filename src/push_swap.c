/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatima <fatima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 04:41:26 by fatima            #+#    #+#             */
/*   Updated: 2025/02/18 02:53:40 by fatima           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"
#include <stdio.h>

/**
 * checks if the array is sorted or not
 */
bool	is_sorted(t_node *stack)
{
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

/**
 * prints "Error\n" on the standered error and exits the program
 * with status 0
 */
void	print_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

/** 
 * errors to handle: 
 * follow this link 
 * such as having non-digits in the input
 */
void	error_handling(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 && (av[i][j] == '-' || av[i][j] == '+'))
				j++;
			if (av[i][j] < '0' || av[i][j] > '9')
				print_error();
			j++;
		}
		if (j > 11)
			print_error();
	}
}

/**
 * creates a new node
 */
void	*new_node(int contents)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->num = contents;
	new->next = NULL;
	new->pre = NULL;
	return (new);
}

/**
 * handel duplicate inputs
 */
void	are_there_duplicates(t_stack *stacks)
{
	t_node	*temp1;
	t_node	*temp2;

	temp1 = stacks->a_head;
	while (temp1)
	{
		temp2 = temp1->next;
		while (temp2)
		{
			if (temp1->num == temp2->num)
			{
				// free_stacks(stacks);
				print_error();
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	stack;

	if (ac <= 2)
		return (0);
	stack.a_head = new_node(0);
	stack.a_tail = new_node(0);
	stack.b_head = NULL;
	stack.b_tail = NULL;
	error_handling(av);
	stack_a_init(&stack, ac, av);
	are_there_duplicates(&stack);
	int l = get_stack_size(stack.a_head);
	(void)l;
	if (ac <= 7)
		less_than_seven(&stack, ac - 1);
	// else
	// 	radix(&stack);
	// printf("%d\n", l);
	// while (stack.a_head)
	// {
	// 	printf("\t%d", stack.a_head->num);
	// 	stack.a_head = stack.a_head->next;
	// }
	// printf("\n");
	// while (stack.b_head)
	// {
	// 	printf("\t%d", stack.b_head->num);
	// 	stack.b_head = stack.b_head->next;
	// }
	return (0);
}

// while (stack.b_head)
// {
// 	printf("\t%d", stack.b_head->num);
// 	stack.b_head = stack.b_head->next;
// }
// free(a_head);
// free(a_tail);