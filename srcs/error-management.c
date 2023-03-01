/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error-management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:04:38 by nvaubien          #+#    #+#             */
/*   Updated: 2023/02/27 23:49:49 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Function to check if user input fits in an int */
int is_valid_input(char *str)
{
	int num;

	num = ft_atoi(str);
	if (num == 0 && str[0] != '0') {
		return (1); // not a valid integer
	}
	else if (num < INT_MIN || num > INT_MAX) {
		return (1); // integer out of range
	}
	return (0); // valid integer
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
