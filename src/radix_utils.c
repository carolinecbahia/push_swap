/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:37:37 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/19 18:45:38 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_bit_zeros(t_node **a, int bit)
{
	int		count;
	t_node	*curr;

	count = 0;
	curr = *a;
	while (1)
	{
		if (((curr->index >> bit) & 1) == 0)
			count++;
		curr = curr->next;
		if (curr == *a)
			break ;
	}
	return (count);
}

int	get_max_bits(t_node **stack)
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

void	sort_bit_adaptive(t_node **a, t_node **b, int bit)
{
	int	size;

	size = get_stack_size(*a);
	while (size > 0)
	{
		if ((((*a)->index >> bit) & 1) == 0)
			pb(b, a);
		else
			ra(a);
		size--;
	}
}
