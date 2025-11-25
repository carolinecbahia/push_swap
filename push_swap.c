/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:49:30 by ccavalca          #+#    #+#             */
/*   Updated: 2025/11/25 17:40:45 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parser(t_node **a)
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

int	check_size(t_node a)
{

}


int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || (argc == 2 && argv[1][0]))
		return (1);
	create_list(&stack_a, argv + 1, argc == 2);
	if (check_args(stack_a))
	{
		ft_free_stack(&stack_a);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (check_size(stack_a) == 3)
		sort_three(stack_a);
	else if (check_size(stack_a) == 5)
		sort_five(stack_a);
	else
		radix(stack_a, stack_b);
	free_stack(stack_a, stack_b);
	return (0);
}
