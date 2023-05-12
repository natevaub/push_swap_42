/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:33:31 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/11 17:28:31 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*	Compute the minimum number of moves to bring the element at idx to the top
	of the stack, be smart about it, reverse_rotate if idx is closer to the bottom
	else rotate, return the number of moves */
int	bring_top_minimum_moves_a(int idx, t_global *ps)
{
	if (idx <= stack_size(&ps->stack_a) / 2)
		return (idx);
	else
		return (-(stack_size(&ps->stack_a) - idx));
}

int	bring_top_minimum_moves_b(int idx, t_global *ps)
{
	if (idx <= stack_size(&ps->stack_b) / 2)
	{
		return (idx);
	}
	else
	{
		return (-(stack_size(&ps->stack_b) - idx));
	}
}

void	bring_top_minimum_a(int op, t_global *ps)
{
	int	i;

	i = 0;
	if (op > 0)
	{
		while (i < op)
		{
			ra(&ps->stack_a);
			i++;
		}
	}
	else
	{
		while (i < -op)
		{
			rra(&ps->stack_a);
			i++;
		}
	}
}

void	bring_top_minimum_b(int op, t_global *ps)
{
	int	i;

	i = 0;
	if (op > 0)
	{
		while (i < op)
		{
			rb(&ps->stack_b);
			i++;
		}
	}
	else
	{
		while (i < -op)
		{
			rrb(&ps->stack_b);
			i++;
		}
	}
}
