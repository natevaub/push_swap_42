/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked-list-insert-del.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:05:17 by nvaubien          #+#    #+#             */
/*   Updated: 2023/04/27 13:05:37 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	insert_at_head(t_stack **head, int new_value)
{
	t_stack *new_data = calloc(1, sizeof(t_stack));
	new_data->value = new_value;
	if (*head == NULL)
	{
		*head = new_data;
	}
	else 
	{
		new_data->next = *head;
		*head = new_data;
	}
}

void	delete_at_head(t_stack **head)
{
	t_stack	*new_head;

	if (*head == NULL) 
		return;
	else
	{
		new_head = (*head)->next;
		free(*head);
		*head = new_head;
	}
}