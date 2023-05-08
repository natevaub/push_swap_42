/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no-print-rte-op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:26:56 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/08 16:36:53 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	check_ra(t_stack **head)
{
	t_stack	*node;
	t_stack	*last_node;

	if (*head != NULL && (*head)->next != NULL)
	{
		node = *head;
		*head = (*head)->next;
		last_node = node;
		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}
		last_node->next = node;
		node->next = NULL;
	}
}

void	check_rb(t_stack **head)
{
	t_stack	*node;
	t_stack	*last_node;

	if (*head != NULL && (*head)->next != NULL)
	{
		node = *head;
		*head = (*head)->next;
		last_node = node;
		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}
		last_node->next = node;
		node->next = NULL;
	}
}

void	check_rr(t_global *ps)
{
	check_ra(&ps->stack_a);
	check_rb(&ps->stack_b);
}
