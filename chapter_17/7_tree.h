#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>
#define MAX_LEN_WORD 50

typedef struct item
{
	char word[MAX_LEN_WORD];
	int occurence;
} Item;

#define MAXITEMS 10

typedef struct trnode
{
	Item item;
	struct trnode * left;
	struct trnode * right;
} Trnode;

typedef struct tree
{
	Trnode * root;
	int size;
} Tree;

/* operation: initialize a tree to empty            */
/* preconditions: ptree points to a tree            */
/* postconditions: the tree is initialized to empty */
void InitializeTree(Tree * ptree);

/* operation: determine if tree is empty             */
/* preconditions: ptree points to a tree             */
/* postconditions: function returns true if tree is  */
/*                 empty and returns false otherwise */
bool TreeIsEmpty(const Tree * ptree);

/* operation: determine if tree is full             */
/* preconditions: ptree points to a tree            */
/* postconditions: function returns true if tree is */
/*                 full and returns false otherwise */
bool TreeIsFull(const Tree * ptree);

/* operation: determine number of items in tree        */
/* preconditions: *ptree points to a tree              */
/* postconditions: function returns number of items in */
/*                 tree                                */
int TreeItemCount(const Tree * ptree);

/* operation: add an item to a tree                    */
/* preconditions: pi is address of item to be added    */
/*                ptree points to an initialized tree  */
/* postconditions: if possible, function adds item to  */
/*                 tree and returns true; otherwise,   */
/*                 the function returns false          */
bool AddItem(const Item * pi, Tree * ptree);

/* operation: find an item in a tree                    */
/* preconditions: pi points to an item                  */
/*                ptree points to an initialized tree   */
/* postconditions: function returns true if item is in  */
/*                 tree and returns false otherwise     */
bool InTree(const Item * pi, const Tree * ptree);

/* operation: delete an item from a tree                */
/* preconditions: pi is address of item to be deleted   */
/* ptree points to an initialized tree                  */
/* postconditions: if possible, function deletes item   */
/*                 from tree and returns true;          */
/*                 otherwise the function returns false */
bool DeleteItem(const Item * pi, Tree * ptree);

/* operation: apply a function to each item in          */
/*            the tree                                  */
/* preconditions: ptree points to a tree                */
/*                pfun points to a function that takes  */
/*                an Item argument and has no return    */
/*                value                                 */
/* postcondition: the function pointed to by pfun is    */
/*                executed once for each item in tree   */
void Traverse (const Tree * ptree, void (* pfun)(Item item));

/* operation: delete everything from a tree           */
/* preconditions: ptree points to an initialized tree */
/* postconditions: tree is empty                      */
void DeleteAll(Tree * ptree);

/* operation:     find the location of an item in a tree
 * precondition:  pi points to an item
 *                ptree points to an initialized tree
 * postconditions: a pointer to the item to corresponding 
 *                 to the item poited by pi is returned
 *                 (in this exercise we search item with specific name)
 *                 return NULL pointer if no match is found
 */
Item * FindItem(const Item * pi, const Tree * ptree);

#endif
