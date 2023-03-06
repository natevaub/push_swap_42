/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack-operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:42:24 by nvaubien          #+#    #+#             */
/*   Updated: 2023/03/05 17:14:52 by nvaubien         ###   ########.fr       */
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


void	sa(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*next;

	if (*head && (*head)->next)
	{
		tmp = *head;
		next = (*head)->next;
		tmp->next = next->next;
		next->next = tmp;
		*head = next;
		ft_printf("sa\n");
	}
}

void	sb(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*next;

	if (*head && (*head)->next)
	{
		tmp = *head;
		next = (*head)->next;
		tmp->next = next->next;
		next->next = tmp;
		*head = next;
		ft_printf("sb\n");
	}
}

void	ss(t_global *ps)
{
	sa(&ps->stack_a);
	sb(&ps->stack_b);
}

void	pa(t_global *ps)
{
	int	tmp;

	if (ps->stack_b == NULL)
		return; 
	else 
	{
		tmp = ps->stack_b->value;
		insert_at_head(&ps->stack_a, tmp);
		delete_at_head(&ps->stack_b);
		ft_printf("pa\n");
	}
}

void	pb(t_global *ps)
{
	int	tmp;

	if (ps->stack_a == NULL)
		return;
	else 
	{
		tmp = ps->stack_a->value;
		insert_at_head(&ps->stack_b, tmp);
		delete_at_head(&ps->stack_a);
		ft_printf("pb\n");
	}
}

void	ra(t_stack **head)
{
	t_stack *node;
	t_stack *last_node;

	// Check if the list has more than one node
	if (*head != NULL && (*head)->next != NULL)
	{
		// Save the first node in temporary variable
		node = *head;
		// Set the head to point to the second element
		*head = (*head)->next;
		// Traverse the list to find the last node
		last_node = node;
		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}
		// Set the next pointer of the last node to the first node
		last_node->next = node;
		// Set the next pointer of the first node to NULL
		node->next = NULL;
	}
}