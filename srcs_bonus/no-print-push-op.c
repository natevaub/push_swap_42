/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no-print-push-op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:29:24 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/08 16:30:13 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_pa(t_global *ps)
{
	int	tmp;

	if (ps->stack_b == NULL)
		return ;
	else
	{
		tmp = ps->stack_b->value;
		insert_at_head(&ps->stack_a, tmp);
		delete_at_head(&ps->stack_b);
	}
}

void	check_pb(t_global *ps)
{
	int	tmp;

	if (ps->stack_a == NULL)
		return ;
	else
	{
		tmp = ps->stack_a->value;
		insert_at_head(&ps->stack_b, tmp);
		delete_at_head(&ps->stack_a);
	}
}
