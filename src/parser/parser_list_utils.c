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

t_redirection	*create_redirection(void)
{
	t_redirection *new = malloc(sizeof(t_redirection) * 1);
	if (!new)
		return (NULL);
	new->redir_type = 0;
	new->file = NULL;
	new->fd = 0;
	return (new);
}

void	command_list_add_back(t_command **command_list_head, t_command *new)
{
	if (command_list_head == NULL)
		return ;
	if ((*command_list_head) == NULL)
		*command_list_head = new;
	else
	{
		t_command *temp;
		temp = (t_command *)ft_lstlast((t_list *)command_list_head);
		temp->next = new;
	};

}



