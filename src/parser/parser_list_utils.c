#include "../../include/minishell.h"

t_command	*create_new_command(void)
{
	t_command *new = malloc(sizeof(t_command) * 1);
	if (!new)
		return (NULL);
	new->command_args = NULL;
	new->in = NULL;
	new->out = NULL;
	new->next = NULL;
	return (new);
}



