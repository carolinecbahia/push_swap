/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:18:04 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/02 22:32:25 by ccavalca         ###   ########.fr       */
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
	push(a, b);
	ft_printf("pb\n");
}

void	rb(t_node **b)
{
	if(!b || !(*b) || !(*b)->next)
		return ;
	*b = (*b)->next;
	ft_printf("rb\n");
}

void	rra(t_node **b)
{
	if (!b || !(*b) || !(*b)->prev)
		return ;
	*b = (*b)->prev;
	ft_printf("rrb\n");
}
