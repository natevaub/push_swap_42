/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:49:58 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/01 09:53:27 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_elem_at_index(t_stack *head, int idx)
{
	int	i;

	if (head == NULL || idx < 0)
		return (-1);
	i = 0;
	while (i < idx && head != NULL)
	{
		head = head->next;
		i++;
	}
	if (head == NULL)
		return (-1);
	return (head->value);
}

int find_index_of_element(t_stack *head, int val)
{
	t_stack	*curr;
	int		i;

	curr = head;
	i = 0;
	while (curr != NULL)
	{
		if (curr->value == val)
		{
			return (i);
		}
		i++;
		curr = curr->next;
	}
	return (-1);
}

void	reset_best_moves(t_moves *moves)
{
	moves->a_moves = 1073741823;
	moves->b_moves = 1073741823;
}