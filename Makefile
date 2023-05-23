
GREY		:= \e[1;30m
RED			:= \e[1;31m
GREEN		:= \e[1;32m
YELLOW		:= \e[1;33m
BLUE		:= \e[1;34m
MAGENTA		:= \e[1;35m
CYAN		:= \e[1;36m
WHITE		:= \e[1;37m

BOLD		:= \e[1m
DIM			:= \e[2m	
UNDERLINE	:= \e[4m
BLINK		:= \e[5m
INVERTED	:= \e[7m
END			:= \e[0m



NAME 		:= push_swap

SRC_DIR 	:= src
SRCS 		:= base/utils.c base/ft_push.c base/ft_check_stack.c base/ft_reverse_rotate.c \
				base/ft_rotate.c base/ft_swap.c base/ft_min.c base/ft_sort3.c base/ft_index.c \
				base/ft_big_numbers.c base/ft_move_operations.c base/push_swap.c \
				libft/ft_arrlen.c libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c \
				libft/ft_intlen.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c \
				libft/ft_isdigit.c libft/ft_isprint.c libft/ft_isspace.c libft/ft_itoa.c \
				libft/ft_lstadd_back.c libft/ft_lstadd_front.c libft/ft_lstclear.c \
				libft/ft_lstdelone.c libft/ft_lstiter.c libft/ft_lstlast.c libft/ft_lstmap.c \
				libft/ft_lstnew.c libft/ft_lstsize.c libft/ft_memchr.c libft/ft_memcmp.c \
				libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_printf.c \
				libft/ft_putchar_fd.c libft/ft_putcharpf.c libft/ft_putendl_fd.c \
				libft/ft_puthexpf.c libft/ft_putnbr_fd.c libft/ft_putnbrpf.c libft/ft_putptrpf.c \
				libft/ft_putstr_fd.c libft/ft_putstrpf.c libft/ft_putunbrpf.c libft/ft_split.c \
				libft/ft_strchr.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlcat.c \
				libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c \
				libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c \
				libft/ft_tolower.c libft/ft_toupper.c libft/get_next_line.c \
				libft/get_next_line_utils.c libft/ft_swap.c

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR   := .build
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)
DEBUG		:= *.txt *.out

CC 			:= cc
CFLAGS 		:= -Wall -Wextra -Werror -g 
CPPFLAGS	:= -MMD -MP -I include
AR			:= ar
ARFLAGS		:= -r -c -s

RM			:= rm -rf
MAKEFLAGS   += --no-print-directory
DIR_DUP	 = mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\e[2K\r $(YELLOW)Compiling $(NAME)$(END)\n"
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@printf "\e[2K\r $(GREEN)Generated $(NAME)$(END)\n"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(DIR_DUP)
	@printf "\e[2K\r $(YELLOW)Compiling $< $(END)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

-include $(DEPS)

clean:
	@printf "\e[2K\r $(RED)Cleaning objects from $(NAME)$(END)\n"
	@$(RM) $(OBJS) $(DEPS) $(BUILD_DIR)

fclean: clean
	@printf "\e[2K\r $(RED)Cleaning executable from $(NAME)$(END)\n"
	@$(RM) $(NAME) $(DEBUG)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: clean fclean re all
