/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error-management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:04:38 by nvaubien          #+#    #+#             */
/*   Updated: 2023/02/08 19:28:51 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	error_cases(t_stack *head)
{
	t_stack *current;
	current = head;
	while(current != NULL)
	{
	}
	return (0);
}



int	error_msg(void)
{
	write(2, "Error\n", 6);
	exit(1);
}