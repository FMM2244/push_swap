/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatima <fatima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 03:42:14 by fatima            #+#    #+#             */
/*   Updated: 2025/02/18 22:40:17 by fatima           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

/**
 * finds the smallest value bigger than privous_min
 */
int	find_next_min(/* t_node *head, int previous_min */)
{
	int	next_minimum;

	while (head)
	{
		if (head->num < next_minimum && head->num > previous_min)
			next_minimum = head->num;
		head = head->next;
	}
	return (next_minimum);
	return 0;
}

/**
 * sets the index of the item to the appropriate index for it
 */
void	set_index(/* t_stack *stacks */)
{
	int		index;
	int		previous_min;
	t_node	*temp;

	temp = stacks->a_head;
	while (temp)
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
	// printf("\t%d\n", i);
	return (i);
}

void print_stack(t_stack stack){

	printf("====================\n");
	t_node *temp;
	temp = stack.a_head;
	while (temp)
	{
		printf(" %d", temp->num - INT_MAX - 1);
		temp = temp->next;
	}
	printf("\n---\n");
	temp = stack.b_head;
	while (temp)
	{
		printf(" %d", temp->num - INT_MAX - 1);
		temp = temp->next;
	}
	printf("\n====================\n");

}

/**
 * handle the negative numbers case using index in and array
 */
void	radix(t_stack *stacks, int max)
{
	int	i;
	int	size;
	i = 0;
	(void)max;
	while (i < 32)
	{
		size = get_stack_size(stacks->a_head);
		while (size--)
		{
			if ((stacks->a_head->num >> i & 1) == 0)
				pb(stacks);
			else
				ra(&stacks->a_head, &stacks->a_tail);
			/* print_stack(*stacks); */
		}
		i++;
		while(stacks->b_head){
			pa(stacks);
		}
	}
}
