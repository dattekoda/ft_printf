NAME	= ft_printf.a
CC		= cc
OBJS	= -Wall -Wextra -Werror
AR		= ar rcs

SRC_DIR	= src
MAND_SRC=	$(addprefix $(SRC_DIR)/core/, ft_printf.c) \
			$(addprefix $(SRC_DIR)/conv/, conv_char.c) \
			$(addprefix $(SRC_DIR)/utils/, itoa_base.c) \

BONUS_DIR = src_bonus
BONUS_SRC = $(BONUS_DIR)/parse_flag_bonus.c \
			$(BONUS_DIR)/pad_bonus.c

OBJS	= $(MAND_SRC:.c=.o)
OBJS_B	= $(BONUS_SRC)
$(NAME):
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a .
	ar rcs $@ $(OBJS)