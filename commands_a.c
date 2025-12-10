/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:18:04 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/09 19:53:24 by ccavalca         ###   ########.fr       */
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
	push(b, a);
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
