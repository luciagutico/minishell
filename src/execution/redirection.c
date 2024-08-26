/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirection.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/22 18:08:06 by anagutie      #+#    #+#                 */
/*   Updated: 2024/08/26 14:55:55 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int infile_redirection(t_shell *shell, t_redirection *node)
{
	if (shell->read_fd > 2)
		close(shell->read_fd);
	shell->read_fd = open(node->file, O_RDONLY);
	if (shell->read_fd == -1)
		return(perror("open operation needed for redirection failed"), 1);
	if (dup2(shell->read_fd, STDIN_FILENO) == -1)
		return(perror("Infile redirection operation failed"), -1);
	else
		return(0);
}

int outfile_redirection(t_shell *shell, t_redirection *node)
{
	if (shell->read_fd > 2)
		close(shell->write_fd);
	shell->write_fd = open(node->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (shell->write_fd == -1)
		return(perror("open operation needed for redirection failed"), 1);
	if (dup2(shell->write_fd, STDOUT_FILENO) == -1)
		return(perror("Outfile redirection operation failed"), -1);
	return(0);
}

int append_redirection(t_shell *shell, t_redirection *node)
{
	if (shell->read_fd > 2)
		close(shell->write_fd);
	shell->write_fd = open(node->file, O_WRONLY | O_CREAT | O_APPEND, 0664);
	if(shell->write_fd == -1)
		return(perror("open operation needed for redirection failed"), 1);
	if (dup2(shell->write_fd, STDOUT_FILENO) == -1)
		return(perror("redirection append operation failed"), -1);
}

int here_doc_redirection(t_shell *shell, t_redirection *node)
{
	
}

void execute_redirection(t_shell *shell, t_redirection *node)
{
	if (node->redir_type == IN)
		infile_redirection(node, shell);
	else if (node->redir_type == OUT)
		outfile_redirection(node, shell);
	else if (node->redir_type == APP)
		append_redirection(node, shell);
	else if (node->redir_type == HERE)
		here_doc_redirection(node, shell);
}