/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_non_builtin.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/24 21:43:26 by anagutie      #+#    #+#                 */
/*   Updated: 2024/08/24 21:55:48 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void execute_one_child(t_shell *shell, t_command *command)
{
	
}
void handle_single_command(t_shell *shell)
{
	int			std_in;
	int 		std_out;
	t_command	*curr_cmd;

	std_in = dup(STDIN_FILENO);
	std_out = dup(STDOUT_FILENO);
	
}