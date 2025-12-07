/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:18:04 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/02 22:33:46 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a)
{
	int		temp_value;
	int		temp_index;
	t_node	*head;
	t_node	*next;

	if (!a || !(*a) || !(*a)->next)
		return ;
	head = *a;
	next = head->next;
	temp_value = head->value;
	head->value = next->value;
	next->value = temp_value;
	temp_index = head->index;
	head->index = next->index;
	next->index = temp_index;
	ft_printf("sa\n");
}

void	pa(t_node **a, t_node **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	ra(t_node **a)
{
	if(!a || !(*a) || !(*a)->next)
		return ;
	*a = (*a)->next;
	ft_printf("ra\n");
}

void	rra(t_node **a)
{
	if (!a || !(*a) || (*a)->next == *a)
		return ;
	*a = (*a)->prev;
	ft_printf("rra\n");
}
