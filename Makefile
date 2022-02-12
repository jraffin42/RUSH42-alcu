# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 14:25:17 by jraffin           #+#    #+#              #
#    Updated: 2022/02/12 08:01:54 by jraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL				=	/bin/sh

PROGNAME			:=	alcu
PROGNAME_BONUS		:=	visualizer

INCLUDEDIR			:=	inc
SRCDIR				:=	src

OBJDIR				:=	./obj
DEBUGDIR			:=	./debugobj

COMMONSRCS			:=	main.c				\
						board.c				\
						get_next_line.c		\
						utils.c				\

NOBONUSSRCS			:=

BONUSSRCS			:=

CC					:=	cc
RM					:=	rm

CCFLAGS				:=	-Wall -Wextra -Werror
LIBFLAGS			:=
#SANITIZE			:=	-fsanitize=thread
#SANITIZE			+=	-fsanitize=address
#SANITIZE			+=	-fsanitize=undefined
#SANITIZE			+=	-fsanitize=memory
OPTFLAG				:=

NAME				:=	$(PROGNAME)
BONUSNAME			:=	$(PROGNAME_BONUS)

OUTDIR				:=	$(OBJDIR)

DEBUGNAME			:= $(addsuffix .debug,$(PROGNAME))
BONUSDEBUGNAME		:= $(addsuffix .debug,$(PROGNAME_BONUS))

ifdef DEBUG
	OPTFLAG 		:=	-g
	LIBFT			:=	$(addsuffix .debug,$(LIBFT))
	NAME			:=	$(DEBUGNAME)
	BONUSNAME		:=	$(BONUSDEBUGNAME)
	OUTDIR			:=	$(DEBUGDIR)
endif

$(OUTDIR)/%.o		:	$(SRCDIR)/%.c | $(OUTDIR)
	@mkdir -p $(dir $@)
	$(CC) -c -MMD -MP $(CCFLAGS) $(OPTFLAG) $(SANITIZE) $(addprefix -I ,$(INCLUDEDIR)) $< -o $@

$(NAME)				:	$(addprefix $(OUTDIR)/,$(COMMONSRCS:.c=.o)) $(addprefix $(OUTDIR)/,$(NOBONUSSRCS:.c=.o)) $(LIBFT) $(MLX)
	$(CC) $(CCFLAGS) $(OPTFLAG) $(SANITIZE) -o $(NAME) $(addprefix $(OUTDIR)/,$(COMMONSRCS:.c=.o)) $(addprefix $(OUTDIR)/,$(NOBONUSSRCS:.c=.o)) $(LIBFLAGS)

$(BONUSNAME)		:	$(addprefix $(OUTDIR)/,$(COMMONSRCS:.c=.o)) $(addprefix $(OUTDIR)/,$(BONUSSRCS:.c=.o)) $(LIBFT) $(MLX)
	$(CC) $(CCFLAGS) $(OPTFLAG) $(SANITIZE) -o $(BONUSNAME) $(addprefix $(OUTDIR)/,$(COMMONSRCS:.c=.o)) $(addprefix $(OUTDIR)/,$(BONUSSRCS:.c=.o)) $(LIBFLAGS)

all					:	$(NAME) $(BONUSNAME)

bonus				:	$(BONUSNAME)

$(DEBUGNAME)		:
ifndef DEBUG
	$(MAKE) $(DEBUGNAME) DEBUG=1
endif

$(BONUSDEBUGNAME)	:
ifndef DEBUG
	$(MAKE) $(BONUSDEBUGNAME) DEBUG=1
endif

ifdef DEBUG
$(PROGNAME)			:	$(NAME)
$(PROGNAME_BONUS)	:	$(BONUSNAME)
endif

debug				:
ifndef DEBUG
	$(MAKE) DEBUG=1
endif

$(OUTDIR)			:
	mkdir $(OUTDIR)

clean				:
	$(RM) -rf $(OBJDIR) $(DEBUGDIR)

fclean				:	clean
	$(RM) -f $(PROGNAME) $(PROGNAME_BONUS) $(DEBUGNAME) $(BONUSDEBUGNAME)

re					:	fclean $(NAME)

.PHONY				:	all clean fclean re

-include	$(addprefix $(OUTDIR)/,$(SRCS:.c=.d))
