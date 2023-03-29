PUSH = dummy.a
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror -g
AR			= ar rcs
RM			= rm -rf

LIBFT_PATH		=	./libft
#JUNK_PATH		=	./junk
LIBFT			=	$(LIBFT_PATH)/libft.a

#SRC_JUNK		=	$(JUNK_PATH)(wildcard *.c)
SRC 			=	$(wildcard *.c)


OBJ-S = $(SRC:.c=.o)
#OBJ-J = $(SRC_JUNK:.c=.o)

NAME = $(PUSH)

all: $(NAME)

$(NAME): $(OBJ-S) $(LIBFT)
	$(AR) $(NAME) $(OBJ-S) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_PATH)
	cp $(LIBFT) ../.
#$(PUSH): $(OBJ-S) $(LIBFT) 
#	$(AR) $(NAME) $(CC) $(CFLAGS) $(LIBFT)  -o $(NAME)

clean:
	@make clean -C ./libft
	$(RM) $(OBJ-S) *.o

fclean: clean
	@make fclean -C ./libft
	$(RM) $(PUSH) *.a
	
re:			fclean all

#bonus: $(N_BONUS)

#.PHONY:		all clean fclean re libft bonus
