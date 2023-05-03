/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error-management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:44:53 by nvaubien          #+#    #+#             */
/*   Updated: 2023/04/27 12:45:05 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Function to check if user input fits in an int */
int is_valid_input(char *str)
{
	int i = 0;
	int len = ft_strlen(str);
	if (len == 1 && str[0] == '-')
		return (1); // Invalid input if only '-' is provided
	if (str[i] == '-')
	{
		i++;
		len--;
	}
	while (i < len)
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	if (ft_strlen(str) > 11 || (ft_strlen(str) == 11
	&& ft_strncmp(str, INT_MIN, 11) < 0)
	|| (ft_strlen(str) == 10 && str[0] != '-'
	&& ft_strncmp(str, INT_MAX, 10) < 0))
		return (1);
	return (0);
}

int find_duplicate(t_stack *node) {
	t_stack	*current;
	t_stack	*runner;
	if (node == NULL)
	{
		return (0);
	}
	current = node;
	while (current != NULL)
	{
		runner = current;
		while (runner->next != NULL)
		{
			if (current->value == runner->next->value)
			{
				printf("current.value %d, runner.next.value = %d", current->value, runner->next->value);
				return (1);
			}
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

void	error_msg(void)
{
	write(2, "Error\n", 6);
	exit(1);
}