/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:22:14 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/08 15:22:46 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	args_count(char **input)
{
	int	i;

	i = 0;
	while (input[i] != NULL)
		i++;
	return (i);
}

int	init_stacks_quote(t_global *ps, const char *arg_str)
{
	char	**args;
	int		count;

	args = ft_split(arg_str, ' ');
	count = args_count(args) - 1;
	while (count >= 0)
	{
		if (is_valid_input(args[count]))
		{
			free_ft_split(args);
			return (-1);
		}
		insert_at_head(&ps->stack_a, ft_atoi(args[count]));
		count--;
		if (find_duplicate(ps->stack_a))
		{
			free_ft_split(args);
			deallocate_stack(ps->stack_a);
			return (-1);
		}
	}
	free_ft_split(args);
	return (0);
}

int	init_stacks(t_global *ps, char **av, int ac)
{
	int	i;

	if (ac == 2)
	{
		return (init_stacks_quote(ps, av[1]));
	}
	else if (ac > 2)
	{
		i = ac - 1;
		while (i > 0)
		{
			if (is_valid_input(av[i]))
				return (-1);
			insert_at_head(&ps->stack_a, ft_atoi(av[i]));
			i--;
			if (find_duplicate(ps->stack_a))
				return (-1);
		}
	}
	return (0);
}
