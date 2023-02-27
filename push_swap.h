/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:22:04 by nvaubien          #+#    #+#             */
/*   Updated: 2023/02/27 18:44:47 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "libs/libft/libft.h"
#include "libs/ftprintf/ft_printf.h"

/* Structs */
typedef struct s_stack {
	int value;
	struct s_stack *next;
}	t_stack;

/* Fonctions */

t_stack	*insert_at_tail(t_stack *head, int new_value);
t_stack	*insert_at_head(t_stack *head, int new_value);
int		find_duplicate(t_stack *node);
void	print_list(t_stack *head);
void	error_msg(void);
void	error_handling(t_stack *node);
int		is_valid_input(char *str);
int		main(int ac, char **av);


#endif

