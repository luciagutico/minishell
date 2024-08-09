/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/30 14:46:57 by anagutie      #+#    #+#                 */
/*   Updated: 2024/08/02 19:36:31 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include <stdlib.h> // to malloc
# include <readline/readline.h> // to read prompt
# include <readline/history.h> // to read prompt

// tokenization

typedef enum s_token_type
{
	TOKEN,
	PIPE,
	S_QUOTE,
	D_QUOTE,
	REDIRECT_IN,
	REDIRECT_OUT,
	REDIRECT_OUT_APPEND,
	WORD,
}	t_token_type;

typedef struct s_token
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
	char 	**env;
	t_env	*own_env;
}	t_shell;

//ENVIROMENT

/*Enviroment functions*/
t_env		*init_env(char **env);
char 		*get_var(char *name, t_env	*env);
char 		*get_var_name(char *env_var);
char 		*get_var_content(char *env_var);

/*Enviroment utils*/
t_env 		*create_node(char *name, char *value);
void 		append_env_list(t_env **head, t_env *new_node);
void 		free_env_list(t_env **env_list);
void 		free_node(t_env *node);

/*tokenization functions*/
t_token	*create_new_token(void);
void	token_list_add_back(t_token **token_list_head, t_token *new_token);
t_token *token_list_find_last(t_token *token_list_node);
t_token	*extract_tokens(char *input_str);
void	fill_token_info(int *current_pos, char *input_str, t_token **new_token);
int		get_token_hint(char c);
void	pipe_token(int *current_pos, char *input_str, char token_hint, t_token **new_token);

//minishell
t_shell *set_up_shell(char **envp);

#endif
