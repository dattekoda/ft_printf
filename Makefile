NAME	= ft_printf.a
CC		= clang
CFLAGS	= -Wall -Wextra -Werror -Iincludes
AR		= ar rcs

SRCS := srcs/core/ft_format.c srcs/core/ft_printf.c \
srcs/handle/handle.c srcs/handle/output.c \
srcs/libft/libft.c srcs/utils/ft_utils.c

OBJS := $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all