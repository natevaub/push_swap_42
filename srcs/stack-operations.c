/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack-operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:42:24 by nvaubien          #+#    #+#             */
/*   Updated: 2023/03/08 17:49:22 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Basic operations */
void print_stack(t_global *ps)
{
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

	// Add some formatting
	printf("stack_a\t\tstack_b\n");
	printf("-------\t\t-------\n");
}

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

void deallocate(t_stack **head)
{
	t_stack	*curr = *head;
	t_stack	*aux;

	while (curr != NULL)
	{
		aux = curr;
		curr = curr->next;
		free(aux);
	}
	*head = NULL;
}