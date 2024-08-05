/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/01 19:30:12 by anagutie      #+#    #+#                 */
/*   Updated: 2024/08/02 18:34:34 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// the main will consist of 3 principal functions 
// one where we set up the shell, the env, the files, all we need.
// The 2nd will be we crated to loop trhough the shell and mantain the
///active status of the shell or go out of it,
//and to 3rd to free and clean everything in the shell
int main(int ac, char **av, char **envp)
{
	t_shell	*shell;
	(void) av;
	(void) ac;
	
	shell = set_up_shell(envp);
	if (!shell)
		return(write(2, "Shell couldnt be initialized",29),1);
}

// for now in the set up shell function I initialize the enviroment.
t_shell *set_up_shell(char **envp)
{
	t_shell	*shell;
	
	shell = ft_calloc(1, sizeof(t_shell));
	if (!shell)
		return (NULL);
	shell->env = envp;
	shell->own_env = init_env(shell->env);
	if (!shell->own_env)
		return(free(shell), NULL);
	return (shell);
}