# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 16:22:07 by nvaubien          #+#    #+#              #
#    Updated: 2023/05/04 16:13:21 by nvaubien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					:= push_swap

CC						:= gcc

CFLAGS					:= #-Wall -Wextra -Werror

# BONUS_NAME				:= checker


LIB_DIRECTORY			:= ./libs/

LIBFT_DIRECTORY			:= $(LIB_DIRECTORY)libft/
LIBFT					:= $(LIBFT_DIRECTORY)libft.a

LIBPRINTF_DIRECTORY		:= $(LIB_DIRECTORY)ftprintf/ #/libs/ftprintf
LIBPRINTF				:= $(LIBPRINTF_DIRECTORY)libftprintf.a # /libs/libftprinf/libftprintf.a

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
							sort-2-3-5.c				\
							helpers-sort-2-3-5.c		\
							big-sort.c					\


OBJECTS_DIRECTORY		:= objs/
OBJECTS_LIST			:= $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS					:= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

all: $(NAME) #$(BONUS_NAME)

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

clean:
	$(MAKE) -sC $(LIBPRINTF_DIRECTORY) clean
	$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	$(MAKE) -sC $(LIBFT_DIRECTORY) fclean
	$(MAKE) -sC $(LIBPRINTF_DIRECTORY) fclean
	rm -f libft.a
	rm -f libftprintf.a
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
