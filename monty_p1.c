#include "main.h"
/**
 * _push - this function pushes element to the  stack
 * @element: this is an element
 * @line: this is error line
 */

void _push(stack_t **element, unsigned int line)
{
	int x, y;

	if (!globv.arg)
	{
		dprintf(2, "L%u", line);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	for (x = 0; globv.arg[x] != NULL; x++)
	{
		if (!isdigit(globv.arg[x]) && globv.arg[x] != '-')
		{
			dprintf(2, "L%u", line);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}
	y = atoi(globv.arg);
	if (globav.info == 1)
		add_dnodeint(element, y);
	else
		add_dnodeint_end(element, y);
}
