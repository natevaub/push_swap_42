/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:21:39 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/07 15:30:08 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	magic_compute(int a_idx, int b_idx, t_global *ps, t_compute_helper *c)
{
	c->greedy_a = bring_top_minimum_moves_a(a_idx, ps);
	c->greedy_b = bring_top_minimum_moves_b(b_idx, ps);
	c->greedy_total = iabs(c->greedy_a) + iabs(c->greedy_b);
	c->rotate_a = a_idx;
	c->rotate_b = b_idx;
	c->rte_tot = max(c->rotate_a, c->rotate_b);
	c->r_rotate_a = -(stack_size(&ps->stack_a) - a_idx);
	c->r_rotate_b = -(stack_size(&ps->stack_b) - b_idx);
	c->r_rte_tot = max(iabs(c->r_rotate_a), iabs(c->r_rotate_b));
	if (c->greedy_total <= c->rte_tot && c->greedy_total <= c->r_rte_tot)
	{
		c->moves_a = c->greedy_a;
		c->moves_b = c->greedy_b;
	}
	else if (c->rte_tot <= c->greedy_total && c->rte_tot <= c->r_rte_tot)
	{
		c->moves_a = c->rotate_a;
		c->moves_b = c->rotate_b;
	}
	else
	{
		c->moves_a = c->r_rotate_a;
		c->moves_b = c->r_rotate_b;
	}
}

void	magic_bring_top(int a_moves, int b_moves, t_global *ps)
{
	t_compute_helper	c;
	int					sign;
	int					min_v;
	int					max_v;
	int					i;

	sign = a_moves * b_moves;
	i = -1;
	if (sign > 0)
	{
		c.moves_a_abs = iabs(a_moves);
		c.moves_b_abs = iabs(b_moves);
		min_v = min(c.moves_a_abs, c.moves_b_abs);
		max_v = max(c.moves_a_abs, c.moves_b_abs) - min_v;
		while (++i < min_v)
			handle_sim_rot(a_moves, ps);
		i = -1;
		while (++i < max_v)
			handle_base_rot(a_moves, c.moves_a_abs, c.moves_b_abs, ps);
	}
	else
	{
		bring_top_minimum_a(a_moves, ps);
		bring_top_minimum_b(b_moves, ps);
	}
}

void	handle_sim_rot(int a, t_global *ps)
{
	if (a > 0)
		rr(ps);
	else
		rrr(ps);
}

void	handle_base_rot(int a, int abs_a, int abs_b, t_global *ps)
{
	if (a > 0)
	{
		if (abs_a > abs_b)
			ra(&ps->stack_a);
		else
			rb(&ps->stack_b);
	}
	else
	{
		if (abs_a > abs_b)
			rra(&ps->stack_a);
		else
			rrb(&ps->stack_b);
	}
}
