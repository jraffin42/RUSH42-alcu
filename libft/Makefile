# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/24 18:18:02 by jraffin           #+#    #+#              #
#    Updated: 2022/02/09 10:07:15 by jraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL			=	/bin/sh

NAME			=	libft.a

SRCDIR			=	.
OBJDIR			=	./obj
DEBUGDIR		=	./debugobj

SRCFILES		=	ft_abs.c			\
					ft_atoi.c			\
					ft_atoi_err.c		\
					ft_basename.c		\
					ft_bzero.c			\
					ft_calloc.c			\
					ft_gnl.c			\
					ft_gnl_leaksafe.c	\
					ft_intlen.c			\
					ft_isalnum.c		\
					ft_isalpha.c		\
					ft_isascii.c		\
					ft_isdigit.c		\
					ft_islower.c		\
					ft_isprint.c		\
					ft_isspace.c		\
					ft_isupper.c		\
					ft_itoa.c			\
					ft_lstadd_back.c	\
					ft_lstadd_front.c	\
					ft_lstclear.c		\
					ft_lstdelone.c		\
					ft_lstiter.c		\
					ft_lstlast.c		\
					ft_lstmap.c			\
					ft_lstnew.c			\
					ft_lstsize.c		\
					ft_max.c			\
					ft_memccpy.c		\
					ft_memchr.c			\
					ft_memcmp.c			\
					ft_memcpy.c			\
					ft_memmove.c		\
					ft_memset.c			\
					ft_min.c			\
					ft_putchar_fd.c		\
					ft_putendl_fd.c		\
					ft_put_error.c		\
					ft_putnbr_fd.c		\
					ft_putstr_fd.c		\
					ft_split.c			\
					ft_splitfree.c		\
					ft_splitset.c		\
					ft_stpcpy.c			\
					ft_stpncpy.c		\
					ft_strchr.c			\
					ft_strchrnul.c		\
					ft_strcmp.c			\
					ft_strcpy.c			\
					ft_strdup.c			\
					ft_striteri.c		\
					ft_strjoin.c		\
					ft_strjoin3.c		\
					ft_strlcat.c		\
					ft_strlcpy.c		\
					ft_strlen.c			\
					ft_strmapi.c		\
					ft_strncmp.c		\
					ft_strncpy.c		\
					ft_strndup.c		\
					ft_strnlen.c		\
					ft_strnstr.c		\
					ft_strrchr.c		\
					ft_strtrim.c		\
					ft_strstr.c			\
					ft_substr.c			\
					ft_tolower.c		\
					ft_toupper.c		\
					ft_wcslen.c			\
					ft_wcsnlen.c		\

SRCS			=	$(addprefix $(SRCDIR)/,$(SRCFILES))
OBJS			=	$(addprefix $(OBJDIR)/,$(SRCFILES:.c=.o))
DEBUGOBJS		=	$(addprefix $(DEBUGDIR)/,$(SRCFILES:.c=.o))

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS			=	crs
RM				=	rm -rf

$(OBJDIR)/%.o	:	$(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $*.c -o $@

$(DEBUGDIR)/%.o	:	$(SRCDIR)/%.c | $(DEBUGDIR)
	$(CC) $(CFLAGS) -g -c $*.c -o $@

all				:	$(NAME)

bonus			:	all

$(NAME)			:	$(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

debug			:	$(NAME).debug

$(NAME).debug	:	$(DEBUGOBJS)
	$(AR) $(ARFLAGS) $(NAME).debug $(DEBUGOBJS)

$(OBJDIR)		:
	mkdir $(OBJDIR)

$(DEBUGDIR)		:
	mkdir $(DEBUGDIR)

clean			:
	$(RM) $(OBJDIR) $(DEBUGDIR)

fclean			:	clean
	$(RM) $(NAME) $(NAME).debug

re				:	fclean all

.PHONY			:	clean fclean re
