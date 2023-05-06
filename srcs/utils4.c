/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:21:39 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/06 18:24:11 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		min(int a, int b)
{
	if (a < b)
		return (a);
	else if (a > b)
		return (b);
	else
		return (a);
}

int		max(int a, int b)
{
	if (a < b)
		return (b);
	else if (a > b)
		return (a);
	else
		return (a);
}

void	magic_compute(int a_idx, int b_idx, t_global *ps, t_compute_helper *c)
{
	// t_compute_helper	c;

	c->greedy_a = bring_top_minimum_moves_a(a_idx, ps);
	c->greedy_b = bring_top_minimum_moves_b(b_idx, ps);
	c->greedy_total = iabs(c->greedy_a) + iabs(c->greedy_b);
	// ft_printf("c.greedy a = %d , c.greedy b = %d\n", c->greedy_a, c->greedy_b);
	c->rotate_a = a_idx;
	c->rotate_b = b_idx;
	c->rotate_total = max(c->rotate_a, c->rotate_b);
	// ft_printf("c.rotate a = %d , c.rotate b = %d\n", c->rotate_a, c->rotate_b);
	c->r_rotate_a = -(stack_size(&ps->stack_a) - a_idx);
	c->r_rotate_b = -(stack_size(&ps->stack_b) - b_idx);
	c->r_rotate_total = max(iabs(c->r_rotate_a), iabs(c->r_rotate_b));
	// ft_printf("c.r_rotate a = %d , c.r_rotate b = %d\n", c->r_rotate_a, c->r_rotate_b);
	if (c->greedy_total <= c->rotate_total && c->greedy_total <= c->r_rotate_total)
	{
		// ft_printf("case 1\n");
		c->moves_a = c->greedy_a;
		c->moves_b = c->greedy_b;
		// ft_printf("c.moves.a = %d --- c.moves.b = %d\n", c->moves_a, c->moves_b);
	}
	else if (c->rotate_total <= c->greedy_total && c->rotate_total <= c->r_rotate_total)
	{
		// ft_printf("case 2\n");
		c->moves_a = c->rotate_a;
		c->moves_b = c->rotate_b;
	}
	else
	{
		// ft_printf("case 3\n");
		c->moves_a = c->r_rotate_a;
		c->moves_b = c->r_rotate_b;
	}
}

void	magic_bring_top(int a_moves, int b_moves, t_global *ps)
{
	// ft_printf("In magic bring top\n");
	t_compute_helper	c;
	int					sign;
	int					min_v;
	int					max_v;
	int					i;

	sign = a_moves * b_moves;
	// ft_printf("Sign = %d\n", sign);
	i = 0;
	if (sign > 0)
	{
		c.moves_a_abs = iabs(a_moves);
		c.moves_b_abs = iabs(b_moves);
		min_v = min(c.moves_a_abs, c.moves_b_abs);
		max_v = max(c.moves_a_abs, c.moves_b_abs) - min_v;
		// ft_printf("minv = %d --- maxv = %d\n", min_v, max_v);
		while (i < min_v)
		{
			if (a_moves > 0)
				rr(ps);
			else
				rrr(ps);
			i++;
		}
		i = 0;
		while (i < max_v)
		{
			if (a_moves > 0)
			{
				if (c.moves_a_abs > c.moves_b_abs)
					ra(&ps->stack_a);
				else
					rb(&ps->stack_b);
			}
			else
			{
				if (c.moves_a_abs > c.moves_b_abs)
					rra(&ps->stack_a);
				else
					rrb(&ps->stack_b);
			}
			i++;
		}
	}
	else
	{
		bring_top_minimum_a(a_moves, ps);
		bring_top_minimum_b(b_moves, ps);
	}
		
}