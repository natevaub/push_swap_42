/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks-visualizer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:02:24 by nvaubien          #+#    #+#             */
/*   Updated: 2023/04/27 13:51:14 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void print_stack(t_global *ps)
{
	ft_printf("\n");
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = ps->stack_a;
	tmp_b = ps->stack_b;

	while (tmp_a || tmp_b)
	{
		if (tmp_a)
		{
			printf("%d", tmp_a->value);
			tmp_a = tmp_a->next;
		}
		printf("\t\t");
		if (tmp_b)
		{
			printf("%d", tmp_b->value);
			tmp_b = tmp_b->next;
		}
		printf("\n");
	}
	ft_printf("\n");
}