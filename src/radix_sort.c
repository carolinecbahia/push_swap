/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:50:46 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/19 18:58:48 by ccavalca         ###   ########.fr       */
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

void	radix_sort(t_node **a, t_node **b)
{
	int		i;
	int		max_bits;

	max_bits = get_max_bits(a);
	i = 0;
	while (i < max_bits)
	{
		sort_bit_adaptive(a, b, i);
		while (get_stack_size(*b) > 0)
			pa(a, b);
		if (is_sorted(*a))
			break ;
		i++;
	}
}
