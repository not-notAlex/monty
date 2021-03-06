#include "monty.h"

g_i values = {0, NULL, 1, NULL, 0};

/**
 * main - start of execution
 * @ac: number of arguments
 * @argv: array of arguments
 * Return: always return 0
 */
int main(int ac, char *argv[])
{
	stack_t *head = NULL;
	int i, k = 0, j = 0, m = 0;
	char buf[10000], *tokens[10000], *tok;
	instruction_t ints[] = {
		{"push", op_push}, {"pall", &op_pall}, {"pint", &op_pint}, {"pop", &op_pop},
		{"swap", &op_swap}, {"add", &op_add}, {"nop", &op_nop}, {NULL, NULL}
	};

	if (ac != 2)
		run_error(0, argv[1]);
	i = open(argv[1], O_RDONLY);
	if (i == -1)
		run_error(1, argv[1]);
	values.file_descriptor = &i;
	for (m = 0; m < 10000; m++)
	{
		buf[m] = '\0';
		tokens[m] = NULL;
	}
	read(i, buf, 1024);
	for (m = 0; m < 10000; m++)
		if (buf[m] == '\n' && buf[m + 1] == '\n')
			buf[m + 1] = '*';
	tok = strtok(buf, "\n");
	while (tok != NULL)
	{
		tokens[j] = tok;
		j++;
		tok = strtok(NULL, "\n");
	}
	while (tokens[k])
	{
		values.has_value = 0;
		values.value = 0;
		execute_commands(tokens[k++], ints, &head);
		values.line_num++;
	}
	free_list(&head);
	close(i);
	return (0);
}

/**
 * run_error - runs errors
 * @n: number of error
 * @str: string of file
 * Return: no return
 */
void run_error(int n, char *str)
{
	if (n == 0)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (n == 1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", str);
		exit(EXIT_FAILURE);
	}
}
