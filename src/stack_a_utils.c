/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatima <fatima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:33:48 by fatima            #+#    #+#             */
/*   Updated: 2025/02/11 23:00:41 by fatima           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

/**
 * Swap the first 2 elements at the top of stack a.
 * Do nothing if there is only one or no elements.
**/
void	sa(t_node *a)
{
	int	temp;

	if (!a || !a->next)
		return ;
	temp = a->num;
	a->num = a->next->num;
	a->next->num = temp;
}

/**
 * Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
**/
t_node	*pa(t_node *a, t_node *b)
{
	t_node	temp;

	if (!b)
		return ;
	temp.num = b->num;
	b = b->next;
	temp.next = &a;
	a->pre = &temp;
	b->pre = NULL;
	return (&temp);
}

/**
 * Shift up all elements of stack a by 1.
 * The first element becomes the last one.
**/
void	ra(t_node *a_head, t_node *a_tail)
{
	if (!a_head || !a_head->next)
		return ;
	a_tail->next = a_head;
	a_head->pre = a_tail;
	a_head = a_head->next;
	a_tail = a_tail->next;
	a_head->pre = NULL;
	a_tail->next = NULL;
}

/**
 * Shift down all elements of stack a by 1.
 * The last element becomes the first one.
**/
void	rra(t_node *a_head, t_node *a_tail)
{
	if (!a_head || !a_head->next)
		return ;
	a_tail->next = a_head;
	a_head->pre = a_tail;
	a_head = a_head->pre;
	a_tail = a_tail->pre;
	a_head->pre = NULL;
	a_tail->next = NULL;
}
