/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:22:11 by nvaubien          #+#    #+#             */
/*   Updated: 2023/02/27 19:00:13 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int ac, char **av)
{
	t_stack *top;
	top = NULL;
	int i = 1;
	// ft_printf("Number of arguments %d\n", ac);
	// printf("%d", ft_atoi(av[1]));
	while (i <= ac - 1)
	{
		top = insert_at_tail(top, ft_atoi(av[i]));
		if (find_duplicate(top) || is_valid_input(av[i]))
			error_msg();
		i++;
	}
	print_list(top);
}