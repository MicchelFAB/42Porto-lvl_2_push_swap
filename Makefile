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

NAME		:= push_swap
NAME_B		:= checker

SRC_DIR		:= src/base
SRC_LIB		:= src/libft
SRCS		:= utils.c ft_push.c ft_check_stack.c ft_reverse_rotate.c \
				ft_rotate.c ft_swap.c ft_index.c ft_big_numbers.c \
				ft_less_movement.c 
SRCS_P		:= push_swap.c
SRCS_B		:= ft_checker.c 

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
SRCS_P		:= $(SRCS_P:%=$(SRC_DIR)/%)
SRCS_B		:= $(SRCS_B:%=$(SRC_DIR)/%)

BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/obj/%.o)
OBJS_B		:= $(SRCS_B:$(SRC_DIR)/%.c=$(BUILD_DIR)/obj/%.o)
OBJS_P		:= $(SRCS_P:$(SRC_DIR)/%.c=$(BUILD_DIR)/obj/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
CPPFLAGS	:= -MMD -MP -I include

RM			:= rm -rf
MAKEFLAGS	+= --no-print-directory
MKDIR_P		:= mkdir -p

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_P) $(BUILD_DIR)/libft/libft.a
	@printf "\e[2K\r$(GREEN)Generated $(NAME)$(END)\n"
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(OBJS_P) -L$(BUILD_DIR)/libft -lft -o $(NAME)

$(BUILD_DIR)/libft/libft.a:
	@make -C $(SRC_LIB)
	@cp $(SRC_LIB)/libft.a $(BUILD_DIR)/libft/libft.a

$(BUILD_DIR)/obj/%.o: $(SRC_DIR)/%.c $(BUILD_DIR)
	@printf "\e[2K\r$(YELLOW)Compiling $<$(END)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

-include $(DEPS)

$(BUILD_DIR):
	@$(MKDIR_P) $(BUILD_DIR)/libft $(BUILD_DIR)/obj

bonus: $(NAME_B)

$(NAME_B): $(OBJS) $(OBJS_B) $(BUILD_DIR)/libft/libft.a
	@printf "\e[2K\r$(BLUE)Generated $(NAME_B)$(END)\n"
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(OBJS_B) -L$(BUILD_DIR)/libft -lft -o $(NAME_B)

clean:
	@printf "\e[2K\r$(RED)Cleaning objects from $(NAME)$(END)\n"
	@make -C $(SRC_LIB) clean
	@$(RM) $(OBJS) $(DEPS) $(BUILD_DIR)

fclean: clean
	@printf "\e[2K\r$(RED)Cleaning executables from $(NAME)$(END)\n"
	@make -C $(SRC_LIB) fclean
	@$(RM) $(NAME) $(NAME_B)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: clean fclean re all
