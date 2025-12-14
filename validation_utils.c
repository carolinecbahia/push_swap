/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:49:18 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/13 13:48:12 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parser(t_node **a, char **av_split)
{
	char **temp;
	int i;
	int j;

	i = 0;
	while(av_split[i])
	{
		temp = ft_split(av_split[i], ' ');
		if (!temp)
			error_exit(a, NULL);
		j = 0;
		while (temp[j])
		{
			stack_add_back(a, create_node(ft_atoi(temp[j])));
			j++;
		}
		free(temp);
		i++;
	}
}

long    ft_atol(char *nptr)
{
	long    nb;
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	nb = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}

int  check_syntax(char *str)
{

}

int  check_duplicate(t_node *stack, int n)
{
	
}

int     is_numeric(char *str)
{

}
