/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatima <fatima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 04:46:06 by fatima            #+#    #+#             */
/*   Updated: 2025/02/13 00:02:15 by fatima           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include "../includes/libft/libft.h"

typedef struct s_node
{
	int				num;
	struct s_node	*next;
	struct s_node	*pre;
}	t_node;

void	sa(t_node *a);
void	ra(t_node *a_head, t_node *a_tail);
void	rra(t_node *a_head, t_node *a_tail);
void	pa(t_node *a, t_node *b);
void	sb(t_node *b);
void	rb(t_node *b_head, t_node *b_tail);
void	rrb(t_node *b_head, t_node *b_tail);
void	pb(t_node *b, t_node *a);
void	ss(t_node *a, t_node *b);
void	rr(t_node *a_head, t_node *a_tail, t_node *b_head, t_node *b_tail);
void	rrr(t_node *a_head, t_node *a_tail, t_node *b_head, t_node *b_tail);

#endif
