/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:24:37 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/09 19:46:17 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_node **a, char **temp_split)
{
	free(*a);
	free(*temp_split);
	ft_printf("Error\n");
	exit(1);
}

void	free_stacks(t_node **stack_a, t_node **stack_b)
{
	free(*stack_a);
	free(*stack_b);
}

int	error_and_free_stack(t_node **stack)
{
	free(*stack);
	ft_printf("Error\n");
	return (-1);
}

int	print_error(t_node **stack)
{
	free(*stack);
	ft_printf("Error\n");
	return (-1);
}
