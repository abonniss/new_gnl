#NAME
NAME = libftprintf.a

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
INCLUDES += includes/

#PATH SOURCES 
PATHSOURCES_LIBFT = srcs/libft/ 
PATHSOURCES_FTPRINTF = srcs/ft_printf/ 
PATHSOURCES_BUFFER = srcs/buffer/ 
PATHSOURCES_STACK = srcs/stack/ 
PATHSOURCES_GNL = srcs/get_next_line/ 

#SOURCES
SRCS += ft_absolute.c
SRCS += ft_add_prefix.c
SRCS += ft_atoi.c
SRCS += ft_bzero.c
SRCS += ft_calloc.c
SRCS += ft_isalnum.c
SRCS += ft_isalpha.c
SRCS += ft_isascii.c
SRCS += ft_isdigit.c
SRCS += ft_isprint.c
SRCS += ft_is_uppercase.c
SRCS += ft_is_lowercase.c
SRCS += ft_isnumber.c
SRCS += ft_isinteger.c
SRCS += ft_itoa.c
SRCS += ft_memalloc.c
SRCS += ft_memccpy.c
SRCS += ft_memchr.c
SRCS += ft_memcmp.c
SRCS += ft_memcpy.c
SRCS += ft_memmove.c
SRCS += ft_memset.c
SRCS += ft_putchar_fd.c
SRCS += ft_putendl_fd.c
SRCS += ft_putnbr_fd.c
SRCS += ft_putstr_fd.c
SRCS += ft_split.c
SRCS += ft_strchr.c
SRCS += ft_strcpy.c
SRCS += ft_strncpy.c
SRCS += ft_strdup.c
SRCS += ft_strjoin.c
SRCS += ft_strlcat.c
SRCS += ft_strlcpy.c
SRCS += ft_strlen.c
SRCS += ft_strmapi.c
SRCS += ft_strncmp.c
SRCS += ft_strnstr.c
SRCS += ft_strrchr.c
SRCS += ft_strtrim.c
SRCS += ft_substr.c
SRCS += ft_strsep.c
SRCS += ft_strclen.c
SRCS += ft_strcdup.c
SRCS += ft_to_lowercase.c
SRCS += ft_to_uppercase.c
SRCS += ft_str_to_uppercase.c
SRCS += ft_str_to_lowercase.c

SRCS_BUFFER += create_buffer.c
SRCS_BUFFER += push_str_buffer.c
SRCS_BUFFER += push_char_buffer.c
SRCS_BUFFER += reset_buffer.c
SRCS_BUFFER += resize_buffer.c
SRCS_BUFFER += delete_buffer.c

SRCS_PRINTF += ft_printf.c
SRCS_PRINTF += ft_ltoabase.c
SRCS_PRINTF += state_machine.c
SRCS_PRINTF += conv.c
SRCS_PRINTF += conv_duixx.c

SRCS_PRINTF_BONUS += ft_printf.c
SRCS_PRINTF_BONUS += ft_ltoabase.c
SRCS_PRINTF_BONUS += manage_buffer.c
SRCS_PRINTF_BONUS += state_machine_bonus.c
SRCS_PRINTF_BONUS += conv_bonus.c
SRCS_PRINTF_BONUS += conv_duixx_bonus.c

SRCS_STACK += stack_create.c
SRCS_STACK += stack_reverse_rotate.c
SRCS_STACK += stack_pop.c
SRCS_STACK += stack_rotate.c
SRCS_STACK += stack_exchange.c
SRCS_STACK += stack_print.c
SRCS_STACK += stack_create_node.c
SRCS_STACK += stack_swap.c
SRCS_STACK += stack_push_all.c
SRCS_STACK += stack_get_root_node.c
SRCS_STACK += stack_get_number.c
SRCS_STACK += stack_get_position.c
SRCS_STACK += stack_push.c
SRCS_STACK += stack_destroy.c

SRCS_GNL += ft_get_next_line.c
SRCS_GNL += ft_get_next_line_utils.c


#HEADERS

HEADERS += libftprintf.h
HEADERS += libft.h
HEADERS += ft_printf.h
HEADERS += buffer.h
HEADERS += stack.h
HEADERS += get_next_line.h

#VPATH

vpath %.c $(PATHSOURCES_LIBFT)
vpath %.c $(PATHSOURCES_FTPRINTF)
vpath %.c $(PATHSOURCES_BUFFER)
vpath %.c $(PATHSOURCES_STACK)
vpath %.c $(PATHSOURCES_GNL)
vpath %.h $(INCLUDES)

#OBJS

PATHOBJS = objs/
PATHOBJS_BONUS = objs_bonus/

OBJS += $(patsubst %.c, $(PATHOBJS)%.o, $(SRCS))
OBJS += $(patsubst %.c, $(PATHOBJS)%.o, $(SRCS_PRINTF))
OBJS += $(patsubst %.c, $(PATHOBJS)%.o, $(SRCS_BUFFER))
OBJS += $(patsubst %.c, $(PATHOBJS)%.o, $(SRCS_STACK))
OBJS += $(patsubst %.c, $(PATHOBJS)%.o, $(SRCS_GNL))
OBJS_BONUS += $(patsubst %.c, $(PATHOBJS_BONUS)%.o, $(SRCS))
OBJS_BONUS += $(patsubst %.c, $(PATHOBJS_BONUS)%.o, $(SRCS_PRINTF_BONUS))
OBJS_BONUS += $(patsubst %.c, $(PATHOBJS_BONUS)%.o, $(SRCS_BUFFER))

#RULES 

all: $(NAME)

$(NAME): $(PATHOBJS) $(OBJS)
	ar rcs $@ $(OBJS) 
	printf "\033[32mCompilation OK\n\033[0m"

$(OBJS): $(PATHOBJS)%.o: %.c $(HEADERS) Makefile 
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(OBJS_BONUS): $(PATHOBJS_BONUS)%.o: %.c $(HEADERS) Makefile 
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(PATHOBJS): 
	mkdir $@

$(PATHOBJS_BONUS): 
	mkdir $@

clean: 
	$(RM) -R $(OBJS) $(OBJS_BONUS) $(PATHOBJS) $(PATHOBJS_BONUS) $(DSYM)
	printf "Clean OK\n"

fclean: clean 
	$(RM) $(NAME)
	printf "fclean OK\n"

re: fclean
	$(MAKE)

bonus: $(PATHOBJS_BONUS) $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS) 
	printf "\033[32mCompilation OK\n\033[0m"

test: all 
	$(CC) $(CFLAGS) -I $(INCLUDES) -L ./ -l ftprintf TestPF.c -o Tester
	printf "\033[32mTest OK\n\033[0m"

test_bonus: bonus
	$(CC) $(CFLAGS) -I $(INCLUDES) -L ./ -l ftprintf TestPF.c -o Tester
	printf "\033[32mTest OK\n\033[0m"

.PHONY: clean fclean re all

.SILENT: 
