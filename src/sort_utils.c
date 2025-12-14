/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:13:16 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/14 12:20:51 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_smallest(t_node *a)
{
	t_node	*smallest;
	t_node	*current;

	if (!a)
		return (NULL);
	smallest = a;
	current = a->next;
	while (current != a)
	{
		if (current->value < smallest->value)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}

t_node	*find_biggest(t_node *a)
{
	t_node	*biggest;
	t_node	*current;

	if (!a)
		return (NULL);
	biggest = a;
	current = a->next;
	while (current != a)
	{
		if (current->value > biggest->value)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}
