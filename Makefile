NAME		= push_swap

HEADER		= push_swap.h

SRCS_PATH	= ./srcs
SRCS_NAME	= push_swap.c
SRCS		= $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

OBJS_PATH	= ./objs
OBJS_NAME	= $(SRCS_NAME:.c=.o)
OBJS		= $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

CC		= gcc
CFLAGS		= -Wall -Wextra - Werror -g
RM		= rm -rf

all :		$(NAME)

$(NAME) :	$(OBJS)
		$(CC) -c $(CFLAGS) $(SRCS)
		ar rc $(NAME) $(OBJS) $(HEADER)

clean :
		$(RM) $(OBJS_PATH)

fclean :	clean
		$(RM) $(NAME)

re :		fclean all

.PHONY :	all clean fclean re
