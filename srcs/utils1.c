/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:33:27 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/04 11:11:11 by nvaubien         ###   ########.fr       */
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

int	is_sorted_a(t_stack **head, int size)
{
	t_stack	*curr;
	int		sorted;
	int		i;

	curr = *head;
	sorted = 1;
	i = 0;
	while (curr != NULL && curr->next != NULL && i < size)
	{
		if (curr->value > curr->next->value)
		{
			sorted = 0;
			break;
		}
		curr = curr->next;
		i++;
	}
	return (sorted);
}


int	is_sorted_b(t_stack **head, int size)
{
	t_stack	*curr;
	int		sorted;
	int		i;

	curr = *head;
	sorted = 1;
	i = 0;
	while (curr != NULL && curr->next != NULL && i < size)
	{
		if (curr->value < curr->next->value)
		{
			sorted = 0;
		}
		curr = curr->next;
		i++;
	}
	return (sorted);
}
