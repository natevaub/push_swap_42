/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no-print-swap-op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:25:21 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/08 16:39:41 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	check_sa(t_stack **head)
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
	}
}

void	check_sb(t_stack **head)
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
	}
}

void	check_ss(t_global *ps)
{
	check_sa(&ps->stack_a);
	check_sb(&ps->stack_b);
}
