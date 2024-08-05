#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <readline/readline.h>
#include <readline/history.h>

typedef struct {
	int  i;
	char *buffer;
} Prompt;

typedef struct {
	char *value;
} Token;

void	extract_tokens(Prompt *prompt)
{
	int j = 0;
	while (prompt->buffer[j])
	{
		while (prompt->buffer[j] != ' ')
		{
			prompt->i += 1;
			j++;
		}
		Token *token = malloc(sizeof(Token));
		token->value = malloc(sizeof(char) * prompt->i-j);
		token->value[j] = '\0';
		j--;
		while (j > (j - prompt->i))
		{
			token->value[j] = prompt->buffer[j];
			j--;
		}
		printf("%s", token->value);
		j++;
	}
}

void create_prompt_struct(char *command_line)
{
	Prompt *prompt = malloc(sizeof(Prompt));
	if (prompt == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(1);
	}
	prompt->i = 0;
	prompt->buffer = strdup(command_line);
	extract_tokens(prompt);
	free(prompt->buffer);
	free(prompt);
}

int main(int argc, char **argv)
{
	argc = 2;
	char *prompt = readline("minishell> ");
	create_prompt_struct(prompt);
	return (0);
}

// function reads the command line
// function token that calls other functions to build the tokens: start by initialize a struct with which holds the command line and the iterator 
// i can reallocate!1
