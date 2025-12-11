/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:33:17 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/11 16:55:48 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	t_node	*it;

	it = stack->value;
	if (!stack || !stack->next)
		return (1);
	while (stack)
	{
		if (it > it->next)
			return (1);
	}
	
}

void    init_stack(t_node **a, char *av)
{

}
