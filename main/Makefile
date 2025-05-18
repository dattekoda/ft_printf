NAME	:= libftprintf.a
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -Iincludes
AR		:= ar rcs

SRCS := srcs/core/ft_format.c srcs/core/ft_printf.c \
srcs/handle/handle.c srcs/handle/output.c \
srcs/libft/libft.c srcs/utils/ft_utils.c \
srcs/handle/ready.c srcs/handle/count.c	\
srcs/libft/libft_min_max.c

BONUS := srcs/core/ft_format.c srcs/core/ft_printf.c \
srcs/handle/handle.c srcs/handle/output.c \
srcs/libft/libft.c srcs/utils/ft_utils.c \
srcs/handle/ready.c srcs/handle/count.c	\
srcs/libft/libft_min_max.c

OBJS := $(SRCS:.c=.o)
OBJS_BONUS := $(BONUS:.c=.o)

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(OBJ) $(OBJS_BONUS)
	$(AR) $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all