/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack-operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:42:24 by nvaubien          #+#    #+#             */
/*   Updated: 2023/02/08 18:06:32 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Basic operations */
void print_list(t_stack *head)
{
	t_stack *current;
	current = head;
	int i = 0;

	while (current != NULL)
	{
		printf("Node %d: %d\n", i, current->value);
		i++;
		current = current->next;
	}
}

t_stack	*insert_at_head(t_stack *head, int new_value)
{
	t_stack *new_data = calloc(1, sizeof(t_stack));
	new_data->value = new_value;
	if (head == NULL) return new_data;
	else 
	{
		new_data->next = head;
		return new_data;
	}
}

t_stack	*insert_at_tail(t_stack *head, int new_value)
{
	t_stack *new_data = calloc(1, sizeof(t_stack));
	new_data->value = new_value;
	if (head == NULL) return new_data;
	else
	{
		t_stack *current = head;
		while (current->next!= NULL)
			current = current->next;
		current->next = new_data;
		return head;
	}
}