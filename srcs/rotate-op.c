/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate-op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:56:28 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/07 15:40:00 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **head)
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
		ft_printf("ra\n");
	}
}

void	rb(t_stack **head)
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
		ft_printf("rb\n");
	}
}

void	ra_no_print(t_stack **head)
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

void	rb_no_print(t_stack **head)
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

void	rr(t_global *ps)
{
	ra_no_print(&ps->stack_a);
	rb_no_print(&ps->stack_b);
	ft_printf("rr\n");
}
