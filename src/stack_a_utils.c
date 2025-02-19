/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatima <fatima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:33:48 by fatima            #+#    #+#             */
/*   Updated: 2025/02/19 10:27:52 by fatima           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

/**
 * Swap the first 2 elements at the top of stack a.
 * Do nothing if there is only one or no elements.
 */
void	sa(t_node *a)
{
	int	temp;

	if (!a || !a->next)
		return ;
	temp = a->num;
	a->num = a->next->num;
	a->next->num = temp;
	
	temp = a->index;
	a->index = a->next->index;
	a->next->index = temp;
	ft_putendl_fd("sa", 1);
}

/**
 * Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
 */
void	pa(t_stack *stack)
{
	/* t_node	*temp; */
	/**/
	/* if (!(*b_head) || !b_head) */
	/* 	return ; */
	/* temp = *b_head; */
	/**/
	/* *b_head = (*b_head)->next; */
	/* (*b_head)->pre = NULL; */
	/**/
	/* temp->next = *a_head; */
	/* (*a_head)->pre = temp; */
	/* *a_head = temp; */
	/* ft_putendl_fd("pa", 1); */

	t_node	*temp;

	if (!stack->b_head)
		return ;

	temp = stack->b_head;

	stack->b_head = stack->b_head->next;
	if(stack->b_head)
	    stack->b_head->pre = NULL;


	temp->pre = NULL;
	temp->next = NULL;

	if(stack->a_head){
		if(stack->a_head == stack->a_tail){
			temp->next = stack->a_tail;
			stack->a_tail->pre = temp;
			stack->a_head = temp;
		} else {
			stack->a_head->pre = temp;
			temp->next = stack->a_head;
			stack->a_head = temp;
		}
	} else {
		stack->a_head = temp;
		stack->a_tail = temp;
	}

	ft_putendl_fd("pa", 1);
}

/**
 * Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 */
void	ra(t_node **a_head, t_node **a_tail)
{
	if (!(*a_head) || !(*a_head)->next)
		return ;
	if ((*a_head)->next == (*a_tail))
	{
		sa(*a_head);
		return ;
	}
	(*a_tail)->next = *a_head;
	(*a_head)->pre = *a_tail;
	*a_head = (*a_head)->next;
	*a_tail = (*a_tail)->next;
	(*a_head)->pre = NULL;
	(*a_tail)->next = NULL;
	ft_putendl_fd("ra", 1);
}

/**
 * Shift down all elements of stack a by 1.
 * The last element becomes the first one.
 */
void	rra(t_node **a_head, t_node **a_tail)
{
	if (!a_head || !(*a_head)->next)
		return ;
	(*a_tail)->next = *a_head;
	(*a_head)->pre = *a_tail;
	*a_head = (*a_head)->pre;
	*a_tail = (*a_tail)->pre;
	(*a_head)->pre = NULL;
	(*a_tail)->next = NULL;
	ft_putendl_fd("rra", 1);
}

/**
 * initialises stack a with the users input
 */
void	stack_a_init(t_stack *stacks, int ac, char **av)
{
	long	temp;
	t_node	*node;
	t_node	*prev_node;

	new_node(0, &stacks->a_head);
	stacks->a_tail = stacks->a_head;
	if (!stacks->a_head || !stacks->a_tail)
		return ;
	prev_node = NULL;
	temp = ft_atoi(av[--ac]);
	if (temp > INT_MAX || temp < INT_MIN)
		print_error();
	stacks->a_tail->num = temp;
	prev_node = stacks->a_tail;
	while (--ac)
	{
		temp = ft_atoi(av[ac]);
		if (temp > INT_MAX || temp < INT_MIN)
			print_error();
		node = NULL;
		new_node(temp, &node);
		node->next = prev_node;
		prev_node->pre = node;
		prev_node = node;
	}
	stacks->a_head = node;
}
