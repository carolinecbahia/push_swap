/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:33:17 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/19 18:28:06 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	t_node	*current;

	current = stack;
	while (current->next != stack)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	init_stack(t_node **a, char **av)
{
	parser(a, av);
	if (!*a)
		return ;
	if (check_duplicate(*a) != 0)
	{
		print_error(a);
		exit(1);
	}
	if (is_sorted(*a) != 0)
	{
		free_stacks(a, NULL);
		exit(0);
	}
}
