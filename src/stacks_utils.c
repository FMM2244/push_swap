/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:43:52 by fmaaita           #+#    #+#             */
/*   Updated: 2025/02/19 13:43:54 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
// void	rrr(t_stack *stacks)
// {
// 	rra(&stacks->a_head, &stacks->a_tail);
// 	rrb(&stacks->b_head, &stacks->b_tail);
// }

void	pa_helper(t_stack *stack, t_node *temp)
{
	if (stack->a_head == stack->a_tail)
	{
		temp->next = stack->a_tail;
		stack->a_tail->pre = temp;
		stack->a_head = temp;
	}
	else
	{
		stack->a_head->pre = temp;
		temp->next = stack->a_head;
		stack->a_head = temp;
	}
}

void	stack_init_helper(t_stack *stacks)
{
	new_node(0, &stacks->a_head);
	stacks->a_tail = stacks->a_head;
	if (!stacks->a_head || !stacks->a_tail)
		return ;
}

void	pb_helper(t_stack *stack, t_node *temp)
{
	if (stack->b_head == stack->b_tail)
	{
		temp->next = stack->b_tail;
		stack->b_tail->pre = temp;
		stack->b_head = temp;
	}
	else
	{
		stack->b_head->pre = temp;
		temp->next = stack->b_head;
		stack->b_head = temp;
	}
}
