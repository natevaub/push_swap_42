/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:58:23 by nvaubien          #+#    #+#             */
/*   Updated: 2023/03/06 09:58:36 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **head)
{
	t_stack	*node;
	t_stack	*last_node;

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
		ft_printf("ra\n");
	}
}

void	rb(t_stack **head)
{
	t_stack	*node;
	t_stack	*last_node;

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
		ft_printf("rb\n");
	}
}

void	rr(t_global *ps)
{
	ra(&ps->stack_a);
	rb(&ps->stack_a);
}

void	rra(t_stack **head)
{
	t_stack	*node;
	t_stack	*last_node;
	t_stack	*second_last_node;

	// Check if the list has more than one node
	if (*head != NULL && (*head)->next != NULL)
	{
		// Traverse the list to find the second last node
		node = *head;
		while (node->next->next != NULL)
		{
			node = node->next;
		}
		// Save the last node in temporary variable
		last_node = node->next;
		// Set the next pointer of the second last node to NULL
		second_last_node = node;
		second_last_node->next = NULL;
		// Set the next pointer of the last node to point to the first node
		last_node->next = *head;
		// Set the head to point to the last node
		*head = last_node;
		ft_printf("rra\n");
	}
}

void	rrb(t_stack **head)
{
	t_stack	*node;
	t_stack	*last_node;
	t_stack	*second_last_node;

	// Check if the list has more than one node
	if (*head != NULL && (*head)->next != NULL)
	{
		// Traverse the list to find the second last node
		node = *head;
		while (node->next->next != NULL)
		{
			node = node->next;
		}
		// Save the last node in temporary variable
		last_node = node->next;
		// Set the next pointer of the second last node to NULL
		second_last_node = node;
		second_last_node->next = NULL;
		// Set the next pointer of the last node to point to the first node
		last_node->next = *head;
		// Set the head to point to the last node
		*head = last_node;
		ft_printf("rra\n");
	}
}

void	rrr(t_global *ps)
{
	rra(&ps->stack_a);
	rrb(&ps->stack_b);
}

