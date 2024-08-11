# --------------- Makefile ------------ #

NAME			:= minishell

# ----------- Source and object files ------------- #

SRC_DIR			:= src
SRCS			:= tokenizer/tokenizer.c tokenizer/tokenizer_utils.c tokenizer/token_list_utils.c
SRCS			:= $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ_DIR			:= .build
OBJS			:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# --------------- Libraries and header files ------------- #

INC_DIR				:= include/42_lib

LIB42_DIR			:= include/42_lib
LIB42_TARGET		:= include/42_lib/libftprintfgnl.a

# --------------- Flags --------------- #

CFLAGS				:= -Wall -Wextra -Werror -I$(INC_DIR)
RM					:= rm -rf

# --------- Compilation/rules --------- #

all: $(NAME)

$(NAME): $(OBJS) $(LIB42_TARGET)
	cc $(CFLAGS) $(OBJS) -lreadline -o $(NAME) $(LIB42_TARGET)
	@echo $(Blue) minishell Compiled ✅ $(Color_Off)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $< into $@"
	@mkdir -p $(dir $@)
	cc $(CFLAGS) -c $< -o $@

$(LIB42_TARGET):
	@$(MAKE) -C $(LIB42_DIR)
	@echo $(Blue) 42_Lib Complete ✅ $(Color_Off)

# ----------- Cleaning rules ---------- #

clean:
	$(MAKE) -C include/42_lib clean
	$(RM) $(OBJ_DIR)
	@echo $(Dark_Pink) Cleaning complete.. 💥 $(Color_Off)

fclean: clean
	$(MAKE) -C include/42_lib fclean
	$(RM) $(NAME)
	@echo $(Dark_Pink) Thorough cleaning complete.. 💥 $(Color_Off)

re: fclean all

# ----------- Specific rules ---------- #

print-%:
	$(info '$*'='$($*)')

.PHONY: clean fclean re new all

# ----------- Color codes ---------- #

Color_Off	= "\033[0m"
Blue		= "\033[38;5;68m"
Yellow		= "\033[38;5;230m"
Pink		= "\033[38;5;218m"
Dark_Pink	= "\033[38;5;175m"
