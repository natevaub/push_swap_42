/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big-sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:58:45 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/04 17:07:04 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	big_sort_first_step(t_global *ps)
{
	int		x;
	int		best_index;
	t_moves	best_moves;
	t_moves current_moves;

	x = 0;
	best_moves.a_moves = 1073741823;
	best_moves.b_moves = 1073741823;
	best_index = -1;
	pb(ps);
	pb(ps);
	while (stack_size(&ps->stack_a) > 3)
	{
		while (x < stack_size(&ps->stack_a))
		{
			compute_operations(x, ps, &current_moves);
			if (iabs(current_moves.a_moves) + iabs(current_moves.b_moves) 
			< iabs(best_moves.a_moves) + iabs(best_moves.b_moves))
			{
				best_index = x;
				best_moves.a_moves = iabs(current_moves.a_moves);
				best_moves.b_moves = iabs(current_moves.b_moves);
				ft_printf("x = %d, new best mooves adds = %d\n", x, iabs(current_moves.a_moves) + iabs(current_moves.b_moves));
			}
			x++;
		}
		/* Get index of minimum in ops */
		x = 0;
		bring_top_minimum_a(best_moves.a_moves, ps);
		print_stack(ps);
		bring_top_minimum_b(best_moves.b_moves, ps);
		print_stack(ps);
		pb(ps);
		reset_best_moves(&best_moves);
		print_stack(ps);
	}
	sort3(ps);
	print_stack(ps);
}

void	big_sort_second_step(t_global *ps)
{
	int	mina;
	int	maxa;
	int	i_mina;
	int	i_maxa;
	int	b_elem;
	int	temp;
	t_moves	moves;

	while (stack_size(&ps->stack_b) > 0)
	{
		mina = stack_min_value(ps->stack_a);
		i_mina = find_index_of_element(ps->stack_a, mina);
		maxa = stack_max_value(ps->stack_a);
		i_maxa = find_index_of_element(ps->stack_a, maxa);
		ft_printf("%d --- %d\n", mina, maxa);
		if (ps->stack_b->value < mina || ps->stack_b->value > maxa)
		{
			bring_top_minimum_a(i_mina, ps);
			pa(ps);
			print_stack(ps);
		}
		else
		{
			b_elem = ps->stack_b->value;
			ft_printf("b_elem = %d\n", b_elem);
			temp = find_smallest_bigger_than(b_elem, ps->stack_a);
			ft_printf("FInd smallet bigget than = %d\n", temp);
			moves.a_moves = bring_top_minimum_moves_a(temp, ps);
			ft_printf("MOOVES = %d\n", moves.a_moves);
			bring_top_minimum_a(moves.a_moves, ps);
			pa(ps);
			print_stack(ps);
		}
	}
	i_mina = stack_min_index(ps->stack_a);
	ft_printf("Min a = %d\n", i_mina);
	moves.a_moves = bring_top_minimum_moves_a(i_mina, ps);
	ft_printf("amoves = %d\n", moves.a_moves);
	bring_top_minimum_a(moves.a_moves, ps);
}