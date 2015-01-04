/*	Author: Parker Mathewson					*
 *	Date: 4/18/12							*
 *	Comments: This is a program to help us practice using structs	*
 *			and linked lists. We will then print out in	*
 *			reverse.					*/

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

typedef struct node_s
{
	int data;
	struct node_s* next;
} node_t;

node_t* find_previous(node_t* target, node_t* head)
{
	node_t *previous, *current;

	if(head == target)
	{
		previous = head->next;
		current = head->next->next;
		while (current != target)
		{
			previous = current;
			current = current->next;
		}
		return previous;
	}
	else
	{
		previous = head;
		current = head->next;
		while (current != target)
		{
			previous = current;
			current = current->next;
		}
		return previous;
	}
	return NULL;
}

void delete_node(node_t* target, node_t* head)
{
	node_t* previous, temp;

	previous = find_previous(target, head);
	previous->next = target->next;
	free(target);
}

void print_function(node_t* pt, node_t* head)
{
	printf("%d ", pt->data);
	if(pt->next == head);
	else
		print_function(pt->next, head);
}

int main(void)
{
	int data_insert = 0;
	node_t *headp, *temp, *current=NULL;

	for(data_insert = 0; data_insert < 5; data_insert++)
	{
		temp =(node_t*)malloc(sizeof(node_t));
		temp->data=data_insert;
		temp->next = headp;

		if(current == NULL) headp=temp;
		else current->next=temp;
		current = temp;
	}

	print_function(headp, headp);
	delete_node(headp->next->next, headp);
	printf("\nDeleting headp->next->next\n");
	print_function(headp, headp);

	return(0);
}
