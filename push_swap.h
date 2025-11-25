/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:59:20 by ccavalca          #+#    #+#             */
/*   Updated: 2025/11/25 18:13:51 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"


//structs, lists
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

//cleanup and error
void	ft_free_stack(t_node **stack);
char	error_exit(t_node *stack, char **args);

//validations
void	parser(t_node **a);
void	create_list(t_node a);
int		valid_args(t_node *a);
int		check_size(t_node a);

//sort
void	sort_three(t_node **a);
void	sort_five(t_node **a);
void	bubble_sort(t_node **a);

//radix
void	*indexer(t_node **a);
void	radix(t_node **a, t_node **b);

//commands
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **b, t_node **a);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rr(t_node **a, t_node **b);
void	rrr(t_node **a, t_node **b);

#endif
