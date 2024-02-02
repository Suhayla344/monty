#include "monty.h"
#include <stdio.h>

/**
 * push - this function pushes element to the  stack
 * @element: this is an element
 * @line: this is error line
 */

void push(stack_t **element, unsigned int line)
{
	int n, i = 0, f	= 0;

	if (globv.arg)
	{
		if (globv.arg[0] == '-')
			i++;
		for (; globv.arg[0] != '\0'; i++)
		{
			if (globv.arg[i] > 57 || globv.arg[i] < 48)
				f = 1;
		}
		if (f == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			fclose(globv.pf);
			free(globv.buff);
			free_stack(*element);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		fclose(globv.pf);
		free(globv.buff);
		free_stack(*element);
		exit(EXIT_FAILURE);
	}
	n = atoi(globv.arg);
	if (globv.info == 0)
		add_dnodeint(element, n);
	else
		add_dnodeint_end(element, n);
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
	if (pp == NULL)
		return;
	while (pp)
	{
		printf("%d\n", pp->n);
		pp = pp->next;
	}
}
