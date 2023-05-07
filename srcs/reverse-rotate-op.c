/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse-rotate-op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:57:19 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/07 00:43:05 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack **head)
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
		ft_printf("rra\n");
	}
}

void	rrb(t_stack **head)
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
		ft_printf("rrb\n");
	}
}

void	rra_no_print(t_stack **head)
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

void	rrb_no_print(t_stack **head)
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

void	rrr(t_global *ps)
{
	rra_no_print(&ps->stack_a);
	rrb_no_print(&ps->stack_b);
	ft_printf("rrr\n");
}
