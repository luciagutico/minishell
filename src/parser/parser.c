#include "../../include/minishell.h"

// This function goes through the token_list with the new_command node
// and calls functions to fill the command node depending on the nature of the token.
void	fill_command_info(t_command *new_command, t_token **current_token)
{
	while (*current_token != NULL && (*current_token)->type != PIPE)
	{
		void (*get_full_command[])(t_command *, t_token	**) =
		{
			[PIPE] = NULL,
			[S_QUOTE] = NULL,
			[D_QUOTE] = NULL,
			[REDIRECT_IN] = NULL,
			[REDIRECT_OUT] = fill_redirect_out,
			[WORD] = fill_command_args,
		};
		get_full_command[(*current_token)->type](new_command, current_token);
		if (*current_token != NULL)
			*current_token = (*current_token)->next;
	}
	// if (*current_token != NULL && (*current_token)->type == PIPE)
	// 		*current_token = (*current_token)->next;
}

// This function parses the token_list, and fills the command nodes while arranging them in a linked list.
t_command *parser(t_token *token_list_head)
{
	t_command	*command_list_head;
	t_token		*current_token;
	t_command	*new_command;

	current_token = token_list_head;
	command_list_head = NULL;
	while (current_token != NULL)
	{
		while (current_token != NULL && current_token->type != PIPE)
		{
			new_command = create_new_command();
			fill_command_info(new_command, &current_token);
			command_list_add_back(&command_list_head, new_command);
			if (current_token != NULL)
				current_token = current_token->next;
		}
		if (current_token != NULL)
			current_token = current_token->next;
	}
	return (command_list_head);
}
//TODO: implement space token
//TODO:handle expansion
/* int main(void) */
/* { */
/* 	t_token *list_token_head; */
/* 	t_token *new; */
/* 	t_token *two; */
/* 	t_token *three; */
/* 	t_token *four; */
/* 	// t_token *five; */
/* 	// t_token *six; */
/* 	t_command *test_command; */
/* 	test_command = create_new_command(); */
/* 	list_token_head = NULL; */
/* 	new = create_new_token(); */
/* 	new->type = WORD; */
/* 	new->str = "cat "; */
/* 	token_list_add_back(&list_token_head, new); */
/* 	two = create_new_token(); */
/* 	two->type = WORD; */
/* 	two->str = "output.txt"; */
/* 	token_list_add_back(&list_token_head, two); */
/* 	three = create_new_token(); */
/* 	three->type = PIPE; */
/* 	three->str = "|"; */
/* 	token_list_add_back(&list_token_head, three); */
/* 	four = create_new_token(); */
/* 	four->type = WORD; */
/* 	four->str = "wc -l"; */
/* 	token_list_add_back(&list_token_head, four); */
/* 	// five = create_new_token(); */
/* 	// five->type = WORD; */
/* 	// five->str = "fil"; */
/* 	// token_list_add_back(&list_token_head, five); */
/* 	// six = create_new_token(); */
/* 	// six->type = WORD; */
/* 	// six->str = "e"; */
/* 	// token_list_add_back(&list_token_head, six); */
/* 	test_command = parser(list_token_head); */
/* 	// int i = 0; */
/* 	// while (test_command->command_args != NULL && test_command->command_args[i] != NULL) */
/* 	// { */
/* 	// 	printf("command.args[%d] = %s\n", i, test_command->command_args[i]); */
/* 	// 	printf("command.out = %s\n", test_command->out->file); */
/* 	// 	i++; */
/* 	// } */
/* 	return (0); */
/* } */

//TODO: check if parsing with "cat output.txt" works (that is, if filename is not after redirection tokens)
// int main(void)
// {
// 	char *args[] =  {"/usr/bin/cat", "output.txt", NULL};
// 	execve("/usr/bin/cat", args, NULL);
// 	perror("execve");
// 	return (0);
// }
