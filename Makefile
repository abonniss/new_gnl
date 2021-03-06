#NAME
NAME = gnl

#COMPILER
CC = clang

#COMPILER FLAGS
CFLAGS += -Wall
CFLAGS += -Wextra

#ERROR FLAGS
ifneq ($(err), no)
	CFLAGS += -Werror
endif

#DEBUG FLAGS
ifeq ($(debug), 0)
	CFLAGS += -g3
else ifeq ($(debug), 1)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address
else ifeq ($(debug), 2)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -Weverything
endif

#DEBUGS SYMBOLS
DSYM += $(NAME).dSYM 

#INCLUDES 
INCLUDES += includes

#LIB 
PATH_LIB = libftprintf
LIB = $(PATH_LIB)/libftprintf.a
INCLUDES_LIB = ./$(PATH_LIB)/includes
LIB_NAME = ftprintf

#PATH_SOURCES 
PATH_SRCS = srcs

#SOURCES
SRCS += get_next_line_2.c
SRCS += main.c

#HEADERS
HEADERS += get_next_line_2.h

#VPATH
vpath %.c $(PATH_SRCS)
vpath %.h $(INCLUDES)

#OBJS
PATH_OBJS = objs
OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

#COLORS PRINT
NC 		= \033[0m
GREEN 	= \033[32m
CYAN 	= \033[36m
RED 	= \033[31m
ONELINE = \e[1A\r


#RULES 

all: $(NAME)

$(NAME): $(LIB) $(LIBMLX) $(PATH_OBJS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDES) -I $(INCLUDES_LIB) -L $(PATH_LIB) -l$(LIB_NAME) -o $@
	printf "$(GREEN)$@ IS READY\n$(NC)"									

$(LIB): FORCE
	#make -C libftprintf 
	$(MAKE) -C $(PATH_LIB) 


FORCE: 
	#permet de forcer la réalisationn de la lib

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -I $(INCLUDES_LIB) -I $(INCLUDES) -c $< -o $@
	printf "$(CYAN)$< IS COMPILING                                 \n$(NC)"

$(PATH_OBJS):
	mkdir $@

clean:
	$(MAKE) -C $(PATH_LIB) clean 
	$(RM) -R $(PATH_OBJS) $(DSYM)
	printf "$(RED)IT'S CLEAN\n$(NC)"

fclean: clean
	$(MAKE) -C $(PATH_LIB) fclean 
	$(RM) $(NAME)
	printf "$(RED)$(NAME) REMOVED\n$(NC)"

re: fclean
	$(MAKE) -C $(PATH_LIB) re 
	$(MAKE)

.PHONY: clean fclean re all FORCE 

.SILENT: 
