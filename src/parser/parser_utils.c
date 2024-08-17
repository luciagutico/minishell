#include "../../include/minishell.h"

void	fill_command_args(t_command *new_command, t_token **current_token)
{
	int i;
	t_token	*start;
	
	i = 0;
	start = (*current_token);
	while (start != NULL && start->type == WORD)
	{
		i++;
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
}

t_redirection_type	get_redirection_type(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '>')
		{
			if (str[i + 1] == '>')
				return ()
		}
	}
}

void	fill_redirection(t_command *new_command, t_token **current_token);
{
	get_redirection_type(*current_token->str);
}

