/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no-print-rrte-op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:28:17 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/08 16:34:49 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_rra(t_stack **head)
{
	t_stack	*node;
	t_stack	*last_node;
	t_stack	*second_last_node;

	if (*head != NULL && (*head)->next != NULL)
	{
		node = *head;
		while (node->next->next != NULL)
		{
			node = node->next;
		}
		last_node = node->next;
		second_last_node = node;
		second_last_node->next = NULL;
		last_node->next = *head;
		*head = last_node;
	}
}

void	check_rrb(t_stack **head)
{
	t_stack	*node;
	t_stack	*last_node;
	t_stack	*second_last_node;

	if (*head != NULL && (*head)->next != NULL)
	{
		node = *head;
		while (node->next->next != NULL)
		{
			node = node->next;
		}
		last_node = node->next;
		second_last_node = node;
		second_last_node->next = NULL;
		last_node->next = *head;
		*head = last_node;
	}
}

void	check_rrr(t_global *ps)
{
	check_rra(&ps->stack_a);
	check_rrb(&ps->stack_b);
}
