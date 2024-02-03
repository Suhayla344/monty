#include "monty.h"

/**
 *
 *
 */
void _add(stack_t **head, unsigned int line)
{
	stack_t *pp;
	int length = 0, vx;

	pp = *head;
	while (pp)
	{
		pp = pp->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		fclose(globv.pf);
		free(globv.buff);
		free_globv(*head);
		exit(EXIT_FAILURE);
	}
	pp = *head;
	vx = pp->n + pp->next->n;
	pp->next->n = vx;
	*head = pp->next;
	free(pp);

}
