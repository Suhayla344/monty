#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *
 * _push - this function pushes element to the  stack
 * @element: this is an element
 * @line: this is error line
 */

void _push(stack_t **element, unsigned int line)
{
	int x, y;

	if (!globv.arg)
	{
		dprintf(STDERR_FILENO, "L%u", line);
		dprintf(STDERR_FILENO, "usage: push integer\n");
		free_globv();
		exit(EXIT_FAILURE);
	}
	for (x = 0; globv.arg[x] != NULL; x++)
	{
		if (!isdigit(globv.arg[x]) && globv.arg[x] != '-')
		{
			dprintf(2, "L%u", line);
			dprintf(2, "usage: push integer\n");
			free_globv();
			exit(EXIT_FAILURE);
		}
	}
	x = atoi(globv.arg);
	if (globv.info == 1)
		add_dnodeint(element, y);
	else
		add_dnodeint_end(element, y);
}
/**
 * _pall - this function prints existing values in stack
 * @element: this is head of linked list
 * @line: line number
 * Return: no return
 */
void _pall(stack_t **element, unsigned int line)
{
	stack_t *pp;
	(void)line;

	pp = *element;

	while (pp)
	{
		printf("%d\n", pp->n);
		pp = pp ->next;
	}
}
