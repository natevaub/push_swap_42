/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big-sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:58:45 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/11 17:39:15 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	big_sort_initial_push(t_global *ps)
{
	pb(ps);
	pb(ps);
}

void	big_sort_first_step(t_global *ps)
{
	int		x;
	t_moves	best_moves;
	t_moves	curr_moves;

	x = 0;
	best_moves = (t_moves){1073741823, 1073741823, 2147483647};
	big_sort_initial_push(ps);
	while (stack_size(&ps->stack_a) > 3)
	{
		while (x < stack_size(&ps->stack_a))
		{
			compute_operations(x, ps, &curr_moves);
			if (curr_moves.tot_moves < best_moves.tot_moves)
				best_moves = (t_moves){curr_moves.a_moves, curr_moves.b_moves,
					curr_moves.tot_moves};
			x++;
		}
		x = 0;
		magic_bring_top(best_moves.a_moves, best_moves.b_moves, ps);
		pb(ps);
		best_moves = (t_moves){1073741823, 1073741823, 2147483647};
	}
	sort3(ps);
}

void	big_sort_second_step(t_global *ps)
{
	t_compute_helper	c;
	t_moves				moves;
	int					b_elem;
	int					temp;

	while (stack_size(&ps->stack_b) > 0)
	{
		c.mina = stack_min_value(ps->stack_a);
		c.i_mina = find_index_of_element(ps->stack_a, c.mina);
		c.maxa = stack_max_value(ps->stack_a);
		c.i_maxa = find_index_of_element(ps->stack_a, c.maxa);
		if (ps->stack_b->value < c.mina || ps->stack_b->value > c.maxa)
			bring_top_minimum_push(c.i_mina, ps);
		else
		{
			b_elem = ps->stack_b->value;
			temp = find_smallest_bigger_than(b_elem, ps->stack_a);
			moves.a_moves = bring_top_minimum_moves_a(temp, ps);
			bring_top_minimum_push(moves.a_moves, ps);
		}
	}
	c.i_mina = stack_min_index(ps->stack_a);
	moves.a_moves = bring_top_minimum_moves_a(c.i_mina, ps);
	bring_top_minimum_a(moves.a_moves, ps);
}

void	bring_top_minimum_push(int op, t_global *ps)
{
	bring_top_minimum_a(op, ps);
	pa(ps);
}

void	big_sort(t_global *ps)
{
	if (is_sorted_a(&ps->stack_a, stack_size(&ps->stack_a)) == 1)
		return ;
	big_sort_first_step(ps);
	big_sort_second_step(ps);
}
