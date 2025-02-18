/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatima <fatima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 03:42:14 by fatima            #+#    #+#             */
/*   Updated: 2025/02/18 15:25:39 by fatima           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

/**
 * finds the smallest value bigger than privous_min
 */
int	find_next_min(t_node *head, int previous_min)
{
	int	next_minimum;

	printf("entering find next min\n");
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
	int		index;
	int		previous_min;
	t_node	*temp1;
	t_node	*temp2;

	printf("entering set index\n");
	temp1 = stacks->a_head;
	temp2 = stacks->a_head;
	index = 1;
	find_min(stacks->a_head, &previous_min);
	while (temp1)
	{
		temp2 = stacks->a_head;
		while (temp2)
		{
			if (temp2->num == previous_min)
			{
				temp2->index = index;
				temp2 = temp2->next;
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
 * sorts stack b so it's ready to be pushed to stack a
 */
void	sort_b(t_stack *stacks)
{
	int	size;
	int	i;
	t_node	*temp;

	size = get_stack_size(stacks->b_head);
	temp = stacks->b_head;
	while (!is_sorted(stacks->b_head))
	{
		i = 1;
		while (!is_sorted(stacks->b_head) && size--)
		{
			if ((stacks->b_head->index >> i & 1) == 0)
				sb(stacks->b_head);
			else
				rb(&stacks->b_head, &stacks->b_tail);
			i++;
			temp = temp->next;
		}
		temp = temp->next;
	}
	while (stacks->b_head)
		pa(&stacks->a_head, &stacks->a_tail);
}

/**
 * handle the negative numbers case using index in and array
 */
void	radix(t_stack *stacks)
{
	int		size;
	int		i;
	t_node	*temp;

	printf("calling set_index\n");
	set_index(stacks);
	size = get_stack_size(stacks->a_head);
	temp = stacks->a_head;
	i = 0;
	while (!is_sorted(stacks->a_head))
	{
		while (!is_sorted(stacks->a_head) && size--)
		{
			if ((stacks->a_head->index >> i & 1) == 0)
				pb(stacks);
			else
				ra(&stacks->a_head, &stacks->a_tail);
			i++;
			temp = temp->next;
		}
		temp = temp->next;
		printf("calling sort_b\n");
		sort_b(stacks);
		printf("finished sort_b\n");
	}
}
