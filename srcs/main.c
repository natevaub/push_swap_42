/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:22:11 by nvaubien          #+#    #+#             */
/*   Updated: 2023/03/07 19:14:15 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int ac, char **av)
{
	t_global ps;
	ps.stack_a = NULL;
	ps.stack_b = NULL;

	int i = ac - 1;
	while (i >= 1)
	{
		insert_at_head(&ps.stack_a, ft_atoi(av[i]));
		if (find_duplicate(ps.stack_a) || is_valid_input(av[i]))
			error_msg();
		i--;
	}
	print_stack(&ps);
	rra(&ps.stack_a);
	print_stack(&ps);

	// Remember to free the memory allocated for ps when you're done
	// free(ps->stack_a);
	// free(ps->stack_b);
	// free(ps);
	return (0);
}