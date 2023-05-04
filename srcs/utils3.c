/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:03:23 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/04 17:01:51 by nvaubien         ###   ########.fr       */
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
	ft_printf("max stack = %d\n", current);
	while (curr != NULL)
	{
		ft_printf("Curr value = %d Number = %d Current = %d\n", curr->value, number, current);
		if (curr->value >= number && curr->value <= current)
		{
			current = curr->value;
			res = i;
			ft_printf("Res = %d\n", res);
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
	int	b_elem;
	int	minb;
	int	maxb;
	int	i;

	minb = stack_min_value(ps->stack_b);
	maxb = stack_max_value(ps->stack_b);
	a_elem = find_elem_at_index(ps->stack_a, a_idx);
	ft_printf("minb %d --- maxb %d\n", minb, maxb);
	ft_printf("a_elem = %d\n", a_elem);
	moves->a_moves = bring_top_minimum_moves_a(a_idx, ps);
	print_stack(ps);
	if (a_elem > maxb || a_elem < minb)
	{
		b_elem = find_index_of_element(ps->stack_b, maxb);
		moves->b_moves = bring_top_minimum_moves_b(b_elem, ps);
	}
	else
	{
		i = find_biggest_smaller_than(a_elem, ps->stack_b);
		ft_printf("i = %d\n", i);
		moves->b_moves = bring_top_minimum_moves_b(i, ps);
	}
	ft_printf("a_moves = %d\n", moves->a_moves);
	ft_printf("b_moves = %d\n", moves->b_moves);
	ft_printf("\n");
	// print_stack(ps);
	// exit(1);
}

