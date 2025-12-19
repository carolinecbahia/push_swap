/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:49:18 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/14 14:24:27 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_syntax(char *str)
{
	if (!is_numeric(str))
		return (0);
	return (1);
}

int	check_duplicate(t_node *stack)
{
	t_node	*current;
	t_node	*compare;

	if (!stack)
		return (0);
	current = stack;
	while (1)
	{
		compare = stack;
		while (1)
		{
			if (compare->value == current->value && compare != current)
				return (1);
			compare = compare->next;
			if (compare == stack)
				break ;
		}
		current = current->next;
		if (current == stack)
			break ;
	}
	return (0);
}

static long	ft_atol_push(const char *str, t_node **a, char **matrix)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)
	{
		error_exit(a, matrix);
	}
	return (res * sign);
}

void	parser(t_node **a, char **av_split)
{
	char	**temp;
	int		i;
	int		j;
	long	val;

	i = 0;
	while (av_split[i])
	{
		if (!av_split[i] || av_split[i][0] == '\0')
			error_exit(a, NULL);
		temp = ft_split(av_split[i], ' ');
		if (!temp)
			error_exit(a, NULL);
		j = 0;
		while (temp[j])
		{
			if (check_syntax(temp[j]) == 0)
				error_exit(a, temp);
			val = ft_atol_push(temp[j], a, temp);
			stack_add_back(a, create_node((int)val));
			j++;
		}
		free_matrix(temp);
		i++;
	}
}
