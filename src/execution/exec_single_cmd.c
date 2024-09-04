/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_single_cmd.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/24 21:42:30 by anagutie      #+#    #+#                 */
/*   Updated: 2024/09/04 19:41:24 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void execute_one_child(t_shell *shell, t_command *command)
{
	pid_t	child;

	child = fork();
	if (child == -1)
		return(EXIT_FAILURE);
	if (child == 0)
	{
		execute_command(shell, command);
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

	}
	else if (single_cmd->command_args)//how to check if my command is a builtin?
		execute_builtin(shell, single_cmd);
	else
		execute_one_child(shell, single_cmd);
}

