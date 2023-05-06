/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:03:23 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/05 16:38:03 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Function to find the biggest element in b smaller than number, return idx of element */
int	find_biggest_smaller_than(int number, t_stack *head)
{
	int		i;
	int		current;
	int		res;
	t_stack	*curr;

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

int	find_smallest_bigger_than(int number, t_stack *head)
{
	int	i;
	int	current;
	int	res;
	t_stack	*curr;

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

void	compute_operations(int a_idx, t_global *ps, t_moves *moves)
{
	// Fonctions min val stack, max val stack
	// Fonction min index stack, max index stack
	int	a_elem;
	int	b_index;
	int	minb;
	int	maxb;
	int	i;

	minb = stack_min_value(ps->stack_b);
	maxb = stack_max_value(ps->stack_b);
	a_elem = find_elem_at_index(ps->stack_a, a_idx);
	moves->a_moves = bring_top_minimum_moves_a(a_idx, ps);
	if (a_elem > maxb || a_elem < minb)
	{
		b_index = find_index_of_element(ps->stack_b, maxb);
		moves->b_moves = bring_top_minimum_moves_b(b_index, ps);
	}
	else
	{
		i = find_biggest_smaller_than(a_elem, ps->stack_b);
		moves->b_moves = bring_top_minimum_moves_b(i, ps);
	}
	// print_stack(ps);
	// exit(1);
}

