/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:43:55 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/12 22:21:21 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// make && valgrind --leak-check=full --track-origins=yes ./push_swap
// python3 tester.py -s -n 3 -t 5 -b ./push_swap
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
	if (size == 2)
		sort2(&ps);
	else if (size == 3)
		sort3(&ps);
	else if (size == 4)
		sort4(&ps);
	else if (size == 5)
		sort5(&ps);
	else
		big_sort(&ps);
	deallocate_stack(ps.stack_a);
	return (0);
}
