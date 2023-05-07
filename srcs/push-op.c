/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:53:48 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/07 15:31:24 by nvaubien         ###   ########.fr       */
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
