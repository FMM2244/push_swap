/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatima <fatima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 00:14:10 by fatima            #+#    #+#             */
/*   Updated: 2025/02/19 02:11:52 by fatima           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	free_all(t_stack *stacks)
{
	t_node	*t1;
	t_node	*t2;

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
