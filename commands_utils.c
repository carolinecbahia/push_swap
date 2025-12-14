/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:28:50 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/13 21:23:17 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop(t_node **stack)
{
	t_node	*node_to_remove;
	
	if (!*stack)
		return (NULL);
	node_to_remove = *stack;
	if (node_to_remove->next == node_to_remove)
		*stack = NULL;
	else
	{
		*stack = node_to_remove->next;
		(*stack)->prev = node_to_remove->prev;
		node_to_remove->prev->next = *stack;
	}
	node_to_remove->next = NULL;
	node_to_remove->prev = NULL;
	return (node_to_remove);
}

void	push(t_node **stack, t_node *node_to_add)
{
	if (!node_to_add)
		return ;
	if (!*stack)
	{
		*stack = node_to_add;
		node_to_add->next = node_to_add;
		node_to_add->prev = node_to_add;
	}
	else
	{
		node_to_add->next = *stack;
		node_to_add->prev = (*stack)->prev;
		(*stack)->prev->next = node_to_add;
		(*stack)->prev = node_to_add;
		*stack = node_to_add;
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
	*stack = (*stack)->prev;
}
