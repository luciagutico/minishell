/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/25 12:04:25 by anagutie      #+#    #+#                 */
/*   Updated: 2024/08/25 12:10:31 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void execution(t_shell *shell)
{
	if (shell->cmd_chain == 1)
		handle_single_command(shell->cmd_chain);
		
}