/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:26:40 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/08 16:38:06 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	valid_instruction(const char *instruction)
{
	return (!ft_strncmp(instruction, "sa\n", ft_strlen("sa\n"))
		|| !ft_strncmp(instruction, "sb\n", ft_strlen("sb\n"))
		|| !ft_strncmp(instruction, "ss\n", ft_strlen("ss\n"))
		|| !ft_strncmp(instruction, "pa\n", ft_strlen("pa\n"))
		|| !ft_strncmp(instruction, "pb\n", ft_strlen("pb\n"))
		|| !ft_strncmp(instruction, "ra\n", ft_strlen("ra\n"))
		|| !ft_strncmp(instruction, "rb\n", ft_strlen("rb\n"))
		|| !ft_strncmp(instruction, "rr\n", ft_strlen("rr\n"))
		|| !ft_strncmp(instruction, "rra\n", ft_strlen("rra\n"))
		|| !ft_strncmp(instruction, "rrb\n", ft_strlen("rrb\n"))
		|| !ft_strncmp(instruction, "rrr\n", ft_strlen("rrr\n")));
}

void	read_instructions(t_global *ps, char *instruction)
{
	if (!ft_strncmp(instruction, "sb\n", ft_strlen(instruction)))
		check_sb(&ps->stack_b);
	else if (!ft_strncmp(instruction, "sa\n", ft_strlen(instruction)))
		check_sa(&ps->stack_a);
	else if (!ft_strncmp(instruction, "ss\n", ft_strlen(instruction)))
		check_ss(ps);
	else if (!ft_strncmp(instruction, "ra\n", ft_strlen(instruction)))
		check_ra(&ps->stack_a);
	else if (!ft_strncmp(instruction, "rb\n", ft_strlen(instruction)))
		check_rb(&ps->stack_b);
	else if (!ft_strncmp(instruction, "rr\n", ft_strlen(instruction)))
		check_rr(ps);
	else if (!ft_strncmp(instruction, "rra\n", ft_strlen(instruction)))
		check_rra(&ps->stack_a);
	else if (!ft_strncmp(instruction, "rrb\n", ft_strlen(instruction)))
		check_rrb(&ps->stack_b);
	else if (!ft_strncmp(instruction, "rrr\n", ft_strlen(instruction)))
		check_rrr(ps);
	else if (!ft_strncmp(instruction, "pa\n", ft_strlen(instruction)))
		check_pa(ps);
	else if (!ft_strncmp(instruction, "pb\n", ft_strlen(instruction)))
		check_pb(ps);
}

void	apply_instructions(t_global *ps)
{
	print_stack(ps);
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction)
	{
		if (!valid_instruction(instruction))
		{
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		else
			read_instructions(ps, instruction);
		free(instruction);
		instruction = get_next_line(0);
	}
}
