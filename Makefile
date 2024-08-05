NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = src/
SRCS = $(SRC_DIR)minishell.c

ENVIROMENT_DIR = $(SRC_DIR)enviroment/
ENVIROMENT_SRC = $(ENVIROMENT_DIR)enviroment.c \
			   $(ENVIROMENT_DIR)enviroment_utils.c \

			

ALL_SRCS = $(SRCS) $(ENVIROMENT_SRC)
OBJS = $(SRCS:.c=.o)
LIBFT = includes/libft/libft.a
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C includes/libft

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make -C includes/libft fclean

re: fclean all

.PHONY: all clean fclean re
