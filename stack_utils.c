/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:05:11 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/11 17:46:36 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	stack_add_back(t_node **stack, t_node *new_node)
{
	if (!stack || !new_node)
		return ;
	new_node = create_node(new_node->value);
	(*stack)->prev->value = new_node->value;
}

void	stack_add_front(t_node **stack, t_node *new_node)
{

}

int	get_stack_size(t_node *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack->next != NULL)
	{
		i++;
	}
	return (i);
}

t_node	*get_last_node(t_node *stack)
{
	t_node	*tail;

	if (!stack)
		return (NULL);
	while (stack->next != NULL)
	{
		tail = stack->next;
	}
	return (tail);
}
