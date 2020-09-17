#include "monty.h"

/**
 * execute_commands - executes the monty commands
 * @tokens: tkens to parse
 * @ints: instructions
 * @head: head of list
 * Return: no return
 */
void execute_commands(char *tokens, instruction_t ints[], stack_t **head)
{
	char *coms[2];
	int k = 0, i = 0;

	coms[0] = strtok(tokens, " ");
	if (coms[0] == NULL)
	{
		values.line_num--;
		return;
	}
	coms[1] = strtok(NULL, " ");
	values.has_value = 0;
	values.value = 0;
	while (ints[k].opcode)
	{
		if (_strcmp(coms[0], ints[k].opcode))
		{
			if (coms[1] != NULL)
			{
				i = 0;
				while (coms[1][i])
				{
					if (coms[1][i] > 57 || coms[1][i] < 48)
					{
						printf("L%d: usage: push integer\n", values.line_num);
						free_list(head);
						exit(EXIT_FAILURE);
					}
					i++;
				}
				values.value = atoi(coms[1]);
				values.has_value = 1;
			}
			ints[k].f(head, values.line_num);
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
