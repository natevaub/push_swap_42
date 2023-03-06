/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error-management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:04:38 by nvaubien          #+#    #+#             */
/*   Updated: 2023/03/06 11:01:43 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Function to check if user input fits in an int */
int is_valid_input(char *str)
{
	int i = 0;
	int len = ft_strlen(str);
	// Check for negative numbers
	if (str[i] == '-')
	{
		i++;
		len--;
	}
	// Check for non-digit characters and length limit
	while (i < len)
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	// Check for overflow or underflow
	if (ft_strlen(str) > 11 || (ft_strlen(str) == 11
	&& ft_strncmp(str, INT_MIN, 11) < 0)
	|| (ft_strlen(str) == 10 && str[0] != '-'
	&& ft_strncmp(str, INT_MAX, 10) < 0))
		return (1);
	return (0);
}

int find_duplicate(t_stack *node) {
	t_stack *pholder;
	t_stack *test;

	pholder = node;
	if (node == NULL) {
		return 0;
	}
	while (pholder != NULL) {
		test = pholder->next;
		while (test != NULL) {
			if (pholder->value == test->value) {
				return (1);
			}
			test = test->next;
		}
		pholder = pholder->next;
	}
	return (0);
}

void	error_msg(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
