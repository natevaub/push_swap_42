/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:09:22 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/08 16:47:47 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	main(int ac, char **av)
{
	t_global	ps;
	int			size;

	ps.stack_a = NULL;
	ps.stack_b = NULL;
	if (ac == 1)
		exit(EXIT_FAILURE);
	if (init_stacks(&ps, av, ac) == -1)
		error_msg();
	size = stack_size(&ps.stack_a);
	apply_instructions(&ps);
	if (is_sorted_a(&ps.stack_a, size) == 1 && stack_size(&ps.stack_a) == size)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	
	deallocate_stack(ps.stack_a);
	deallocate_stack(ps.stack_b);
}
