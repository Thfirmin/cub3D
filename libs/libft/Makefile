# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfirmin <thiagofirmino2001@gmail.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 21:07:07 by thfirmin          #+#    #+#              #
#    Updated: 2023/06/30 00:19:36 by thfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# +>                                     NAME 

NAME	= libft.a

export MASTERLIB	= $(addprefix $(PTH_HERE),$(NAME))
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     PATHS 

PTH_SRC		= srcs/
PTH_HERE	= $(shell pwd)/
PTH_INC		= includes/
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    SOURCES 

SRCS	= $(shell ls $(PTH_SRC))
LIBS	= $(shell find $(PTH_SRC) -mindepth 1 -maxdepth 1 -type d)
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    CONFIG

export IFLAGS	= -I$(PTH_HERE) -I$(PTH_HERE)$(PTH_INC)
MAKEFLAGS		+= --no-print-directory

ifneq (1, $(LOG))
	MAKEFLAGS += --silent
endif
ifneq (,$(LOG))
	export REDIR = > /dev/null
endif
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     CODES 

NULL			= \e[m
RED				= \e[38;5;9m
YELLOW			= \e[38;5;11m
GREEN			= \e[38;5;2m
BLUE			= \e[38;5;6m
PURPLE			= \e[38;5;5m
PINK			= \e[38;5;13m
WHITE			= \e[38;5;15m

STRONG			= \e[1m
SHADOW			= \e[2m
ITALIC			= \e[3m
UNDLINE			= \e[4m
UPPLINE			= \e[53m
DUNDLINE		= \e[21m
CENSORED		= \e[9m
UPALIGN			= \e[73m
DWALIGN			= \e[74m
FULLER			= \e[7m
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     RULES 

all:	$(SRCS)

$(SRCS):
	make -C $(PTH_SRC)$@ && sleep 1

bonus:
	$(foreach lib, $(LIBS), make bonus -C $(lib);)

mclean:
	$(foreach lib, $(LIBS), make mclean -C $(lib);)

bclean:
	$(foreach lib, $(LIBS), make bclean -C $(lib);)

clean:
	$(foreach lib, $(LIBS), make clean -C $(lib);)

fclean:	clean
ifneq (,$(shell ls $(MASTERLIB) 2> /dev/null))
	@printf "[${YELLOW}${BOLD}INFO${NULL}] ${UNDLINE}Deleting${NULL} ${NAME} library\n" $(REDIR)
	rm -rf $(MASTERLIB)
	@printf "[${RED}${BOLD}INFO${NULL}] ${NAME} library ${BOLD}Deleted${NULL}\n" $(REDIR)
endif

bre: fclean bonus

re: fclean all

.PHONY:		all update_libs bonus mclean bclean clean fclean re bre
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# vim: fdm=marker fmr=+>,<+ ts=4 sw=4 nofen noet:
