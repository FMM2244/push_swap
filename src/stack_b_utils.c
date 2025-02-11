/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatima <fatima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:35:12 by fatima            #+#    #+#             */
/*   Updated: 2025/02/11 23:03:34 by fatima           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

/**
 * Swap the first 2 elements at the top of stack b.
 * Do nothing if there is only one or no elements.
**/
void	sb(t_node *b)
{
	int	temp;

	if (!b || !b->next)
		return ;
	temp = b->num;
	b->num = b->next->num;
	b->next->num = temp;
}

/**
 * Take the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty.
**/
t_node	*pb(t_node *b, t_node *a)
{
	t_node	temp;

	if (!b)
		return ;
	temp.num = a->num;
	a = a->next;
	temp.next = &b;
	b->pre = &temp;
	a->pre = NULL;
	return (&temp);
}

/**
 * Shift up all elements of stack b by 1.
 * The first element becomes the last one.
**/
void	rb(t_node *b_head, t_node *b_tail)
{
	if (!b_head || !b_head->next)
		return ;
	b_tail->next = b_head;
	b_head->pre = b_tail;
	b_head = b_head->next;
	b_tail = b_tail->next;
	b_head->pre = NULL;
	b_tail->next = NULL;
}

/**
 * Shift down all elements of stack b by 1.
 * The last element becomes the first one.
**/
void	rrb(t_node *b_head, t_node *b_tail)
{
	if (!b_head || !b_head->next)
		return ;
	b_tail->next = b_head;
	b_head->pre = b_tail;
	b_head = b_head->pre;
	b_tail = b_tail->pre;
	b_head->pre = NULL;
	b_tail->next = NULL;
}
