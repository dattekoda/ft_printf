NAME	:= libftprintf.a
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -Iincludes
AR		:= ar rcs

SRCS := srcs/core/ft_format.c srcs/core/ft_printf.c \
srcs/handle/handle.c srcs/handle/output.c \
srcs/libft/libft.c srcs/utils/ft_utils.c \
srcs/handle/ready.c srcs/handle/count.c	\
srcs/libft/libft_min_max.c

OBJS := $(SRCS:.c=.o)

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(NAME);

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all