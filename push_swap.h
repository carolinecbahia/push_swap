/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:59:20 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/11 17:46:19 by ccavalca         ###   ########.fr       */
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
void	error_exit(t_node **a, char **temp_split);
void	free_stacks(t_node **stack_a, t_node **stack_b);
int		error_and_free_stack(t_node **stack);
int		print_error(t_node **stack);

//validations
void	parser(t_node **a, char **av_split);
long	ft_atol(char *str_nb);
int		check_syntax(char *str);
int		check_duplicate(t_node *stack, int n);
int		is_numeric(char *str);
int		is_sorted(t_node *stack);
void	init_stack(t_node **a, char *av);

//list utils
t_node	*create_node(int value);
void	stack_add_back(t_node **stack, t_node *new_node);
void	stack_add_front(t_node **stack, t_node *new_node);
int		get_stack_size(t_node *stack);
t_node	*get_last_node(t_node *stack);

//sort
void	sort_stack(t_node **a, t_node **b);
void	sort_two(t_node **a);
void	sort_three(t_node **a);
void	sort_five(t_node **a);
void	bubble_sort(t_node **stack);

//radix
void	*indexer(t_node *a);
void	radix_sort(t_node **a, t_node **b);

//commands
void	swap(t_node **stack);
void	rotate(t_node **stack);
void	reverse_rotate(t_node **stack);
void	push(t_node **src, t_node **dest);
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