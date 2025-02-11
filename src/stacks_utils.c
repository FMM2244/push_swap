/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatima <fatima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:41:11 by fatima            #+#    #+#             */
/*   Updated: 2025/02/11 22:59:27 by fatima           ###   ########.fr       */
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
void	rr(t_node *a_head, t_node *a_tail, t_node *b_head, t_node *b_tail)
{
	ra(a_head, a_tail);
	rb(b_head, b_tail);
}

/**
 * rra and rrb at the same time.
**/
void	rrr(t_node *a_head, t_node *a_tail, t_node *b_head, t_node *b_tail)
{
	rra(a_head, a_tail);
	rrb(b_head, b_tail);
}
