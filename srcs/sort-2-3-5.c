/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort-2-3-5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:29:48 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/12 22:21:59 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort3(t_global *ps)
{
	if (is_sorted_a(&ps->stack_a, stack_size(&ps->stack_a)))
		return ;
	if (ps->stack_a->value < ps->stack_a->next->value)
		top_greater_middle(ps);
	else
		top_less_middle(ps);
}

void	sort5(t_global *ps)
{
	if (is_sorted_a(&ps->stack_a, stack_size(&ps->stack_a)) == 1)
		return ;
	find_min_pb(ps);
	sort3(ps);
	pa(ps);
	pa(ps);
}

void	sort2(t_global *ps)
{
	if (is_sorted_a(&ps->stack_a, stack_size(&ps->stack_a)) == 1)
		return ;
	else
		sa(&ps->stack_a);
}

void	sort4(t_global *ps)
{
	if (is_sorted_a(&ps->stack_a, stack_size(&ps->stack_a)) == 1)
		return ;
	find_min_pb_one(ps);
	sort3(ps);
	pa(ps);
}
