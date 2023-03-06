/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:57:44 by nvaubien          #+#    #+#             */
/*   Updated: 2023/03/06 09:57:50 by nvaubien         ###   ########.fr       */
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