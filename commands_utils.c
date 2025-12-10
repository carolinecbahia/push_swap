/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:28:50 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/09 19:53:52 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **src, t_node **dest)
{
	t_node	*node_to_move;

	if (!*src)
		return ;
	node_to_move = *src;
	if (node_to_move->next == node_to_move)
		*src = NULL;
	else
	{
		*src = node_to_move->next;
		(*src)->prev = node_to_move->prev;
		node_to_move->prev->next = *src;
	}
	if (!dest)
	{
		*dest = node_to_move;
		node_to_move->next = node_to_move;
		node_to_move->prev = node_to_move;
	}
	else
	{
		node_to_move->next = *dest;
		node_to_move->prev = (*dest)->prev;
		(*dest)->prev->next = node_to_move;
		(*dest)->prev = node_to_move;
		*dest = node_to_move;
	}
}

void	swap(t_node **stack)
{
	int		temp_value;
	int		temp_index;
	t_node	*head;
	t_node	*next;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	head = *stack;
	next = head->next;
	temp_value = head->value;
	head->value = next->value;
	next->value = temp_value;
	temp_index = head->index;
	head->index = next->index;
	next->index = temp_index;
}

void	rotate(t_node **stack)
{
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
}

void	reverse_rotate(t_node **stack)
{
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
}
