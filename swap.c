#include "monty.h"

/**
 * _swap - adds the last element of the stack
 * @head: stack head
 * @cont: line num
 * Return: no return
*/
void _swap(stack_t **head, unsigned int cont)
{
	stack_t *t;
	int l = 0;
	int indx;

	t = *head;
	while (t)
	{
		t = t->next;
		l++;
	}
	if (l < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack", cont);
		fclose(bus.pf);
		free(bus.buff);
		free_globv(*head);
		exit(EXIT_FAILURE);
	}
	t = *head;
	indx = t->n;
	t->n = t->next->n;
	t->next->n = indx;
}
