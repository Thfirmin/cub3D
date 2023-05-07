# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/01 20:52:29 by thfirmin          #+#    #+#              #
#    Updated: 2023/04/27 11:38:46 by thfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# +>                                     NAMES 

NAME	= $(MASTERLIB)

PROJ	= libftprintf
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    CONFIG

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    SOURCES 

SRCS	= ft_printf.c \
		  ft_puthex_fd.c \
		  ft_putunbr_fd.c

OBJS	= $(SRCS:.c=.o)
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

BOLD			= \e[1m
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

.c.o:
	$(CC) $(CFLAGS) $(DFLAGS) $(OFLAGS) $(IFLAGS) -c $< $(LFLAGS) -o $(<:.c=.o)

all:	$(NAME)

re:		fclean all
.PHONY: all clean fclean re
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                   MANDATORY

$(NAME):	$(OBJS)
	@printf "[${YELLOW}${BOLD}INFO${NULL}] ${UNDLINE}Compiling${NULL} ${PROJ} dependency\n" $(REDIR)
	ar -rcs $(MASTERLIB) $(OBJS)
	ranlib $(MASTERLIB)
	@printf "[${GREEN}${BOLD}INFO${NULL}] ${PROJ} dependency ${BOLD}Compiled${NULL}\n" $(REDIR)

mclean:
ifneq (,$(shell ls $(OBJS) 2> /dev/null))
	@printf "[${YELLOW}${BOLD}INFO${NULL}] ${UNDLINE}Deleting${NULL} ${PROJ} objects\n" $(REDIR)
	rm -rf $(shell ls $(OBJS) 2> /dev/null)
	@printf "[${BLUE}${BOLD}INFO${NULL}] ${PROJ} objects ${BOLD}Deleted${NULL}\n" $(REDIR)
endif
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     BONUS

bonus:	all

bclean: mclean

bre:	fclean bonus
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     CLEAN 

clean:	mclean bclean

fclean:	clean
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# vim: fdm=marker fmr=+>,<+ ts=4 sw=4 nofen noet
