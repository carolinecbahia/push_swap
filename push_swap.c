/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:49:30 by ccavalca          #+#    #+#             */
/*   Updated: 2025/11/23 17:00:21 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parser(t_node *a)
{
	int	*array;
	
}

void	create_list(t_node a)
{

}

int	valid_args(t_node *a)
{
	int	*array;

	array = parser(a);
	while (a != NULL)
	{

	}
}

int	check_size(t_stack a)
{

}


int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc != 2)
		return ;
	stack_a = create_list(stack_a);
	if (valid_args(stack_a) == -1)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (check_size(stack_a) == 3)
		sort_three(stack_a);
	if (check_size(stack_a) == 5)
		sort_five(stack_a);
	else
		radix(stack_a, stack_b);
	return (0);
}
