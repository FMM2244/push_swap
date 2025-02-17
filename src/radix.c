/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatima <fatima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 03:42:14 by fatima            #+#    #+#             */
/*   Updated: 2025/02/17 16:37:38 by fatima           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

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

void	sort_b(t_stack *stacks)
{
	int	size;
	int	i;

	size = get_stack_size(stacks->b_head);
	while (!is_sorted(stacks->b_head))
	{
		i = 1;
		while (!is_sorted(stacks->b_head) && size--)
		{
			if ((stacks->b_head->num >> i & 1) == 0)
				sb(stacks->b_head);
			else
				rb(&stacks->b_head, &stacks->b_tail);
			i++;
		}
	}
	while (stacks->b_head)
		pa(stacks);
}

/**
 * handle the negative numbers case using index in and array
 */
void	radix(t_stack *stacks)
{
	int	size;
	int	i;

	size = get_stack_size(stacks->a_head);
	i = 0;
	while (!is_sorted(stacks->a_head))
	{
		while (!is_sorted(stacks->a_head) && size--)
		{
			if ((stacks->a_head->num >> i & 1) == 0)
				pb(stacks);
			else
				ra(&stacks->a_head, &stacks->a_tail);
			i++;
		}
		sort_b(stacks);
	}
}
