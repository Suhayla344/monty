#include "monty.h"
/**
 * _pop - function that prints the top
 * @line: number of the line
 * @head: the head of the stack
 * Return: no return , void function
 */
void _pop(stack_t **head, unsigned int line)
{
	stack_t *pp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		fclose(bus.pf);
		free(bus.buff);
		free_globv(*head);
		exit(EXIT_FAILURE);
	}
	pp = *head;
	*head = pp->next;
	free(pp);
}
