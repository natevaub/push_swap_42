/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:36:35 by nvaubien          #+#    #+#             */
/*   Updated: 2023/03/10 15:29:58 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_size(t_stack **head)
{
	int		size;
	t_stack	*curr;

	size = 0;
	curr = *head;
	while (curr != NULL)
	{
		size++;
		curr = curr->next;
	}
	return (size);
}

int	stack_min(t_stack **head)
{
	t_stack *curr;
	int	index_min;
	int	min_val;

	curr = *head;
	index_min = -1;
	min_val = 2147483647;
	while (curr != NULL)
	{
		if (curr->value < min_val)
		{
			min_val = curr->value;
			index_min++;
		}
		curr = curr->next;
	}
	return (index_min);
}

int	is_sorted(t_stack **head)
{
	t_stack	*curr;
	int		sorted;

	curr = *head;
	sorted = 1;
	while (curr != NULL && curr->next != NULL)
	{
		if (curr->value > curr->next->value)
			sorted = 0;
		curr = curr->next;
	}
	return (sorted);
}