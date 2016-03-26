/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) 
{
	int front = 0, back, median = 0;
	if (head == NULL)
		return -1;

	if (head->next == NULL)
	{
		return head->num;
	}

	struct node *temp = head;
	while (temp != NULL)
	{
		front++; back = 0;
		struct node *temp1 = temp->next;
		while (temp1 != NULL)
		{
			back++;
			temp1 = temp1->next;
		}
		if (front == back)
		{
			median = (temp->num + temp->next->num) / 2;	break;
		}
		if (front == back - 1)
		{
			median = temp->next->num;	break;
		}
		temp = temp->next;
	}

	return median;
}
