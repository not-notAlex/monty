#include "monty.h"

/**
 * op_push - pushes an element onto the stack
 * @head: head of list
 * @n: value of element
 * Return: no return
 */
void op_push(stack_t **head, unsigned int n)
{
	(void)head;
	(void)n;
	if (values.has_value == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", values.line_num);
		free_list(head);
		close(*(values.file_descriptor));
		exit(EXIT_FAILURE);
	}
	add_node_beginning(head, values.value);
}

/**
 * op_pall - prints the list
 * @head: head of list
 * @n: line number
 * Return: no return
 */
void op_pall(stack_t **head, unsigned int n)
{
	stack_t *ptr = *head;
	(void)n;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * op_pint - prints the top element of the stack
 * @head: head of list
 * @n: line number
 * Return: no return
 */
void op_pint(stack_t **head, unsigned int n)
{
	(void)n;
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", values.line_num);
		free_list(head);
		close(*(values.file_descriptor));
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * op_pop - deletes top element
 * @head: head of list
 * @n: line number
 * Return: no return
 */
void op_pop(stack_t **head, unsigned int n)
{
	(void)n;
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", values.line_num);
		free_list(head);
		close(*(values.file_descriptor));
		exit(EXIT_FAILURE);
	}
	delete_node(head, 0);
}

/**
 * op_swap - swaps top two elements
 * @head: head of list
 * @n: line number
 * Return: no return
 */
void op_swap(stack_t **head, unsigned int n)
{
	int tmp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", values.line_num);
		free_list(head);
		close(*(values.file_descriptor));
		exit(EXIT_FAILURE);
	}

	tmp = (*head)->n;
	(void)n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = tmp;
}
