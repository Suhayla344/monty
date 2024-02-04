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

/**
 * add_dnodeint - add a note at the begining of the
 * @head: frist position of linked list
 * @n: data to store
 * Return: a doubly linked list
*/
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *ptr;

	if (head == NULL)
		return (NULL);
	ptr = malloc(sizeof(stack_t));
	if (!ptr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_globv();
		exit(EXIT_FAILURE);
	}
	ptr->n = n;
	if (*head == NULL)
	{
		ptr->next = *head;
		ptr->prev = NULL;
		*head = ptr;
		return (*head);
	}
	(*head)->prev = ptr;
	ptr->next = (*head);
	ptr->prev = NULL;
	*head = ptr;
	return (*head);
}
