# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cport <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/07 15:55:49 by cport             #+#    #+#              #
#    Updated: 2020/09/22 18:14:07 by cport            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = cport.filler

CC      = gcc
FLAG    = -Wall -Wextra -Werror

DIR_S   = src
DIR_H   = includes
DIR_L   = libft

LIB     = $(addprefix $(DIR_L)/, libft.a)

SOURCES = filler.c parse_map.c parse_token.c clean.c
SRCS    = $(addprefix $(DIR_S)/, $(SOURCES))
OBJS    = $(SRCS:.c=.o)

all:    $(NAME)

$(LIB):
	@- make -C $(DIR_L)

$(OBJS):    %.o: %.c
	@$(CC) -c $(FLAGS) -I  $(DIR_H) $< -o $@

$(NAME):    $(LIB) $(OBJS)
	@$(CC) $(OBJS) $(LIB) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@make -C $(DIR_L) clean

fclean: clean
	@rm -rf $(OBJS)
	@make -C $(DIR_L) fclean

re:	fclean all

.PHONY:	all clean fclean re
