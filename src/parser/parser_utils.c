#include "../../include/minishell.h"

void	command_args(t_command *new_command, t_token **current_token)
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

	i = 0;
	while (new_command->command_args != NULL && new_command->command_args[i] != NULL)
	{
		printf("%s", new_command->command_args[i]);
		i++;
	}
	// i need to allocate for command_args
	// so i need to know the number of command + flgs before, then calloc for that nume

}
