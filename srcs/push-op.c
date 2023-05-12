/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:53:48 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/12 22:19:11 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_global *ps)
{
	int	tmp;

	if (ps->stack_b == NULL)
		return ;
	else
	{
		tmp = ps->stack_b->value;
		insert_at_head(&ps->stack_a, tmp);
		delete_at_head(&ps->stack_b);
		ft_printf("pa\n");
	}
}

void	pb(t_global *ps)
{
	int	tmp;

	if (ps->stack_a == NULL)
		return ;
	else
	{
		tmp = ps->stack_a->value;
		insert_at_head(&ps->stack_b, tmp);
		delete_at_head(&ps->stack_a);
		ft_printf("pb\n");
	}
}


void	find_min_pb_one(t_global *ps)
{
	int	loop;
	int	size;
	int	index;

	loop = 0;
	while (loop < 1)
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
