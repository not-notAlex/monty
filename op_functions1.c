#include "monty.h"

/**
 * op_add - adds top two elements and removes the top one
 * @head: head of list
 * @n: line number
 * Return: no return
 */
void op_add(stack_t **head, unsigned int n)
{
	int tmp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", values.line_num);
		free_list(head);
		close(*(values.file_descriptor));
		exit(EXIT_FAILURE);
	}

	tmp = (*head)->n;
	(void)n;
	delete_node(head, 0);
	(*head)->n += tmp;
}

/**
 * op_nop - does nothing :(
 * @head: head of list
 * @n: line number
 * Return: no return
 */
void op_nop(stack_t **head, unsigned int n)
{
	(void)head;
	(void)n;
}
