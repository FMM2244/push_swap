/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_number_of_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:42:43 by fmaaita           #+#    #+#             */
/*   Updated: 2025/02/19 13:42:47 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * finds minimum value in the stack
 */
int	find_min(t_node *a_head, int *minimum)
{
	int	index;

	*minimum = a_head->num;
	index = 0;
	while (a_head)
	{
		if (a_head->num < *minimum)
			*minimum = a_head->num;
		a_head = a_head->next;
		index++;
	}
	return (index);
}

/**
 * handle all passible options for 2 indices
 */
void	handle_two_items(t_stack *stacks)
{
	if (stacks->a_head->num > stacks->a_tail->num)
		sa(stacks->a_head);
	return ;
}

/**
 * trace all possible options for 3 indices 
 */
void	handle_three_items(t_stack *stacks)
{
	int	left;
	int	right;
	int	center;

	left = stacks->a_head->num;
	center = stacks->a_head->next->num;
	right = stacks->a_tail->num;
	if (left < right && right < center)
	{
		sa(stacks->a_head);
		ra(&stacks->a_head, &stacks->a_tail);
	}
	else if (left < right && left > center)
		sa(stacks->a_head);
	else if (left > right && center > left)
		rra(&stacks->a_head, &stacks->a_tail);
	else if (left > center && center > right)
	{
		sa(stacks->a_head);
		rra(&stacks->a_head, &stacks->a_tail);
	}
	else if (left > right && right > center)
		ra(&stacks->a_head, &stacks->a_tail);
}

/**
 * this function is self explanitory
 */
void	hendle_four_to_six_items(t_stack *stacks)
{
	int	*minimum;
	int	index;

	minimum = (int *)malloc(sizeof(int));
	while (get_stack_size(stacks->a_head) != 3)
	{
		index = find_min(stacks->a_head, minimum);
		if (*minimum == stacks->a_head->num)
			pb(stacks);
		else if (index < get_stack_size(stacks->a_head) / 2)
			ra(&stacks->a_head, &stacks->a_tail);
		else
			rra(&stacks->a_head, &stacks->a_tail);
	}
	handle_three_items(stacks);
	while (stacks->b_head)
		pa(stacks);
	free(minimum);
}

/**
 * calls the appropriate function
 * based on the number of nodes in the stack
 */
void	less_than_seven(t_stack *stacks, int length)
{
	if (length == 2)
		handle_two_items(stacks);
	else if (length == 3)
		handle_three_items(stacks);
	else
		hendle_four_to_six_items(stacks);
}
