/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatima <fatima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 04:46:06 by fatima            #+#    #+#             */
/*   Updated: 2025/02/18 17:24:56 by fatima           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include "../includes/libft/libft.h"

typedef struct s_node
{
	u_int				num;
	struct s_node	*next;
	struct s_node	*pre;
}	t_node;

typedef struct s_stack
{
	t_node	*a_head;
	t_node	*a_tail;
	t_node	*b_head;
	t_node	*b_tail;
}	t_stack;


void	sa(t_node *a);
void	ra(t_node **a_head, t_node **a_tail);
void	rra(t_node **a_head, t_node **a_tail);
void	pa(t_stack *);
void	sb(t_node *b);
void	rb(t_node **b_head, t_node **b_tail);
void	rrb(t_node **b_head, t_node **b_tail);
void	pb(t_stack *);
void	ss(t_node *a, t_node *b);
void	rr(t_stack *stacks);
void	rrr(t_stack *stacks);
void	print_error(void);
void	stack_a_init(t_stack *stacks, int ac, char **av);
void	*new_node(int contents);
void	less_than_seven(t_stack *stacks, int length);
void	handle_three_items(t_stack *stacks);
void	radix(t_stack *stacks, int max);
bool	is_sorted(t_node *stack);
int		get_stack_size(t_node *head);
int		find_min(t_node *a_head, int *minimum);

#endif
