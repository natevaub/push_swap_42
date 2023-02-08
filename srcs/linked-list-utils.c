/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked-list-utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:58:28 by nvaubien          #+#    #+#             */
/*   Updated: 2023/02/08 19:30:33 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int find_duplicate(t_stack *node)
{
	t_stack *pholder;
	t_stack *test;
	test = node;
	pholder = node->next;
	if (node == NULL) 
		return (0);
	else
	{
		while (pholder != NULL)
		{
			if (test->value == pholder->value)
			{
				return (1);
			}
			printf("pholder = %d\n", pholder->value);
			pholder = pholder->next;
		}
		test->next;
		printf("test = %d\n", pholder->value);
	}
	return (0);
}