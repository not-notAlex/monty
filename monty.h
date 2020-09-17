#ifndef MONTY_H_
#define MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_info - contains gloabl info to use
 * @value: value of opcode
 * @file_descriptor: - pointer to opened file
 * Description: Stores information to be used in other areas
 */
typedef struct gloabl_info
{
	int value;
	int *file_descriptor;
	int line_num;
	char **buf;
	int has_value;
} g_i;

extern g_i values;

stack_t *add_node_beginning(stack_t **head, const int n);
stack_t *add_node_end(stack_t **head, const int n);
stack_t *add_node(stack_t **head, unsigned int i, const int n);
void delete_node(stack_t **head, unsigned int i);
void free_list(stack_t **head);
void op_push(stack_t **head, unsigned int n);
void op_pall(stack_t **head, unsigned int n);
void op_pint(stack_t **head, unsigned int n);
void op_pop(stack_t **head, unsigned int n);
void op_swap(stack_t **head, unsigned int n);
void op_add(stack_t **head, unsigned int n);
void op_nop(stack_t **head, unsigned int n);
void execute_commands(char *tokens, instruction_t ints[], stack_t **head);
int _strcmp(char *str1, char *str2);
void run_error(int n, char *str);

#endif
