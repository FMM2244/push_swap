/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:40:27 by fmaaita           #+#    #+#             */
/*   Updated: 2025/02/19 13:40:33 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * finds the smallest value bigger than privous_min
 */
int	find_next_min(t_node *head, int previous_min)
{
	int	next_minimum;

	next_minimum = INT_MAX;
	while (head)
	{
		if (head->num < next_minimum && head->num > previous_min)
			next_minimum = head->num;
		head = head->next;
	}
	return (next_minimum);
}

/**
 * sets the index of the item to the appropriate index for it
 */
void	set_index(t_stack *stacks)
{
	int				previous_min;
	t_node			*temp1;
	t_node			*temp2;
	unsigned int	index;

	find_min(stacks->a_head, &previous_min);
	temp1 = stacks->a_head;
	index = 0;
	while (temp1)
	{
		temp2 = stacks->a_head;
		while (temp2)
		{
			if (temp2->num == previous_min)
			{
				temp2->index = index;
				break ;
			}
			temp2 = temp2->next;
		}
		index++;
		temp1 = temp1->next;
		previous_min = find_next_min(stacks->a_head, previous_min);
	}
}

/**
 * returns the number of items in the stack (length)
 */
int	get_stack_size(t_node *head)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = head;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

/**
 * handle the negative numbers case using index in and array
 */
void	radix(t_stack *stacks)
{
	int	i;
	int	size;

	i = 0;
	while (i < 32)
	{
		size = get_stack_size(stacks->a_head);
		while (size--)
		{
			if ((stacks->a_head->index >> i & 1) == 0)
				pb(stacks);
			else
				ra(&stacks->a_head, &stacks->a_tail);
		}
		i++;
		while (stacks->b_head)
			pa(stacks);
		if (is_sorted(stacks->a_head))
			break ;
	}
}
