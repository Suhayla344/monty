#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>

/*structions*/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct list - global struct to use in the func
 * @info: is stack or queue
 * @cont: current line
 * @arg: second parameter inside the current line
 * @head: deubly  linked list
 * @pf: file descriptor
 * @buff: input text
 *
 * Description: element linked list node struc
 * for stack, queue, LIFO, FIFO
*/
typedef struct list
{
	int info;
	unsigned int counter;
	char *arg;
	stack_t *head;
	FILE *pf;
	char *buff;
} list_t;

/*global value*/
extern list_t globv;

/*func_monty_p1.c*/
void _push(stack_t **element, unsigned int line);
void _pall(stack_t **element, unsigned int line);
void free_globv(void);
stack_t *add_dnodeint(stack_t **head, const int y);
stack_t *add_dnodeint_end(stack_t **head, const int y);
#endif
