# 
# 
NAME 		:= dummy.a

SRC_DIR 	:= src
SRCS 		:=		base/ft_check_double.c base/ft_check_int.c base/ft_push.c\
				base/ft_reverse_rotate.c base/ft_rotate.c base/ft_swap.c \
				 base/utils.c \
					libft/ft_arrlen.c libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c \
				libft/ft_intlen.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c \
				libft/ft_isdigit.c libft/ft_isprint.c libft/ft_isspace.c libft/ft_itoa.c \
				libft/ft_lstadd_back.c libft/ft_lstadd_front.c libft/ft_lstclear.c \
				libft/ft_lstdelone.c libft/ft_lstiter.c libft/ft_lstlast.c libft/ft_lstmap.c \
				libft/ft_lstnew.c libft/ft_lstsize.c libft/ft_memchr.c libft/ft_memcmp.c \
				libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_printf.c \
				libft/ft_putchar_fd.c libft/ft_putcharpf.c libft/ft_putendl_fd.c base/ft_sort3.c\
				libft/ft_puthexpf.c libft/ft_putnbr_fd.c libft/ft_putnbrpf.c libft/ft_putptrpf.c \
				libft/ft_putstr_fd.c libft/ft_putstrpf.c libft/ft_putunbrpf.c libft/ft_split.c \
				libft/ft_strchr.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlcat.c \
				libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c \
				libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c \
				libft/ft_tolower.c libft/ft_toupper.c libft/get_next_line.c \
				libft/get_next_line_utils.c

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR   := .build
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

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
	$(AR) $(ARFLAGS) $(NAME) $(OBJS) 
	$(info GERADO $(NAME))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info GERADO $@)

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS) $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re
.SILENT:

#JUNK_PATH		=	./junk
#LIBFT			=	$(LIBFT_PATH)/libft.a

#SRC_JUNK		=	$(JUNK_PATH)(wildcard *.c)
#SRC 			=	$(wildcard *.c)


#OBJ-S = $(SRC:.c=.o)
#OBJ-J = $(SRC_JUNK:.c=.o)

#NAME = $(PUSH)



#$(LIBFT):
#	make -C $(LIBFT_PATH)
#	cp $(LIBFT) ../.
#$(PUSH): $(OBJ-S) $(LIBFT) 
#	$(AR) $(NAME) $(CC) $(CFLAGS) $(LIBFT)  -o $(NAME)

#	@make clean -C ./libft
#	$(RM) $(OBJ-S) *.o

#fclean: clean
#	@make fclean -C ./libft
#	$(RM) $(PUSH) *.a
	
#re:			fclean all

#bonus: $(N_BONUS)

#.PHONY:		all clean fclean re libft bonus
