#include "monty.h"
#include <stdio.h>
extern list_t bus;
/**
 * _push - this function pushes element to the  stack
 * @head: this is an element
 * @line: this is error line
 */

void _push(stack_t **head, unsigned int line)
{
	int n, i = 0, f	= 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			i++;
		for (; bus.arg[0] != '\0'; i++)
		{
			if (bus.arg[i] > 57 || bus.arg[i] < 48)
				f = 1;
		}
		if (f == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			fclose(bus.pf);
			free(bus.buff);
			free_globv(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		fclose(bus.pf);
		free(bus.buff);
		free_globv(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	if (bus.info == 0)
		add_dnodeint(head, n);
	else
		add_dnodeint_end(head, n);
}

/**
 * _pall - this function prints existing values in stack
 * @head: this is head of linked list
 * @line: line number
 * Return: no return
 */
void _pall(stack_t **head, unsigned int line)
{
	stack_t *pp;
	(void)line;

	pp = *head;
	if (pp == NULL)
		return;
	while (pp)
	{
		printf("%d\n", pp->n);
		pp = pp->next;
	}
}
/**
 * free_globv - this functions frees doubly linked list
 * @head: this param is the head of the stack
 */
void free_globv(stack_t *head)
{
	stack_t *pp;

	pp = head;
	while (head)
	{
		pp = head->next;
		free(head);
		head = pp;
	}
}
