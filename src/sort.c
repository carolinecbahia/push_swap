/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:29:57 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/14 13:46:51 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **a)
{
	if ((*a)->next->value < (*a)->value)
		sa(a);
}

void	sort_three(t_node **a)
{
	t_node	*bigger;

	if (!a || !*a)
		return ;
	bigger = find_biggest(*a);
	if (*a == bigger)
		ra(a);
	else if ((*a)->next == bigger)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_five(t_node **a, t_node **b)
{
	t_node	*smaller;

	while (get_stack_size(*a) > 3)
	{
		smaller = find_smallest(*a);
		while (*a != smaller)
			ra(a);
		pb(b, a);
	}
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

void	sort_stack(t_node **a, t_node **b)
{
	int	size;

	size = get_stack_size(*a);
	if (size == 1)
		return ;
	else if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size > 3 && size <= 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}
