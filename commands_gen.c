/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_gen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:18:04 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/03 23:23:31 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push(t_node **src, t_node **dest)
{
    t_node  *node_to_move;

    if (!*src)
        return ;
    node_to_move = *src;
    if (node_to_move->next == node_to_move)
        *src = NULL;
    else 
    {
        *src = node_to_move->next;
        (*src)->prev = node_to_move->prev;
        node_to_move->prev->next = *src;
    }
    if (!dest)
    {
        *dest = node_to_move;
        node_to_move->next = node_to_move;
        node_to_move->prev = node_to_move;
    }
    else
    {
        node_to_move->next = *dest;
        node_to_move->prev = (*dest)->prev;
        (*dest)->prev->next = node_to_move;
        (*dest)->prev = node_to_move;
        *dest = node_to_move;
    }
}

void	ss(t_node **a, t_node **b)
{
	sa(*a);
	sb(*b);
}

void	rr(t_node **a, t_node **b)
{
	ra(*a);
	rb(*b);
}

void	rrr(t_node **a, t_node **b)
{
	rra(*a);
	rrb(*b);
}
