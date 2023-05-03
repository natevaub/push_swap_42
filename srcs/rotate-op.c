/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate-op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:56:28 by nvaubien          #+#    #+#             */
/*   Updated: 2023/04/27 13:14:55 by nvaubien         ###   ########.fr       */
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