/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) 
{
	if (head == NULL)
		return NULL;

	struct node *p = head;
	struct node *q = head->next;
	struct node *q_trace = NULL;
	struct node *temp1 = NULL;
	
	if (q != NULL)
	{
		q_trace = q->next;
	}

	while (q_trace != NULL)
	{
		p->next = NULL;
		q->next = NULL;
		q->next = p;
		p->next = temp1;
		temp1 = q;
		p = q_trace;
		q = q_trace->next;
		if (q_trace->next != NULL)
			q_trace = q_trace->next->next;
		else
			q_trace = NULL;
	}
	if (q_trace == NULL && q!=NULL)
	{
		p->next = NULL;
		q->next = NULL;
		q->next = p;
		p->next = temp1;
		temp1 = q;
	}
	if (p->next == NULL && q == NULL)
	{
		p->next = temp1;
		temp1 = p;
	}
	head = temp1;
	return head;
}
