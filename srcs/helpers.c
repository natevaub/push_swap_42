/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:08:12 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/07 15:31:39 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_min_index(t_stack *head)
{
	int		min_val;
	int		min_idx;
	int		i;
	t_stack	*curr;

	if (head == NULL)
		return (-1);
	curr = head;
	min_idx = 0;
	i = 0;
	min_val = curr->value;
	while (curr != NULL)
	{
		if (curr->value < min_val)
		{
			min_val = curr->value;
			min_idx = i;
		}
		i++;
		curr = curr->next;
	}
	return (min_idx);
}

int	stack_min_value(t_stack *head)
{
	int		min_val;
	int		min_idx;
	int		i;
	t_stack	*curr;

	if (head == NULL)
		return (-1);
	curr = head;
	min_idx = 0;
	i = 0;
	min_val = curr->value;
	while (curr != NULL)
	{
		if (curr->value < min_val)
		{
			min_val = curr->value;
			min_idx = i;
		}
		i++;
		curr = curr->next;
	}
	return (min_val);
}

int	stack_max_index(t_stack *head)
{
	int		max_val;
	int		max_idx;
	int		i;
	t_stack	*curr;

	if (head == NULL)
		return (-1);
	curr = head;
	max_idx = 0;
	i = 0;
	max_val = curr->value;
	while (curr != NULL)
	{
		if (curr->value > max_val)
		{
			max_val = curr->value;
			max_idx = i;
		}
		i++;
		curr = curr->next;
	}
	return (max_idx);
}

int	stack_max_value(t_stack *head)
{
	int		max_val;
	int		max_idx;
	int		i;
	t_stack	*curr;

	if (head == NULL)
		return (-1);
	curr = head;
	max_idx = 0;
	i = 0;
	max_val = curr->value;
	while (curr != NULL)
	{
		if (curr->value > max_val)
		{
			max_val = curr->value;
			max_idx = i;
		}
		i++;
		curr = curr->next;
	}
	return (max_val);
}

int	iabs(int x)
{
	if (x < 0)
		return (x * -1);
	else
		return (x);
}
