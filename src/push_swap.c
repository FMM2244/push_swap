/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatima <fatima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 04:41:26 by fatima            #+#    #+#             */
/*   Updated: 2025/02/13 01:40:57 by fatima           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"
#include <stdio.h>

void	print_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

/** 
 * errors to handle: 
 * follow this link 
 * https://42-cursus.gitbook.io/guide/rank-02/push_swap/building-the-thing
*/
void	error_handling(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 && (av[i][j] == '-' || av[i][j] == '+'))
				j++;
			if (av[i][j] < '0' || av[i][j] > '9')
				print_error();
			j++;
		}
		if (j > 11)
			print_error();
	}
}

void	*new_node(int contents)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->num = contents;
	new->next = NULL;
	new->pre = NULL;
	return (new);
}

int	stack_a_init(t_node **head, t_node *tail, int ac, char **av)
{
	long	temp;
	t_node	*node;
	t_node	*prev_node;

	prev_node = NULL;
	temp = ft_atoi(av[--ac]);
	if (temp > INT_MAX || temp < INT_MIN)
		print_error();
	tail->num = temp;
	prev_node = tail;
	while (--ac)
	{
		temp = ft_atoi(av[ac]);
		if (temp > INT_MAX || temp < INT_MIN)
			print_error();

		node = new_node(temp);
		node->next = prev_node;
		prev_node->pre = node;
		prev_node = node;
	}
	*head = node;
	return (1);
}

int	main(int ac, char **av)
{
	t_node	*a_head;
	t_node	*a_tail;
	// t_node	*b_head;
	// t_node	*b_tail;

	a_head = new_node(0);
	a_tail = new_node(0);
	if (ac == 1)
		return (0);
	error_handling(av);
	stack_a_init(&a_head, a_tail, ac, av);
	while (a_head)
	{
		printf("%d\n", a_head->num);
		a_head = a_head->next;
	}
	return (0);
}
