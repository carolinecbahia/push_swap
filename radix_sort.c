/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:50:46 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/13 14:28:06 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_list(t_node **a)
{
	t_node	*lst_cpy;
	int *tmp_arr;
	int i;
	int j;

	if (!*a)
		return (NULL);
	tmp_arr = (int *)malloc(sizeof lst_cpy);
	lst_cpy = *a;
	i = 0;
	while(lst_cpy)
	{
		tmp_arr[i] = lst_cpy->value;
		lst_cpy = lst_cpy->next;
		i++;
	}
	tmp_arr[i] = NULL;
	return (tmp_arr);
}

int	*sorter(t_node **a, int *arr_a)
{
    int i;
	int temp;
	t_node	*ptr1;
	t_node	*ptr2;

	if (!a)
		return ;
	ptr1 = *a;
	ptr2 = (*a)->next;
	while (a)
	{
		if (ptr1->value > ptr2->value)
		{
			temp = ptr1->value;
			ptr1->value = ptr2->value;
			ptr2->value = temp;
		}
		i++;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
}

void	indexer(t_node **a)
{
	
}

void	radix_sort(t_node **a, t_node **b)
{

}