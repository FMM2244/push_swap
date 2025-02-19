/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:40:04 by fmaaita           #+#    #+#             */
/*   Updated: 2025/02/19 13:40:06 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
				print_error(NULL);
			j++;
		}
		if (j > 11)
			print_error(NULL);
	}
}

/**
 * creates a new node
 */
void	new_node(int contents, t_node **new)
{
	*new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return ;
	(*new)->num = contents;
	(*new)->next = NULL;
	(*new)->pre = NULL;
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
				print_error(stacks);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	stack;

	if (ac == 1)
		return (0);
	stack.b_head = NULL;
	stack.b_tail = NULL;
	error_handling(av);
	if (ac == 2)
		return (0);
	stack_a_init(&stack, ac, av);
	are_there_duplicates(&stack);
	if (!is_sorted(stack.a_head))
	{
		set_index(&stack);
		if (ac <= 6)
			less_than_seven(&stack, ac - 1);
		else
			radix(&stack);
	}
	free_all(&stack);
	return (0);
}
