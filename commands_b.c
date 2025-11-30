/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:18:04 by ccavalca          #+#    #+#             */
/*   Updated: 2025/11/30 16:01:29 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_node **b)
{
	int		temp_value;
	int		temp_index;
	t_node	*head;
	t_node	*next;

	if (!b || !(*b) || !(*b)->next)
		return ;
	head = *b;
	next = head->next;
	temp_value = head->value;
	head->value = next->value;
	next->value = temp_value;
	temp_index = head->index;
	head->index = next->index;
	next->index = temp_index;
	ft_printf("sb\n");
}

void	pb(t_node **b, t_node **a)
{
	int		temp_value;
	int		temp_index;
	t_node	*b_head;
	t_node	*a_head;

	if (!b || !a || !(*b) || !(*a))
		return ;
	b_head = *b;
	a_head = *a;
	temp_value = b_head->value;
	b_head->value = a_head->value;
	a_head->value = temp_value;
	temp_index = b_head->index;
	b_head->index = a_head->index;
	a_head->index = temp_index;
	ft_printf("pb\n");
}

// void	rb(t_node **b)
// {
// 	int		temp_value;
// 	int		temp_index;
// 	t_node	*head;
// 	t_node	*last;

// 	head = *b;
// 	last = head->prev;
// 	last->value = head->value;
// 	last->index = head->index;
// 	ft_printf("rb\n");
// }
