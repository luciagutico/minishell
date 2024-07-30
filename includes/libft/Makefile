SCR_M = ft_atoi.c       \
        ft_bzero.c      \
        ft_calloc.c     \
        ft_isalnum.c    \
        ft_isalpha.c    \
        ft_isascii.c    \
        ft_isdigit.c    \
        ft_isprint.c    \
        ft_memchr.c     \
        ft_memcmp.c     \
        ft_memcpy.c     \
        ft_memmove.c    \
        ft_memset.c     \
        ft_putchar_fd.c \
        ft_strchr.c     \
        ft_strdup.c     \
        ft_strlcat.c    \
        ft_strlcpy.c    \
        ft_strlen.c     \
        ft_strncmp.c    \
        ft_strcmp.c     \
        ft_strnstr.c    \
        ft_strrchr.c    \
        ft_substr.c     \
        ft_tolower.c    \
        ft_toupper.c    \
        ft_strtrim.c    \
        ft_strmapi.c    \
        ft_strjoin.c    \
        ft_striteri.c   \
        ft_itoa.c       \
        ft_split.c       \
# SRC_B = ft_lstnew_bonus.c       \
#         ft_lstadd_front_bonus.c \
#         ft_lstsize_bonus.c      \
#         ft_lstlast_bonus.c      \
#         ft_lstadd_back_bonus.c  \
#         ft_lstdelone_bonus.c    \
#         ft_lstclear_bonus.c     \
#         ft_lstiter_bonus.c      \
#         ft_lstmap_bonus.c

OBJ_M = $(SCR_M:.c=.o)
# OBJ_B = $(SCR_B:.c=.o)

NAME  = libft.a

CC      = cc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar -rcs
RM      = rm -f

.PHONY: all clean   fclean  re

all:    $(NAME)

$(NAME):$(OBJ_M)
	$(AR) $(NAME) $(OBJ_M)

$(OBJ_M):%.o:%.c
	$(CC) -c -I $(NAME) $(CFLAGS) $< -o $@

clean: 
	$(RM) $(OBJ_M)

fclean: clean
	$(RM) $(NAME)

re: fclean  all