/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/22 12:58:32 by anagutie      #+#    #+#                 */
/*   Updated: 2024/08/30 16:29:36 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int execute_builtin(t_shell *shell, t_command *cmd)
{
	if (!cmd || cmd->command_args[0])
		return (0);
	if (ft_strcmp(cmd->command_args, "cd") == 0)
		return(execute_cd(cmd->command_args, shell->env));
	if (ft_strcmp(cmd->command_args, "echo") == 0)
		return(execute_echo(cmd->command_args));
	if (ft_strcmp(cmd->command_args, "pwd") == 0)
		return(execute_pwd(cmd->command_args, shell->env));
	if (ft_strcmp(cmd->command_args, "export") == 0)
		return(execute_export(cmd->command_args, shell->env));
	if (ft_strcmp(cmd->command_args, "unset") == 0)
		return(execute_unset(cmd->command_args, shell->env));
	if (ft_strcmp(cmd->command_args, "env") == 0)
		return(execute_env(shell->env));
	if (ft_strcmp(cmd->command_args, "exit") == 0)
	{
		return(execute_exit(cmd->command_args, shell->env));
		return(1);
	}
	return(0);
}

int	execute_cd(t_env *env)
{
	char *path = 
}
int	execute_echo()
{
	
}
int	execute_pwd()
{
	
}

int execute_export()
{
	
}
int execute_env()
{
	
}
int execute_exit(t_env *env)
{
	print_env_linked_list(env);
	
}

int execute_unset()
{
	
}


