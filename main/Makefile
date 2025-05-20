NAME	:= libftprintf.a
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -Iincludes
AR		:= ar rcs

SRCS := srcs/ft_format.c srcs/ft_printf.c \
srcs/handle.c srcs/output.c \
srcs/libft.c srcs/ft_utils.c \
srcs/ready.c srcs/count.c	\
srcs/libft_min_max.c

BONUS_SRCS := srcs/ft_format_bonus.c srcs/ft_printf_bonus.c \
srcs/handle_bonus.c srcs/output_bonus.c \
srcs/libft_bonus.c srcs/ft_utils_bonus.c \
srcs/ready_bonus.c srcs/count_bonus.c	\
srcs/libft_min_max_bonus.c

OBJS := $(SRCS:.c=.o)
BONUS_OBJS := $(BONUS_SRCS:.c=.o)

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus:
	$(MAKE) OBJS="$(BONUS_OBJS)" NAME=$(NAME) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all