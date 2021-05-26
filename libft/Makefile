# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cport <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 15:55:49 by cport             #+#    #+#              #
#    Updated: 2019/09/22 18:14:07 by cport            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isgraph.c \
ft_isspace.c ft_isprint.c ft_ispunct.c ft_islower.c ft_isupper.c ft_atoi.c \
ft_tolower.c ft_toupper.c ft_putchar.c ft_putendl.c ft_putnbr.c ft_putstr.c \
ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_itoa.c \
ft_memset.c ft_bzero.c ft_strcmp.c ft_strncmp.c ft_memcmp.c ft_strdup.c \
ft_memmove.c ft_memcpy.c ft_memccpy.c ft_strcpy.c ft_strncpy.c ft_strlcpy.c \
ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strchri.c ft_strrchr.c \
ft_memchr.c ft_strstr.c ft_strnstr.c ft_strlen.c ft_overint.c ft_oversiz.c \
ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
ft_strjoin.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_lstnew.c ft_lstdel.c \
ft_lstdelone.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_intlen.c ft_lstlen.c \
ft_realloc.c get_next_line.c ft_intlenb.c ft_wcharlen.c ft_strsplitdel.c \
ft_printf.c pf_parse.c pf_utilities.c pf_process_cs.c pf_process_diouxp.c \
pf_process_f.c ft_mod.c ft_isnum.c

OBJS = $(SRCS:.c=.o)

INCL = libft.h 

all: $(NAME)

$(NAME): $(OBJS)
	@gcc -Wall -Wextra -Werror -c $(SRCS) -I $(INCL)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o:%.c
	@gcc -Wall -Wextra -Werror $< -c -o $@

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
