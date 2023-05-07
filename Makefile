# +>                                   NAMES                                 

# Name of gerated program
NAME	= cub3D
# Operational Sytem
OS		= $(shell uname)
# Shell interpreter
SH		= $(shell echo ${SHELL} | sed "s/.*\///g")

# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                   LOCAL

# Local settings, Put your own settings and additional flags here

# Directory name to header files (*.h)
INC_PTH	= includes

# Directory name to source files (*.c)
SRC_PTH	= srcs

# Directory name to Ooject files (*.o)
OBJ_PTH	= objs

# Directory name to Library files (*.a)
LIB_PTH	= libs

# User flags to compilation (ex. -Wall)
UCFLAGS	=

# User flags to include (ex. -I includes)
UIFLAGS	=

# User flags to links (ex. -L. -lft)
ifeq ($(OS),Darwin)
	ULFLAGS	=-framework OpenGL -framework AppKit -lm
else ifeq ($(OS),Linux)
	ULFLAGS	=-lXext -lX11 -lz -lm
endif

# User flags to debug (ex. -g -fsanitize=address)
UDFLAGS	=

# User flags to optimization (ex. -o3)
UOFLAGS	=

# User flags to defines (ex. -D BUFFER_SIZE=42)
UDEFINS	=

# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                 SET PATHS

# Directory tree mounting system [DON'T TOUCH IT!!!]
INC_TREE	= $(shell ls -d $(INC_PTH) 2> /dev/null) $(shell find $(LIB_PTH) -type f 2> /dev/null | tr ' ' '\n' | grep \\.h$$ | sed "s/[^/]*\.h$$//g" | uniq)
SRC_TREE	= $(shell echo $(SRCS) | tr ' ' '\n' | sed "s/[^/]*\.c$$//g" | uniq)
OBJ_TREE	= $(subst $(SRC_PTH),$(OBJ_PTH),$(SRC_TREE))
LIB_TREE	= $(shell find $(LIB_PTH) -mindepth 1 -maxdepth 1 -type d 2> /dev/null | sed "s/.*\///g")


# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                  SOURCES

# Wildcard  implemention without wildcard operator [DON'T TOUCH IT!!!]
SRCS	= $(shell find ${SRC_PTH} -type f 2> /dev/null | tr ' ' '\n' | grep \\.c$$)

OBJS	= $(subst $(SRC_PTH),$(OBJ_PTH),$(subst .c,.o,$(SRCS)))

# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                   CONFIG

# Standard 42 compilation flags
ACFLAGS =-Wall -Wextra -Werror

# Linker flags generator [DON'T TOUCH IT!!!]
ALFLAGS	=$(foreach lib, $(LIB_TREE), -L$(LIB_PTH)/$(lib) -l$(subst lib,,$(lib)))

# Include flags generator [DON'T TOUCH IT!!!]
AIFLAGS	=$(foreach inc, $(INC_TREE), -I$(inc))

# Some defines to easy compile 42 projects
ADEFINS	=-D __GNU_SOURCE

# Verbose System
MAKEFLAGS	+= --no-print-directory
ifneq (1,$(LOG))
	MAKEFLAGS += --silent
endif
ifneq (,$(LOG))
	export REDIR = &> /dev/null
endif

# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                  ALIASES

OTOC		= $(subst $(OBJ_PTH),$(SRC_PTH),$(subst .o,.c,$@))

NULL		= \e[m
RED			= \e[38;5;9m
YELLOW		= \e[38;5;11m
GREEN		= \e[38;5;2m
BLUE		= \e[38;5;6m
PURPLE		= \e[38;5;5m
PINK		= \e[38;5;13m
WHITE		= \e[38;5;15m

BOLD		= \e[1m
SHADOW		= \e[2m
ITALIC		= \e[3m
UNDLINE		= \e[4m
UPPLINE		= \e[53m
DUNDLINE	= \e[21m
CENSORED	= \e[9m
UPALIGN		= \e[73m
DWALIGN		= \e[74m
FULLER		= \e[7m
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    ENVS

CC		=cc
CFLAGS	=$(ACFLAGS) $(UCFLAGS)
LFLAGS	=$(ALFLAGS) $(ULFLAGS) 
IFLAGS	=$(AIFLAGS) $(UIFLAGS)
OFLAGS	=$(AOFLAGS) $(UOFLAGS)
DFLAGS	=$(ADFLAGS) $(UDFLAGS)
DEFINS	=$(ADEFINS) $(UDEFINS)
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                   SCRIPT

all:	$(OBJ_TREE) lib_update $(NAME)

$(OBJ_TREE):
	mkdir -p $@

lib_update:
	$(foreach libs, $(LIB_TREE), make -C $(LIB_PTH)/$(libs);)

$(NAME):	$(OBJS)
ifneq (,$(OBJS))
	@printf "[${YELLOW}${BOLD}INFO${NULL}] ${UNDLINE}Compiling${NULL} ${NAME}\n" $(REDIR)
	$(CC) $(CFLAGS) $(DFLAGS) $(OFLAGS) $(IFLAGS) $(OBJS) $(LFLAGS) -o $(NAME) 
	@printf "[${GREEN}${BOLD}INFO${NULL}] ${BOLD}Compiled ${NAME}${NULL}\n" $(REDIR)
endif

$(OBJS):	$(SRCS)
	@if [ "$(OTOC)" = "$(findstring $(OTOC),$?)" ]; then \
		if [ "$(LOG)" = "1" ]; then \
			printf "$(CC) $(CFLAGS) $(IFLAGS) $(DFLAGS) $(OFLAGS) -c $(OTOC) -o $@\n"; \
		fi; \
		$(CC) $(CFLAGS) $(IFLAGS) $(DFLAGS) $(OFLAGS) -c $(OTOC) -o $@; \
	else \
		touch $@; \
	fi

clean:
ifneq (,$(shell ls -d $(OBJ_PTH) 2> /dev/null))
	@printf "[${YELLOW}${BOLD}INFO${NULL}] ${UNDLINE}Deleting${NULL} ${NAME} objects\n" $(REDIR)
	rm -rf $(OBJ_PTH)
	@printf "[${BLUE}${BOLD}INFO${NULL}] ${BOLD}Deleted ${NAME} objects${NULL}\n" $(REDIR)
endif

fclean:	clean
	$(foreach libs, $(LIB_TREE), make -C $(LIB_PTH)/$(libs) fclean;)
ifneq (,$(shell ls $(NAME) 2> /dev/null))
	@printf "[${YELLOW}${BOLD}INFO${NULL}] ${UNDLINE}Deleting${NULL} ${NAME}\n" $(REDIR)
	rm -rf $(NAME)
	@printf "[${RED}${BOLD}INFO${NULL}] ${BOLD}Deleted ${NAME}${NULL}\n" $(REDIR)
endif

re:	fclean all

help:
	printf "| LEX MAKEFILE COMPILE HELP |\n|\n";
	printf "| > To compile use 'make'\n|\n";
	printf "| > To compile with your own flags you have two ways for it:\n";
	printf "|\t+ Set it in Makefile [LOCAL] section_\n|\t\t(The proper flag in the proper place of preference).\n|\n";
	printf "|\t+ Compile as command argument_\n|\t\tEx. make all UDFLAGS=\"-g -fsanitize=thread\" UOFLAGS=-o.\n|\n";
	printf "|\t! If you are using this flag for testing and don't intend_\n|\t\tto use it every time, I recommend using it as an_\n|\t\targument rather than setting it in the file directly.\n|\n";
	printf "| > To compile with debug flags use {UDFLAGS} var\n|\t+ ex: make re UDFLAGS=\"-g -fsanitize=address\".\n|\n";
	printf "| > To compile with otimization flags use {UOFLAGS} var\n|\t+ ex: make re UDFLAGS=\"-g -fsanitize=address\" UOFLAGS=-o3.\n|\n";
	printf "| > To compile a option in libraries compilation, create a flag named {LIBFLAGS} var\n|\t+ ex: make all LIBFLAGS=re.\n|\n";
	printf "| > To compile a option in a specifc library, create a flag named {<UPPERCASED LIB_NAME>LIBFLAGS} var\n|\t+ ex: make all LIBFTLIBFLAGS=bonus.\n|\n";
	printf "| > To control verbose mode use {LOG} var\n|\t+ ex: make LOG=0\n|\t! LOG => { null = std | 0 = silent | 1 = full log }.\n|\n";
	printf "| * If you'll use a flag repetitively, you can set this flag_\n|\tin Makefile in \"LOCAL\" field.\n|\n";
	printf "| * (be careful with the flag name).\n|\n";
	printf "|\t     \e[1;2;3mLex project(2023) - Vila Arejo\e[m\n";
	printf "|\t\e[1;2;3mThiago F.(thfirmin) & Thawan C.(Tde-souz)\e[m\n";

.PHONY: all lib_update mclean clean fclean re
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# vim: fdm=marker fmr=+>,<+ ts=4 sw=4 nofen noet:
