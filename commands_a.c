/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:18:04 by ccavalca          #+#    #+#             */
/*   Updated: 2025/11/30 16:01:36 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a)
{
	int		temp_value;
	int		temp_index;
	t_node	*head;
	t_node	*next;

	if (!a || !(*a) || !(*a)->next)
		return ;
	head = *a;
	next = head->next;
	temp_value = head->value;
	head->value = next->value;
	next->value = temp_value;
	temp_index = head->index;
	head->index = next->index;
	next->index = temp_index;
	ft_printf("sa\n");
}

void	pa(t_node **a, t_node **b)
{
	int		temp_value;
	int		temp_index;
	t_node	*a_head;
	t_node	*b_head;

	if (!a || !b || !(*a) || !(*b))
		return ;
	a_head = *a;
	b_head = *b;
	temp_value = a_head->value;
	a_head->value = b_head->value;
	b_head->value = temp_value;
	temp_index = a_head->index;
	a_head->index = b_head->index;
	b_head->index = temp_index;
	ft_printf("pa\n");
}

// void	ra(t_node **a)
// {
// 	int		temp_value;
// 	int		temp_index;
// 	t_node	*head;
// 	t_node	*last;

// 	head = *a;
// 	last = head->prev;
// 	last->value = head->value;
// 	last->index = head->index;
// 	ft_printf("ra\n");
// }

// void	rra(t_node **a)
// {
// 	int		temp_value;
// 	int		temp_index;
// 	t_node	*head;
// 	t_node	*last;

// 	head = *a;
// 	last = head->prev;
// 	head->value = last->value;
// 	head->index = last->index;
// 	ft_printf("rra\n");
// }
