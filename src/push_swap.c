/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatima <fatima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 04:41:26 by fatima            #+#    #+#             */
/*   Updated: 2025/02/09 01:38:05 by fatima           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"
#include <stdio.h>

/** 
 * errors to handle: 
 * follow this link 
 * https://42-cursus.gitbook.io/guide/rank-02/push_swap/building-the-thing
*/
int	error_handling(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
			av[i][j++] = 'a';
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{

	if (ac == 2)
	{
		error_handling(av);
	}
	return (0);
}
