/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers-sort-2-3-5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:31:39 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/07 15:27:07 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	top_greater_middle(t_global *ps)
{
	if (ps->stack_a->value < ps->stack_a->next->value)
	{
		if (ps->stack_a->value < ps->stack_a->next->next->value)
		{
			rra(&ps->stack_a);
			sa(&ps->stack_a);
		}
		else
			rra(&ps->stack_a);
	}
}

void	top_less_middle(t_global *ps)
{
	if (ps->stack_a->next->value < ps->stack_a->next->next->value)
	{
		if (ps->stack_a->value > ps->stack_a->next->next->value)
			ra(&ps->stack_a);
		else
			sa(&ps->stack_a);
	}
	else
	{
		sa(&ps->stack_a);
		rra(&ps->stack_a);
	}
}

void	find_min_pb(t_global *ps)
{
	int	loop;
	int	size;
	int	index;

	loop = 0;
	while (loop < 2)
	{
		size = stack_size(&ps->stack_a);
		index = stack_min_index(ps->stack_a);
		if (index <= size / 2)
		{
			ra_low_index(index, ps);
		}
		else
		{
			ra_high_index(index, size, ps);
		}
		pb(ps);
		loop++;
	}
}

void	ra_low_index(int index, t_global *ps)
{
	while (index)
	{
		ra(&ps->stack_a);
		index--;
	}
}

void	ra_high_index(int index, int size, t_global *ps)
{
	while (index <= size - 1)
	{
		rra(&ps->stack_a);
		index++;
	}
}
