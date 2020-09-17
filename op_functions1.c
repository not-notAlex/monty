#include "monty.h"

/**
 * op_add - adds top two elements and removes the top one
 * @head: head of list
 * @n: line number
 * Return: no return
 */
void op_add(stack_t **head, unsigned int n)
{
	int tmp = (*head)->n;

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
