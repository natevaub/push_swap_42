/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:22:04 by nvaubien          #+#    #+#             */
/*   Updated: 2023/03/10 14:54:30 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <string.h>
# include "libs/libft/libft.h"
# include "libs/ftprintf/ft_printf.h"

# define INT_MAX "2147483647"
# define INT_MIN "-2147483648"

/* Structs */
typedef struct s_stack {
	int value;
	struct s_stack *next;
}	t_stack;

typedef struct s_global {
	t_stack *stack_a;
	t_stack *stack_b;
}	t_global;

/* Fonctions */
void	insert_at_head(t_stack **head, int new_value);
void	delete_at_head(t_stack **head);
int		find_duplicate(t_stack *node);
void	print_stack(t_global *ps);
void	error_msg(void);
int		is_valid_input(char *str);
int		main(int ac, char **av);

/* Push Swap Operations */
void	sa(t_stack **head);
void	sb(t_stack **head);
void	ss(t_global *ps);
void	pa(t_global *ps);
void	pb(t_global *ps);
void	ra(t_stack **head);
void	rb(t_stack **head);
void	rra(t_stack **head);
void	rrb(t_stack **head);
void	rrr(t_global *ps);

void	deallocate(t_stack **head);

int		stack_size(t_stack **head);
int		is_sorted(t_stack **head);
int		stack_min(t_stack **head);



void	sort3(t_global *ps);
void	sort5(t_global *ps);
void	top_greater_middle(t_global *ps);
void	top_less_middle(t_global *ps);
void	find_min_pb(t_global *ps);

#endif

