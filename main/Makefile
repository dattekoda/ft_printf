NAME	:= libftprintf.a
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -Iincludes
AR		:= ar rcs

SRCS := srcs/mandatory/ft_format.c srcs/mandatory/ft_printf.c \
srcs/mandatory/handle.c srcs/mandatory/output.c \
srcs/mandatory/libft.c srcs/mandatory/ft_utils.c \
srcs/mandatory/ready.c srcs/mandatory/count.c	\
srcs/mandatory/libft_min_max.c

BONUS_SRCS := srcs/bonus/ft_format_bonus.c srcs/bonus/ft_printf_bonus.c \
srcs/bonus/handle_bonus.c srcs/bonus/output_bonus.c \
srcs/bonus/libft_bonus.c srcs/bonus/ft_utils_bonus.c \
srcs/bonus/ready_bonus.c srcs/bonus/count_bonus.c	\
srcs/bonus/libft_min_max_bonus.c

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