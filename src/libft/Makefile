# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamaral- <mamaral-@student.42porto.com     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 12:11:35 by mamaral-          #+#    #+#              #
#    Updated: 2023/05/24 14:54:16 by mamaral-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREY		:= \e[1;30m
RED		 := \e[1;31m
GREEN	   := \e[1;32m
YELLOW	  := \e[1;33m
BLUE		:= \e[1;34m
MAGENTA	 := \e[1;35m
CYAN		:= \e[1;36m
WHITE	   := \e[1;37m

BOLD		:= \e[1m
DIM		 := \e[2m	
UNDERLINE   := \e[4m
BLINK	   := \e[5m
INVERTED	:= \e[7m
END		 := \e[0m

NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
AR			= ar rc
RM			= rm -rf

SRCS			= ft_arrlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
					ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
					ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
					ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
					ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
					ft_strjoin.c ft_strtrim.c ft_split.c ft_swap.c ft_itoa.c \
					ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c ft_isspace.c ft_intlen.c \
					ft_arrlen.c ft_printf.c ft_putcharpf.c ft_atol.c ft_putstrpf.c \
					ft_puthexpf.c ft_putnbrpf.c ft_putunbrpf.c ft_putptrpf.c \
					get_next_line.c get_next_line_utils.c
B_SRCS		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c


OBJS		= ${SRCS:.c=.o}
B_OBJS		= ${B_SRCS:.c=.o}

all:		bonus

$(NAME):	${OBJS}
	@printf "\e[2K\r$(CYAN)Generated $(NAME)$(END)\n"
			@${AR} ${NAME} ${OBJS}
	
bonus:		${OBJS} ${B_OBJS}
	@printf "\e[2K\r$(CYAN)Generated $(NAME)$(END)\n"
			@${AR} ${NAME} ${B_OBJS} ${OBJS}

%.o: %.c
			@printf "\e[2K\r$(WHITE)Compiling $<$(END)"
			@${CC} ${CFLAGS} -c -o $@ $<

clean:
	@printf "\e[2K\r$(MAGENTA)Cleaning objects from LIBFT$(END)\n"
			@${RM} *.*o

fclean:		clean
	@printf "\e[2K\r$(MAGENTA)Cleaning library from $(NAME)$(END)\n"
			@${RM} *.a

re:			fclean all

.PHONY: clean fclean re all bonus