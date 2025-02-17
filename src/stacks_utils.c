/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatima <fatima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:41:11 by fatima            #+#    #+#             */
/*   Updated: 2025/02/17 12:43:42 by fatima           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

/**
 * sa and sb at the same time.
**/
void	ss(t_node *a, t_node *b)
{
	sa(a);
	sb(b);
}

/**
 * ra and rb at the same time.
**/
void	rr(t_stack *stacks)
{
	ra(&stacks->a_head, &stacks->a_tail);
	rb(&stacks->b_head, &stacks->b_tail);
}

/**
 * rra and rrb at the same time.
**/
void	rrr(t_stack *stacks)
{
	rra(&stacks->a_head, &stacks->a_tail);
	rrb(&stacks->b_head, &stacks->b_tail);
}
