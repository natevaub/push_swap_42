/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:22:11 by nvaubien          #+#    #+#             */
/*   Updated: 2023/03/09 15:41:26 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// int args_count(char *str)
// {
// 	int i;
// 	int	words;

// 	i = 0;
// 	words = 0;
// 	while (str[i] && str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
// 		i++;
// 	if (str[i])
// 	{
// 		words++;
// 		while (str[i] && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
// 			i++;
// 	}
// 	return (words);
// }

int args_count(char **input)
{
	int	i;
	
	i = 0;
	while(input[i] != NULL)
		i++;
	return (i);
}

char **arg_init(char *av)
{
	char **input;
	input = ft_split(av, ' ');
	return (input);
}

int main(int ac, char **av)
{
	// make && valgrind --leak-check=full --track-origins=yes ./push_swap
	
	t_global ps;
	ps.stack_a = NULL;
	ps.stack_b = NULL;

	char	**input;
	int		count;
	int		ccount;
	
	if (ac == 2)
	{
		printf("ac == 2\n");
		input = arg_init(av[1]);
		count = args_count(input) - 1;
		ccount = count;
		printf("Count = %d\n", count);
		while (count >= 0)
		{
			printf("sigwhile -- %s\n", input[count]);
			insert_at_head(&ps.stack_a, ft_atoi(input[count]));
		// 	if (find_duplicate(ps.stack_a) || is_valid_input(input[count]))
		// 		error_msg();
			count--;
		}
		for (int i = 0; input[i]; i++)
			free(input[i]);
		free(input);
		
	}

	if (ac > 2)
	{
		printf("ac > 2\n");
		int i = ac - 1;
		while (i >= 1)
		{
			insert_at_head(&ps.stack_a, ft_atoi(av[i]));
			if (find_duplicate(ps.stack_a) || is_valid_input(av[i]))
				error_msg();
			i--;
		}
	}

	if (ccount == 2 || ac == 4)
	{
		printf("if count == 2 || ac == 4\n");
		sort3(&ps);
	}

	print_stack(&ps);
	// rra(&ps.stack_a);
	// print_stack(&ps);

	// Remember to free the memory allocated for ps when you're done

	deallocate(&ps.stack_a);
	deallocate(&ps.stack_b);
	// free(ps.stack_a);
	// free(ps.stack_b);
	return (0);
}