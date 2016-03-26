/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) 
{
	int count = 0;
	struct node *temp = head;
	if (head == NULL)
		return NULL;

	while (temp != NULL)
	{
		count++;
		if (count == K)
		{
			struct node *InsertNode = (struct node*)malloc(sizeof(struct node));
			struct node *q;
			InsertNode->num = K;
			InsertNode->next = NULL;
			q = temp->next;
			temp->next = InsertNode;
			InsertNode->next = q;
			temp = temp->next;
			count = 0;
		}
		temp = temp->next;
	}
	return head;
}
