/* implementation of a stack type */
#include <stdio.h>
#include <stdlib.h>
#include "5_stack.h"

static void CopyToNode(Item item, Node * pnode);

/* set stack to empty */
void InitializeStack(Stack * pstack)
{
	*pstack = NULL;
}

/* return true if stack is empty */
bool StackIsEmpty(const Stack * pstack)
{
	return *pstack == NULL;
}

/* return true if stack is full */
bool StackIsFull(const Stack * pstack)
{
	Node * pt;
	bool full;

	pt = (Node *) malloc(sizeof(Node));
	if (pt == NULL)
		full = true;
	else
		full = false;
	free(pt);

	return full;
}

/* returns number of nodes */
unsigned int StackItemCount(const Stack * pstack)
{
	unsigned int count = 0;
	Node * pnode = *pstack;

	while (pnode != NULL) {
		++count;
		pnode = pnode->prev;
	}

	return count;
}

/* creates node to hold item and adds it to the top of */
/* the list pointed to by pstack                       */
bool PushItem(Item item, Stack * pstack)
{
	Node * pnew;
	Node * scan = *pstack;

	pnew = (Node *) malloc(sizeof(Node));

	if (pnew == NULL)
		return false;

	CopyToNode(item, pnew);
	if (*pstack == NULL)
		pnew->prev = NULL;
	else
		pnew->prev = *pstack;
	*pstack = pnew;

	return true;
}

/* pop item */
bool PopItem(Item * pitem, Stack * pstack)
{
	if (*pstack == NULL)
		return false;
	else {
		Node * prevnode = (*pstack)->prev;
		*pitem = (*pstack)->item;
		free(*pstack);
		*pstack = prevnode;
		return true;
	}
}

/* free memory and empty stack */
void EmptyTheStack(Stack * pstack)
{
	Node * psave;

	while (*pstack != NULL) {
		psave = (*pstack)->prev;
		free(*pstack);
		*pstack = psave;
	}
}

/* copies an item into a node */
static void CopyToNode(Item item, Node * pnode)
{
	pnode->item = item;
}
