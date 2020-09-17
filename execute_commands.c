#include "monty.h"

/**
 * execute_commands - executes the monty commands
 * @tokens: tkens to parse
 * @ints: instructions
 * Return: no return
 */
void execute_commands(char *tokens, instruction_t ints[])
{
	char *coms[2];
	int k = 0, num = 0;

	coms[0] = strtok(tokens, " ");
	coms[1] = strtok(NULL, " ");
	while (ints[k].opcode)
	{
		if (_strcmp(coms[0], ints[k].opcode))
		{
			if (coms[1] != NULL)
				num = atoi(coms[1]);
			ints[k].f(&head, num);
			return;
		}
		k++;
	}
}

/**
 * _strcmp - compares two strings
 * @str1: first string
 * @str2: second string
 * Return: 1 if true 0 if false
 */
int _strcmp(char *str1, char *str2)
{
	int i = 0;

	while (str2[i])
	{
		if (str2[i] != str1[i])
			return (0);
		i++;
	}
	return (1);
}
