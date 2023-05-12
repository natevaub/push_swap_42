/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:03:23 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/12 14:33:58 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int find_biggest_smaller_than(int number, t_stack *head)
{
	int i;
	int current;
	int res;
	t_stack *curr;

	curr = head;
	i = 0;
	res = -1;
	current = stack_min_value(head);
	while (curr != NULL)
	{
		if (curr->value <= number && curr->value >= current)
		{
			current = curr->value;
			res = i;
		}
		i++;
		curr = curr->next;
	}
	return (res);
}

int find_smallest_bigger_than(int number, t_stack *head)
{
	int i;
	int current;
	int res;
	t_stack *curr;

	curr = head;
	i = 0;
	res = -1;
	current = stack_max_value(head);
	while (curr != NULL)
	{
		if (curr->value >= number && curr->value <= current)
		{
			current = curr->value;
			res = i;
		}
		i++;
		curr = curr->next;
	}
	return (res);
}

void compute_operations(int a_idx, t_global *ps, t_moves *moves)
{
	t_compute_helper c;
	int a_elem;
	int b_index;
	int i;

	c.minb = stack_min_value(ps->stack_b);
	c.maxb = stack_max_value(ps->stack_b);
	a_elem = find_elem_at_index(ps->stack_a, a_idx);
	if (a_elem > c.maxb || a_elem < c.minb)
	{
		b_index = find_index_of_element(ps->stack_b, c.maxb);
		magic_compute(a_idx, b_index, ps, &c);
		moves->a_moves = c.moves_a;
		moves->b_moves = c.moves_b;
		moves->tot_moves = c.tot;
	}
	else
	{
		i = find_biggest_smaller_than(a_elem, ps->stack_b);
		moves->b_moves = bring_top_minimum_moves_b(i, ps);
		magic_compute(a_idx, i, ps, &c);
		moves->a_moves = c.moves_a;
		moves->b_moves = c.moves_b;
		moves->tot_moves = c.tot;
	}
}
