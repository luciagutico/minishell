/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/30 14:46:57 by anagutie      #+#    #+#                 */
/*   Updated: 2024/08/30 16:00:52 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include "42_lib/src/libft/libft.h"
# include <stdlib.h> // to malloc
# include <string.h> // for string manipulation
# include <readline/readline.h> // to read prompt
# include <readline/history.h> // to read prompt

// parsing

typedef	enum	s_redirection_type
{
	REDIR = 0,
	IN,
	OUT,
	HERE,
	APP,
}	t_redirection_type;

typedef struct s_redirection
{
	t_redirection_type redir_type;
	char	*file;
	int		fd;
	struct s_redirection	*next;
	
}	t_redirection;

typedef struct	s_command
{
	char		**command_args;
	t_redirection		*in;
	t_redirection		*out;
	struct s_command	*next;
}	t_command;

// tokenization

typedef enum s_token_type
{
	TOKEN,
	PIPE,
	IS_SPACE,
	S_QUOTE,
	D_QUOTE,
	REDIRECT_IN,
	REDIRECT_OUT,
	WORD,
}	t_token_type;

typedef struct	s_token
{
	t_token_type	type;
	char			*str;
	struct s_token	*next;
}	t_token;

//struct to manage enviroment

typedef	struct s_env
{
	char 			*var_name;
	char 			*var_value;
	struct 	s_env 	*next;
}	t_env;

typedef struct s_shell
{
	char 		**env;
	t_env		*own_env;
	int			write_fd;
	int			read_fd;
	t_command	*cmd_chain;
}	t_shell;

extern int shell_status;

/*Enviroment functions*/
t_env		*init_env(char **env);
char 		*get_var(char *name, t_env	*env);
char 		*get_name(char *env_var);
char 		*get_value(char *env_var);
t_env 		*var_union(char *name, char *value);
void 		append_env_list(t_env **head, t_env *new_node);
void 		free_list(t_env **env_list);
void 		free_element(t_env *node);
void 	print_env_linked_list(t_env *list);

/*tokenization functions*/
t_token	*create_new_token(void);
void	token_list_add_back(t_token **token_list_head, t_token *new_token);
t_token *token_list_find_last(t_token *token_list_node);
t_token	*extract_tokens(char *input_str);
void	fill_token_info(int *current_pos, char *input_str, t_token *new_token);
int		get_token_hint(char c);
void	pipe_token(int *current_pos, char *input_str, char c);
void	quote_token(int *current_pos, char *input_str, char c);
void	redirect_token(int *current_pos, char *input_str, char c);
void	word_token(int *current_pos, char *input_str, char c);
void	space_token(int *current_pos, char *input_str, char c);

/*parsing functions*/
t_command	*create_new_command(void);
void	fill_command_args(t_command *new_command, t_token **current_token);
void	command_list_add_back(t_command **command_list_head, t_command *new_command);
void	fill_redirect_out(t_command *new_command, t_token **current_token);
t_redirection	*create_redirection(void);
char	*get_file_name(char *file, int end_str, int token_nbr, t_token **current_token);
t_redirection_type	get_redirection_type(char *str);
int	get_fd_file(char *file, t_redirection_type REDIR);
t_command	*command_list_find_last(t_command *command_list_head);

/*executer functions*/
void handle_single_command(t_shell *shell);

//minishell
t_shell *set_up_shell(char **envp);

#endif
