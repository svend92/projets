NAME := fillit

SRCS := backtrack.c getedges.c main.c parser.c solver.c tool_back.c tools.c

L_FT = ./libft

OBJS := $(SRCS:.c=.o)

FLAGS := -Wall -Wextra -Werror

LIBFT := libft/libft.a

RM := rm -f

.PHONY: all clean fclean re

all		: $(NAME)

$(NAME)	: $(OBJS)
		@make -C libft/
		gcc $(FLAGS) -o fillit $(OBJS) $(LIBFT)

clean :
	$(RM) $(OBJS)

fclean :	clean
	$(RM) $(NAME)

re : fclean all
