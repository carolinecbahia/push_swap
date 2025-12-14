/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:24:37 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/14 14:26:45 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_stack_nodes(t_node **stack)
{
	t_node	*current;
	t_node	*temp;
	t_node	*head;

	if (!stack || !*stack)
		return ;
	head = *stack;
	current = *stack;
	while (1)
	{
		temp = current->next;
		free(current);
		if (temp == head)
			break ;
		current = temp;
	}
	*stack = NULL;
}

void	free_stacks(t_node **stack_a, t_node **stack_b)
{
	free_stack_nodes(stack_a);
	free_stack_nodes(stack_b);
}

void	error_exit(t_node **a, char **temp_split)
{
	if (temp_split)
		free_matrix(temp_split);
	if (a)
		free_stacks(a, NULL);
	write(2, "Error\n", 6);
	exit(1);
}

int	print_error(t_node **stack)
{
	free_stacks(stack, NULL);
	write(2, "Error\n", 6);
	return (-1);
}
