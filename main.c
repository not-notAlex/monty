#include "monty.h"

stack_t *head = NULL;

/**
 * main - start of execution
 * @ac: number of arguments
 * @argv: array of arguments
 * Return: always return 0
 */
int main(int ac, char *argv[])
{
	int i, k = 0, j = 0;
	char *buf, *tokens[1024], *tok;
	instruction_t ints[] = {
		{"push", &op_push},
		{"pall", &op_pall},
		{"pint", &op_pint},
		{"pop", &op_pop},
		{"swap", &op_swap},
		{"add", &op_add},
		{"nop", &op_nop},
		{NULL, NULL}
	};

	if (ac < 2 || ac > 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	i = open(argv[1], O_RDONLY);
	if (i == -1)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buf = malloc(1024);
	read(i, buf, 1024);
	tok = strtok(buf, "\n");
	while (tok != NULL)
	{
		tokens[j] = tok;
		j++;
		tok = strtok(NULL, "\n");
	}
	while (tokens[k])
		execute_commands(tokens[k++], ints);
	free(buf);
	free_list(head);
	close(i);
	return (0);
}
