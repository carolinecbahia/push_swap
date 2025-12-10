/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:18:04 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/09 19:53:39 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	pb(t_node **b, t_node **a)
{
	push(a, b);
	ft_printf("pb\n");
}

void	rb(t_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rra(t_node **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}
