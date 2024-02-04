#include "monty.h"

/**
 * _pint - print tha last element
 * @head: in stack head
 * @count: line
 * Return: no return
*/
void _pint(stack_t **head, unsigned int count)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty", count);
		fclose(bus.pf);
		free(bus.buff);
		free_globv(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
