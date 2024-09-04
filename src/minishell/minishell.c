/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/01 19:30:12 by anagutie      #+#    #+#                 */
/*   Updated: 2024/09/04 19:53:32 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// the main will consist of 3 principal functions 
// one where we set up the shell, the env, the files, all we need.
// The 2nd will go trhough the shell and mantain the
// /active status of the shell or go out of it,
// and to 3rd to free and clean everything in the shell
int main(int ac, char **av, char **envp)
{
	t_shell	*shell;
	(void) av;
	
	if (ac == 1)
	{
		shell = set_up_shell(envp);
		if (!shell)
			return(write(2, "Shell couldnt be initialized:(",31),1);
		run_shell_loop(shell);
	}
    return (0);
}

// for now in the set up shell function I initialize the enviroment.
t_shell *set_up_shell(char **envp)
{
	t_shell	*shell;
	
	shell->read_fd = STDIN_FILENO;
	shell->write_fd = STDOUT_FILENO;
	shell->env = envp;
	shell->own_env = init_env(shell->env);
	if (!shell->own_env)
		return(free(shell), NULL);
	return (shell);
}

void run_shell(t_shell *shell)
{
	char *input_str;
	char *prompt;

	prompt = "minishell > ";

	while(input_str = readline(prompt) != NULL)
	{
		if(*input_str)
		{
			add_history(input_str);
			//shell_status = //parse command command;
			free(input_str); //free input string after processing
		}
	}
	rl_clear_history();
}




