# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 16:22:07 by nvaubien          #+#    #+#              #
#    Updated: 2023/03/07 19:14:33 by nvaubien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					:= push_swap
# BONUS_NAME				:= checker


UNAME_S					:= $(shell uname -s)

ifeq ($(UNAME_S),Linux)
  FSANITIZELEAK			:= -fsanitize=leak
  FRAMEWORK				:=
  LINUX_LIBS			:=
  LINUX_INCLUDES		:= -I/usr/include
  OS_FLAG				:= -D LINUX
else
  FSANITIZELEAK			:=
  FRAMEWORK				:=
  LINUX_LIBS			:=
  LINUX_INCLUDES		:=
  OS_FLAG				:= -D OSX
endif


LIB_DIRECTORY			:= ./libs/

LIBFT					:= $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY			:= $(LIB_DIRECTORY)libft/

LIBPRINTF				:= $(LIBPRINTF_DIRECTORY)libftprintf.a # /libs/libftprinf/libftprintf.a
LIBPRINTF_DIRECTORY		:= $(LIB_DIRECTORY)ftprintf/ #/libs/ftprintf

SOURCES_DIRECTORY		:= ./srcs/

SOURCES_LIST			:=	main.c				\
							stack-operations.c	\
							error-management.c	\
							ps_operations.c		\
							rot_operations.c	\
							utils.c				\
							sort.c				\


OBJECTS_DIRECTORY		:= objs/
OBJECTS_LIST			:= $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS					:= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

.PHONY: all clean fclean re

all: $(NAME) #$(BONUS_NAME)

$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	echo compilating libft
	$(MAKE) -sC $(LIBFT_DIRECTORY)
	cp libs/libft/libft.a .

$(LIBPRINTF):
	@echo "$(NAME): Creating $(LIBPRINTF)..."
	$(MAKE) -sC $(LIBPRINTF_DIRECTORY)
	cp libs/ftprintf/libftprintf.a .

$(NAME): $(LIBFT) $(LIBPRINTF) $(OBJECTS_DIRECTORY) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -Llibs/ftprintf -lftprintf -Llibs/libft -lft -o $(NAME)

clean:
	$(MAKE) -sC $(LIBPRINTF_DIRECTORY) clean
	$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	$(MAKE) -sC $(LIBPRINTF_DIRECTORY) clean
	rm -f libft.a
	rm -f libftprintf.a
	rm -f $(NAME)