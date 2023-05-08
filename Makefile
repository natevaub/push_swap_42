# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 16:22:07 by nvaubien          #+#    #+#              #
#    Updated: 2023/05/08 16:39:27 by nvaubien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					:= push_swap

CC						:= gcc

CFLAGS					:= -Wall -Wextra -Werror

BONUS_NAME				:= checker


LIB_DIRECTORY			:= ./libs/

LIBFT_DIRECTORY			:= $(LIB_DIRECTORY)libft/
LIBFT					:= $(LIBFT_DIRECTORY)libft.a

LIBPRINTF_DIRECTORY		:= $(LIB_DIRECTORY)ftprintf/
LIBPRINTF				:= $(LIBPRINTF_DIRECTORY)libftprintf.a

SOURCES_DIRECTORY		:= ./srcs/

SOURCES_LIST			:=	error-management.c			\
							helpers.c					\
							helpers2.c					\
							linked-list-insert-del.c	\
							push_swap.c					\
							push-op.c					\
							reverse-rotate-op.c			\
							rotate-op.c					\
							stacks-visualizer.c			\
							swap-op.c					\
							utils1.c					\
							utils2.c					\
							utils3.c					\
							utils4.c					\
							sort-2-3-5.c				\
							helpers-sort-2-3-5.c		\
							big-sort.c					\
							init.c						\

OBJECTS_DIRECTORY		:= objs/
OBJECTS_LIST			:= $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS					:= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))


SOURCES_DIRECTORY_BONUS	:= ./srcs_bonus/

SOURCES_LIST_BONUS		:=	checker.c					\
							main.c						\
							no-print-push-op.c			\
							no-print-rte-op.c			\
							no-print-rrte-op.c			\
							no-print-swap-op.c			\

OBJECTS_DIRECTORY_BONUS := objs_bonus/
OBJECTS_LIST_BONUS		:= $(patsubst %.c, %.o, $(SOURCES_LIST_BONUS))
OBJECTS_BONUS			:= $(addprefix $(OBJECTS_DIRECTORY_BONUS), $(OBJECTS_LIST_BONUS))

all: $(NAME)

$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(LIBPRINTF) $(OBJECTS_DIRECTORY) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -Llibs/ftprintf -lftprintf -Llibs/libft -lft -o $(NAME)

$(LIBFT):
	@echo "$(NAME) : Compiling libft "
	$(MAKE) -sC $(LIBFT_DIRECTORY)
	cp libs/libft/libft.a .

$(LIBPRINTF):
	@echo "$(NAME): Compiling ftprintf "
	$(MAKE) -sC $(LIBPRINTF_DIRECTORY)
	cp libs/ftprintf/libftprintf.a .

bonus:	$(BONUS_NAME)

$(OBJECTS_DIRECTORY_BONUS):
	mkdir -p $(OBJECTS_DIRECTORY_BONUS)

$(OBJECTS_DIRECTORY_BONUS)%.o : $(SOURCES_DIRECTORY_BONUS)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_NAME): $(OBJECTS_DIRECTORY) $(OBJECTS) $(OBJECTS_DIRECTORY_BONUS) $(OBJECTS_BONUS) $(LIBFT) $(LIBPRINTF)
	$(CC) $(CFLAGS) $(filter-out $(OBJECTS_DIRECTORY)push_swap.o,$(OBJECTS)) $(OBJECTS_BONUS) \
	-L$(LIBPRINTF_DIRECTORY) -lftprintf -L$(LIBFT_DIRECTORY) -lft -o $(BONUS_NAME)
clean:
	$(MAKE) -sC $(LIBPRINTF_DIRECTORY) clean
	$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	rm -rf $(OBJECTS_DIRECTORY)
	rm -rf $(OBJECTS_DIRECTORY_BONUS)

fclean: clean
	$(MAKE) -sC $(LIBFT_DIRECTORY) fclean
	$(MAKE) -sC $(LIBPRINTF_DIRECTORY) fclean
	rm -f libft.a
	rm -f libftprintf.a
	rm -f $(NAME)
	rm -rf $(BONUS_NAME)

re : fclean all

.PHONY: all clean fclean re
