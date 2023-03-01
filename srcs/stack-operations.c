/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack-operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:42:24 by nvaubien          #+#    #+#             */
/*   Updated: 2023/03/01 00:49:36 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Basic operations */
void	print_stack(t_global *ps)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int	a;

	tmp_a = ps->stack_a;
	tmp_b = ps->stack_b;
	a = 0;
	while (tmp_a || tmp_b)
	{
		if (tmp_a)
		{
			printf("Node %d = %d", a, tmp_a->value);
			tmp_a = tmp_a->next;
			a++;
		}
		printf("\t\t");
		if (tmp_b)
		{
			printf("Node %d = %d", a, tmp_b->value);
			tmp_b = tmp_b->next;
			a++;
		}
		printf("\n");
	}
}

t_stack	*insert_at_head(t_stack *head, int new_value)
{
	t_stack *new_data = calloc(1, sizeof(t_stack));
	new_data->value = new_value;
	if (head == NULL) return new_data;
	else 
	{
		new_data->next = head;
		return new_data;
	}
}

t_stack	*insert_at_tail(t_stack *head, int new_value)
{
	t_stack *new_data = calloc(1, sizeof(t_stack));
	new_data->value = new_value;
	if (head == NULL) return new_data;
	else
	{
		t_stack *current = head;
		while (current->next!= NULL)
			current = current->next;
		current->next = new_data;
		return head;
	}
}

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
		ft_printf("sb\n");
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