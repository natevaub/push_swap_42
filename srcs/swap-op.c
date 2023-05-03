/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap-op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:54:50 by nvaubien          #+#    #+#             */
/*   Updated: 2023/04/27 12:55:16 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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