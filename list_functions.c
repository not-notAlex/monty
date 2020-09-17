#include "monty.h"

/**
 * add_node_beginning - adds new node at beginning
 * @head: head of list
 * @n: value of new node
 * Return: new node
 */
stack_t *add_node_beginning(stack_t **head, const int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list(head);
		exit(EXIT_FAILURE);
	}
	node->n = n;
	node->next = *head;
	node->prev = NULL;
	if (*head == NULL)
	{
		*head = node;
		return (node);
	}
	(*head)->prev = node;
	*head = node;
	return (node);
}

/**
 * add_node_end - adds node at end of list
 * @head: head of list
 * @n: value of node
 * Return: new node
 */
stack_t *add_node_end(stack_t **head, const int n)
{
	stack_t *node, *ptr;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list(head);
		exit(EXIT_FAILURE);
	}
	node->n = n;
	node->next = NULL;
	if (*head == NULL)
	{
		node->prev = NULL;
		*head = node;
		return (node);
	}
	ptr = *head;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = node;
	node->prev = ptr;
	return (node);
}

/**
 * free_list - frees list
 * @head: head of list
 *
 * Return: no return
 */
void free_list(stack_t **head)
{
	stack_t *ptr, *ptr2;

	if (*head == NULL)
		return;

	ptr = *head;
	while (ptr)
	{
		ptr2 = ptr->next;
		free(ptr);
		ptr = ptr2;
	}
}

/**
 * add_node - adds node at given index
 * @head: head of list
 * @i: index
 * @n: value of list
 * Return: new node
 */
stack_t *add_node(stack_t **head, unsigned int i, const int n)
{
	stack_t *node, *ptr;
	unsigned int x = 0;

	if (i == 0)
		return (add_node_beginning(head, n));

	ptr = *head;
	while (ptr && x < i)
	{
		ptr = ptr->next;
		x++;
	}
	if (ptr == NULL)
		return (add_node_end(head, n));
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list(head);
		exit(EXIT_FAILURE);
	}
	node->n = n;
	ptr->prev->next = node;
	node->next = ptr;
	node->prev = ptr->prev;
	ptr->prev = node;
	return (node);
}

/**
 * delete_node - deletes node at given index
 * @head: head of list
 * @i: index
 * Return: no return
 */
void delete_node(stack_t **head, unsigned int i)
{
	stack_t *ptr = *head;
	unsigned int x = 0;

	while (ptr && x < i)
	{
		ptr = ptr->next;
		x++;
	}

	if (ptr == NULL)
		return;

	if (ptr->next)
		ptr->next->prev = ptr->prev;
	if (ptr->prev)
		ptr->prev->next = ptr->next;
	else
		*head = ptr->next;

	free(ptr);
}
