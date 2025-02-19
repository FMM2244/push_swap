/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:39:15 by fmaaita           #+#    #+#             */
/*   Updated: 2025/02/19 13:39:22 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack *stacks)
{
	t_node	*t1;
	t_node	*t2;

	if (!stacks)
		return ;
	t1 = stacks->a_head;
	while (t1)
	{
		t2 = t1;
		t1 = t1->next;
		free(t2);
	}
}

bool	should_break(t_stack *stack, int i)
{
	t_node	*temp;

	temp = stack->a_head;
	while (temp)
	{
		if ((((temp->index >> i) & 1) == 1))
			return (false);
		temp = temp->next;
	}
	return (true);
}

/**
 * prints "Error\n" on the standered error and exits the program
 * with status 0
 */
void	print_error(t_stack *s)
{
	ft_putendl_fd("Error", 2);
	free_all(s);
	exit(1);
}
	// t_node	*x;
	// x = stack.a_head;
	// while (x)
	// {
	// 	printf(" %d %d \n", x->num, x->index);
	// 	x = x->next;
	// }
	// printf("\n\n");
	// x = stack.a_head;
	// while (x)
	// {
	// 	printf(" %d ", x->num);
	// 	x = x->next;
	// }
