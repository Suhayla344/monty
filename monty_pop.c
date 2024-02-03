#include "monty.h"
/**
 * _pop - function that prints the top
 * @line: number of the line
 * @head: the head of the stack
 * Return: no return , void function
 */
void _pop(stack_t **head, unsigned int line)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprint(stderr, "L%d: can't pop an empty stack\n", line)
		fclose(globv.pf);
		free(globv.buff);
		free_globv(*head);
		exit(EXIT_FAILURE);
	}
	pp = *head;
	*head = pp->next;
	free(pp);
}