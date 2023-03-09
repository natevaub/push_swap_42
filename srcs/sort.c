/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:35:47 by nvaubien          #+#    #+#             */
/*   Updated: 2023/03/09 16:20:57 by nvaubien         ###  ########.fr       */
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

void	sort3(t_global *ps)
{
	if (is_sorted(&ps->stack_a))
		return;
	if (ps->stack_a->value < ps->stack_a->next->value)
		top_greater_middle(ps);
	else if (ps->stack_a->next->value < ps->stack_a->next->next->value)
		top_less_middle(ps);
}
