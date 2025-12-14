/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:05:11 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/13 21:40:18 by ccavalca         ###   ########.fr       */
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

void	stack_add_back(t_node **stack, t_node *new)
{
	 if (!*stack)
    {
        *stack = new;
        new->next = new;
        new->prev = new;
    }
    else
    {
        new->next = *stack;
        new->prev = (*stack)->prev;
        (*stack)->prev->next = new;
        (*stack)->prev = new;
    }
}

void	stack_add_front(t_node **stack, t_node *new)
{
	if (!*stack)
    {
        *stack = new;
        new->prev = new;
        new->next = new;
    }
    else
    {
        new->prev = *stack;
        new->next = (*stack)->prev;
        (*stack)->next->prev = new;
        (*stack)->next = new;
    }
}

int	get_stack_size(t_node *stack)
{
	int	i;
	t_node	*current;

	if (!stack)
		return (0);
	current = stack->next;
	i = 1;
	while (current != stack)
	{
		i++;
		current = current->next;
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
