/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse-rotation-op.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:57:19 by nvaubien          #+#    #+#             */
/*   Updated: 2023/04/27 12:59:19 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		ft_printf("rrb\n");
	}
}

void	rrr(t_global *ps)
{
	rra(&ps->stack_a);
	rrb(&ps->stack_b);
}
