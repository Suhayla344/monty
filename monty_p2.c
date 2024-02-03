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
		fprintf(2, "L%u: can't pint, stack empty", counter);
		fclose(list_t.pf);
		free(list_t.counter);
		free_globv(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
