/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:22:04 by nvaubien          #+#    #+#             */
/*   Updated: 2023/02/02 20:02:01 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <string.h>
#include "libs/libft/libft.h"
#include "libs/ftprintf/ft_printf.h"

/* Structs */
typedef struct s_stack {
	int value;
	struct node *next;
}	t_stack;

/* Fonctions */

t_stack	*insert_at_tail(t_stack *head, int new_value);
t_stack	*insert_at_head(t_stack *head, int new_value);
void	print_list(t_stack *head);
int		main(int ac, char **av);


#endif

