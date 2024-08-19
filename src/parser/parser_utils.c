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

char	*get_file_name(char *file, int end_str, int token_nbr, t_token **current_token)
{
	int	i;
	int	j;
	int str_i;

	i = 0;
	j = 0;
	while (j < token_nbr && i < end_str)
	{
		str_i = 0;
		while ((*current_token)->str[str_i] != '\0')
		{
			file[i] = (*current_token)->str[str_i];
			str_i++, i++;
		}
		*current_token = (*current_token)->next;
		j++;
	}
	file[i] = '\0';
	return (file);
}

int	get_fd_file(char *file, t_redirection_type REDIR)

{
	int fd;
	fd = OUT; // TODO: modify this when adding new cases
	if (REDIR == OUT)
		fd = open(file, O_WRONLY | O_CREAT, 0777); //TODO: do I need O TRUNC?
	if (fd == -1)
			return (-1); //TODO: check if protection ok
	return (fd);
}

char	*get_redirection_file(t_token **current_token)
{
	char *file;
	int i;
	int j;
	int end_str;
	int token_nbr;
	t_token	*token_pos;

	j = 0; // keeps track of how many tokens we traverse
	i = 0; // iterates through each token->str
	*current_token = (*current_token)->next;
	token_pos = *current_token;
	// go through the token list until i meet a delimiter
	while (token_pos != NULL && token_pos->type != PIPE && token_pos->type != REDIRECT_IN && token_pos->type != REDIRECT_OUT)
	{
		// go through the string of each token
		i += ft_strlen(token_pos->str);
		j++;
		token_pos = token_pos->next;
	}
	file = calloc(i + 1, sizeof(char)); //TODO: protect
	end_str = i;
	token_nbr = j;
	file = get_file_name(file, i, j, current_token);
	return (file);
}

void	fill_redirect_out(t_command *new_command, t_token **current_token)
{
	// TODO: implement heredoc
	t_redirection *out;
	
	out = create_redirection();
	while ((*current_token) != NULL && (*current_token)->type != PIPE)
	{
		out->redir_type = get_redirection_type((*current_token)->str);
		out->file = get_redirection_file(current_token);
		out->fd = get_fd_file(out->file, out->redir_type);
	}
	new_command->out = out;
}

// get the redirection type
// open the file
// get the file descriptor
//
// if redirection, open fd (check for error) and put that file as redir.
//
// TODO: deal with quotes, so that even if within a word it works.
