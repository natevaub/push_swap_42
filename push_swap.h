/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:42:24 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/06 17:15:58 by nvaubien         ###   ########.fr       */
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
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_global;

typedef struct s_moves {
	int	a_moves;
	int	b_moves;
}	t_moves;

typedef struct s_compute_helper
{
	int	greedy_a;
	int	greedy_b;
	int	greedy_total;
	int rotate_a;
	int	rotate_b;
	int	rotate_total;
	int	r_rotate_a;
	int	r_rotate_b;
	int	r_rotate_total;
	int	moves_a;
	int	moves_b;
	int	moves_a_abs;
	int	moves_b_abs;
	int	minb;
	int	maxb;
}	t_compute_helper;

/* --- helpers.c --- */
int 	stack_min_index(t_stack *stack);
int		stack_max_index(t_stack *stack);
int 	stack_min_value(t_stack *head);
int 	stack_max_value(t_stack *head);
int		iabs(int x);

/* --- helpers2.c --- */
int		find_elem_at_index(t_stack *head, int idx);
int 	find_index_of_element(t_stack *head, int val);
void	reset_best_moves(t_moves *moves);

/* --- push_swap.c --- */
int		args_count(char **input);
int		init_stacks_quote(t_global *ps, const char *arg_str);
int		init_stacks(t_global *ps, char **av, int ac);

/* --- error-management.c --- */
int		is_valid_input(char *str);
int		find_duplicate(t_stack *node);
void	error_msg(void);

/* --- swap-op.c --- */
void	sa(t_stack **head);
void	sb(t_stack **head);
void	ss(t_global *ps);

/* --- rotation-op.c --- */
void	ra(t_stack **head);
void	rb(t_stack **head);
void	ra_no_print(t_stack **head);
void	rb_no_print(t_stack **head);
void	rr(t_global *ps);

/* --- reverse-rotation-op.c --- */
void	rra(t_stack **head);
void	rrb(t_stack **head);
void	rra_no_print(t_stack **head);
void	rrb_no_print(t_stack **head);
void	rrr(t_global *ps);

/* --- push-op.c --- */
void	pa(t_global *ps);
void	pb(t_global *ps);

/* --- stacks-visualizer.c --- */
void	print_stack(t_global *ps);

/* --- linked-list-insert-del --- */
void	insert_at_head(t_stack **head, int new_value);
void	delete_at_head(t_stack **head);

/* --- sort-2-3-5.c --- */
void	sort2(t_global *ps);
void	sort3(t_global *ps);
void	sort5(t_global *ps);

/* --- helpers-sort-2-3-5.c --- */
void	top_greater_middle(t_global *ps);
void	top_less_middle(t_global *ps);
void	find_min_pb(t_global *ps);

/* --- utils1.c --- */
int		stack_size(t_stack **head);
int		is_sorted_a(t_stack **head, int size);
int		is_sorted_b(t_stack **head, int size);
int		stack_min_index(t_stack *head);

/* --- utils2.c --- */
int		bring_top_minimum_moves_a(int idx, t_global *ps);
int		bring_top_minimum_moves_b(int idx, t_global *ps);
void	bring_top_minimum_a(int op, t_global *ps);
void	bring_top_minimum_b(int op, t_global *ps);

/* --- utils3.c --- */
int		find_biggest_smaller_than(int number, t_stack *head);
int		find_smallest_bigger_than(int number, t_stack *head);
void	compute_operations(int a_idx, t_global *ps, t_moves *moves);

/* --- utils4.c --- */
int		min(int a, int b);
int		max(int a, int b);
void	magic_compute(int a_idx, int b_idx, t_global *ps, t_compute_helper *c);
void	magic_bring_top(int a_moves, int b_moves, t_global *ps);

/* --- big-sort.c --- */
void	big_sort_first_step(t_global *ps);
void	big_sort_second_step(t_global *ps);


#endif