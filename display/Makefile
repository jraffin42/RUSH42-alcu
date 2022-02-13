
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 12:57:20 by wszurkow          #+#    #+#              #
#    Updated: 2021/12/22 16:51:46 by wszurkow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES ############
NAME			= a.out
EXTENSION		= c
CC				= gcc
DIR_HEADER		= ./
DIR_SRCS 		= ./
FLAGS			= -Wall -Wextra -Werror -lncurses
RM				= /bin/rm -f
#SANITIZER		= -fsanitize=address -fsanitize=leak
OBJS			= ${SRCS_FILES:.${EXTENSION}=.o}
SRCS_FILES	    = \
				  ./main.c\
				  ./display_board.c \
				  ./display_get.c \
				  ./display_init.c \
				  ./display_put.c \
				  ./readline_ncurse.c \

# OS SETTINGS ###########
OS				= $(shell uname -r | grep arch)
ifeq (${OS}, "")
	ECHO = echo
else
	ECHO = echo -e
endif

ECHO = printf

# RULES #################
all:		${NAME}

%.o: %.${EXTENSION}
	@${ECHO} "${Y}[ COMPILING OBJ] ${_R}"
	${CC} ${FLAGS} -I ${DIR_HEADER} -o $@ -c $<

${NAME}: ${OBJS}
	@${ECHO} "${BLUE}[ COMPILING BIN] ${_R}"
	${CC} ${FLAGS} -I ${DIR_HEADER} -o ${NAME} ${OBJS} ${SANITIZER}
	@${ECHO} "${G}[ DONE] ${_R}\n"
	@${ECHO} "${G}└─ ./${NAME}${_R}\n"

clean:
	@${ECHO} "${R}[ CLEAN] ${_R}        "
	${RM} ${OBJS}

fclean:		clean
	@${ECHO} "${R}[ FCLEAN] ${_R}       "
	${RM} ${NAME}

re:			fclean all

.PHONY:\
	all fclean clean re \

# COLORS ################
BLACK			=	\033[0;30m
R				=	\033[0;31m
G				=	\033[0;32m
ORANGE			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
LIGHT_GRAY		=	\033[0;37m
DARK_GRAY		=	\033[1;30m
LIGHT_RED		=	\033[1;31m
LIGHT_GREEN		=	\033[1;32m
Y				=	\033[1;33m
LIGHT_BLUE		=	\033[1;34m
LIGHT_PURPLE	=	\033[1;35m
LIGHT_CYAN		=	\033[1;36m
WHITE			=	\033[1;37m
NO_COLOR		=	\033[0m
BOLD			=	\e[1m
_R				=	\e[0m

# MISC #################
#Auto update
#@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(GREEN)Compiled [√]$(RESET)\n"
# use "\r" on printf to clear current line
