/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:59:20 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/14 15:00:11 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

//structs, lists
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

//cleanup and error
void	error_exit(t_node **a, char **temp_split);
void	free_stacks(t_node **stack_a, t_node **stack_b);
void	free_stack_nodes(t_node **stack);
int		print_error(t_node **stack);
void	free_matrix(char **matrix);

//validations
void	parser(t_node **a, char **av_split);
int		check_syntax(char *str);
int		check_duplicate(t_node *stack);
int		is_numeric(char *str);
void	init_stack(t_node **a, char **av);

//list utils
t_node	*create_node(int value);
void	stack_add_back(t_node **stack, t_node *new);
void	stack_add_front(t_node **stack, t_node *new);
int		get_stack_size(t_node *stack);

//sort and utils
t_node	*find_smallest(t_node *a);
t_node	*find_biggest(t_node *a);
void	sort_two(t_node **a);
void	sort_three(t_node **a);
void	sort_five(t_node **a, t_node **b);
void	sort_stack(t_node **a, t_node **b);

//radix sort
void	indexer(t_node **a);
void	radix_sort(t_node **a, t_node **b);

//commands
void	swap(t_node **stack);
void	rotate(t_node **stack);
void	reverse_rotate(t_node **stack);
void	push(t_node **stack, t_node *node_to_add);
t_node	*pop(t_node **stack);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **b, t_node **a);
void	ra(t_node **a);
void	rb(t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rrr(t_node **a, t_node **b);

#endif