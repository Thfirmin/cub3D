# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 20:10:53 by marvin            #+#    #+#              #
#    Updated: 2023/05/06 23:35:23 by thfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# +>                                     NAME

NAME		= libmlx.a

OS			= $(shell uname)
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     PATH

MLX_PTH		= mlx-$(OS)/

MLX_HEADER	= mlx.h
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    ALIASES 

ifeq ($(OS),Linux)
MLXFLAGS	= -lXext -lX11 -lz
DEF			= -D ISLINUX=1
else ifeq ($(OS),Darwin)
MLXFLAGS	= -framework OpenGL -framework AppKit
DEF			= -D ISLINUX=0
endif
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     CODES 

BLANK			= \e[m
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

all:	update_tools $(NAME) import_header

update_tools:
	make -C $(MLX_PTH) && sleep 0.5

$(NAME): $(MLX_PTH)$(NAME)
	cp $(MLX_PTH)$(NAME) .

import_header:
ifeq (,$(shell ls $(MLX_HEADER) 2> /dev/null))
	cp $(MLX_PTH).$(MLX_HEADER) ./$(MLX_HEADER)
endif

clean:
	make -C $(MLX_PTH) clean

fclean: clean
ifneq (,$(shell ls $(NAME) 2> /dev/null))
	rm -rf $(NAME)
endif
ifneq (,$(shell ls $(MLX_HEADER) 2> /dev/null))
	rm -rf $(MLX_HEADER)
endif

re:	fclean all

.PHONY: all re mclean tclean clean fclean update_tools debug
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# vim: fdm=marker fmr=+>,<+ ts=4 sw=4 nofen noet:
