/* implementation of a stack type */
#ifndef STACK_H_
#define STACK_H_
#include <stdbool.h>

typedef char Item;

typedef struct node {
	Item item;
	struct node * prev;
} Node;

typedef Node * Stack;

/* function prototypes */

/* operation: */
/* preconditions: */
/* postconditions: */

/* operation:        initialize a stack                          */
/* preconditions:    pstack points to a stack                    */
/* postconditions:   the stack is initialized to empty           */
void InitializeStack(Stack * pstack);

/* operation:        determine if stack is empty                 */
/* preconditions:    pstack points to an initialized stack       */
/* postconditions:   function return True if list is empty       */
/*                   and returns False otherwise                 */
bool StackIsEmpty(const Stack * pstack);

/* operation:        determine if stack is full                  */
/* preconditions:    pstack points to an initialized stack       */
/* postconditions:   function return True if list is full        */
/*                   and returns False otherwise                 */
bool StackIsFull(const Stack * pstack);

/* operation:        determine number of items in list           */
/* preconditions:    pstack points to an initialized stack       */
/* postconditions:   function return number of items in stack    */
unsigned int StackItemCount(const Stack * pstack);

/* operation:        push item on top of the stack               */
/* preconditions:    item is an item to be added to stack        */
/*                   pstack points to an initialized stack       */
/* postconditions:   if possible, function adds item to the top  */
/*                   of stack and returns True; otherwise the    */
/*                   function returns False                      */
bool PushItem(Item item, Stack * pstack);

/* operation:        pop item from top of the stack              */
/* preconditions:    pitem points to the where the popped item   */
/*                   should go                                   */
/*                   pstack points to an initialized stack       */
/* postconditions:   if stack is not empty, function pops the 
/*                   top item from the stack to pitem and        */
/*                   returns True; otherwise the function        */
/*                   returns False                               */
bool PopItem(Item * pitem, Stack * pstack);


/* operation:        free allocated memory, if any               */
/* preconditions:    pstack points to an initialized stack       */
/* postconditions:   any memory allocated for the stack is freed */
/*                   and the stack is set to empty               */
void EmptyTheStack(Stack * pstack);

#endif
