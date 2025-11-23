/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:59:20 by ccavalca          #+#    #+#             */
/*   Updated: 2025/11/23 16:43:17 by ccavalca         ###   ########.fr       */
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
	int			value;
	int			index;
	t_node		*next;
	t_node		*prev;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_stack	*first;
	t_stack	*last;
}	t_stack;

//sort utils

//commands


#endif
