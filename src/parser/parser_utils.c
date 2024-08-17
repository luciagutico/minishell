#include "../../include/minishell.h"

void	fill_command_args(t_command *new_command, t_token **current_token)
{
	int i;
	t_token	*start;
	t_token *end;
	
	i = 0;
	start = (*current_token);
	while (start != NULL && start->type == WORD)
	{
		i++;
		end = start;
		start = start->next;
	}
	new_command->command_args = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while ((*current_token) != start && *current_token != NULL)
	{
		new_command->command_args[i] = (*current_token)->str;
		*current_token = (*current_token)->next;
		i++;
	}
	new_command->command_args[i] = NULL;
	(*current_token) = end;
}

t_redirection_type	get_redirection_type(char *str)
{
	if (!str) // TODO: is this necessary if i return 0 in any case? yes probably because i might access out of bonds memory
		return (0);
	if (str[0] == '>')
	{
		if (str[1] == '>')
			return (APP);
		return (OUT);
	}
	if (str[0] == '<')
	{
		if (str[1] == '<')
			return (HERE);
		return (IN);
	}
	return (0);
}

char	*get_redirection_file(t_token **current_token)
{
	char *file;
	int i;
	int j;
	t_token	*token_pos;

	j = 0; // keeps track of how many tokens we traverse
	i = 0; // iterates through each token->str
	*current_token = (*current_token)->next;
	token_pos = *current_token;
	// go through the token list until i meet a delimiter
	while ((*current_token) != NULL && (*current_token)->type != PIPE && (*current_token)->type != REDIRECT_IN && (*current_token)->type != REDIRECT_OUT)
	{
		// go through the string of each token
		while ((*current_token)->str[i])
			i++;
		j++;
		*current_token = (*current_token)->next;
	}
	file = calloc((i - j) + 1, sizeof(char)); //TODO: protect && separate second part in a different function
	(*current_token) = token_pos;
	i = 0;
	while ((*current_token) != token_pos)
	{
		j = 0;
		while ((*current_token)->str[j])
		{
			file[i] = (*current_token)->str[j];
			i++, j++;
		}
		*current_token = (*current_token)->next;
	}
	file[i] = '\0';
	return (file);
}

void	fill_redirect_out(t_command *new_command, t_token **current_token)
{
	// TODO: implement heredoc
	t_redirection *out;
	
	out = create_redirection();
	while ((*current_token)->type != PIPE && (*current_token) != NULL)
	{
		out->redir_type = get_redirection_type((*current_token)->str);
		out->file = get_redirection_file(current_token);
	}
	new_command->out = out;
	printf("redirection file = %s\n", out->file);
}

// get the redirection type
// open the file
// get the file descriptor
//
// if redirection, open fd (check for error) and put that file as redir.
//
// TODO: deal with quotes, so that even if within a word it works.
