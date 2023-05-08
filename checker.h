/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 23:27:22 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/08 16:34:32 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

/* --- checker.c --- */

void	read_instructions(t_global *ps, char *instruction);
int		valid_instruction(const char *instruction);
void	apply_instructions(t_global *ps);
int		main(int ac, char **av);

/* --- no-printing.c --- */
void	check_pa(t_global *ps);
void	check_pb(t_global *ps);
void	check_rra(t_stack **head);
void	check_rrb(t_stack **head);
void	check_rrr(t_global *ps);
void	check_ra(t_stack **head);
void	check_rb(t_stack **head);
void	check_rr(t_global *ps);
void	check_sa(t_stack **head);
void	check_sb(t_stack **head);
void	check_ss(t_global *ps);

#endif