/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:18:04 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/13 13:42:20 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	pa(t_node **a, t_node **b)
{
	t_node	*node;
	
	node = pop(b);
	if (node)
		push(a, node);
	ft_printf("pa\n");
}

void	ra(t_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rra(t_node **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}
