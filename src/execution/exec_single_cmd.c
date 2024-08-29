/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_single_cmd.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/24 21:42:30 by anagutie      #+#    #+#                 */
/*   Updated: 2024/08/29 16:45:52 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void execute_one_child(t_shell *shell, t_command *command)
{
	pid_t	child;

	child = fork();
	if (child == -1)
	{
		
	}
	if (child == 0)
	{
		
	}
	
}

/**handling cases where the command might be empty, 
a built-in command, or a non-built-in command**/
void handle_single_command(t_shell *shell)
{
	int			std_in;
	int 		std_out;
	t_command	*single_cmd;

	std_in = dup(STDIN_FILENO);
	std_out = dup(STDOUT_FILENO);
	single_cmd = shell->cmd_chain;
	//FOR EMPTY ARG
	if (single_cmd->command_args[0] == NULL)
	{
		while(single_cmd->command_args != NULL)
		{single_cmd->next != 
			
		}
		open(single_cmd->in);
		if (shell->read_fd != STDIN_FILENO)
			dup2(shell->read_fd, STDIN_FILENO);
		if (shell->write_fd != STDOUT_FILENO)
			dup2(shell->write_fd, STDOUT_FILENO);
	}
	else if (single_cmd->command_args)
		handle_builtin(shell, single_cmd);
	else
		execute_one_child(shell, single_cmd);
}

