/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:50:46 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/14 13:43:48 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexer(t_node **a)
{
	int		counter;
	t_node	*current;
	t_node	*compare;

	if (!*a)
		return ;
	current = *a;
	while (1)
	{
		counter = 0;
		compare = *a;
		while (1)
		{
			if (compare->value < current->value)
				counter++;
			compare = compare->next;
			if (compare == *a)
				break ;
		}
		current->index = counter;
		current = current->next;
		if (current == *a)
			break ;
	}
}

static int	get_max_bits(t_node **stack)
{
	t_node	*current;
	int		max;
	int		max_bits;

	current = *stack;
	max = current->index;
	while (current->next != *stack)
	{
		current = current->next;
		if (current->index > max)
			max = current->index;
	}
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_node **a, t_node **b)
{
	int		i;
	int		size;
	int		max_bits;

	max_bits = get_max_bits(a);
	i = 0;
	while (i < max_bits)
	{
		size = get_stack_size(*a);
		while (size > 0)
		{
			if (((*a)->index >> i) & 1)
				ra(a);
			else
				pb(b, a);
			size--;
		}
		while (get_stack_size(*b) > 0)
			pa(a, b);
		i++;
	}
}
