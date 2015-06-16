/*
 * lList2.h
 *
 *  Created on: Jun 6, 2015
 *      Author: yaman
 */
/*credit to:  http://pseudomuto.com/development/2013/05/02/implementing-a-generic-linked-list-in-c/
 * for inspiraton/base code modified by Yaman Saadi*/
#ifndef LLIST2_H_
#define LLIST2_H_
// pass in t
typedef void (*freeFunction)(void*);
typedef enum {FALSE, TRUE} bool;
//compares two datastructures.  returns an int in case the structs are sortable.
typedef int (*comparator)(void* dat1, void* dat2);
typedef int (*iterateOver)(void* data);
typedef struct lListNode{
	void* data;
	struct lListNode *Next;
}lListNode;
typedef struct{
	//to maintain a list, must have a pointer to the beginning of the list.
	//I also have a pointer to the end for convenience ( to append)
	lListNode * first;
	lListNode * tail;
	/*list size maintains the number of elements in the linked list.
	 * element size lets us know how large the element is  */
	int listSize;
	size_t elementSize;
	freeFunction freeFn;
	comparator comparetwo;

}lList;
/* psuedo retruns a void and passes a pointer to list in order to create a new list
 * not sure why he wouldnt just return a list pointer.
 */
lList * list_new(size_t eleSize, freeFunction freeFn, comparator compare);
lListNode *createNode(void* data);
void list_destroy(lList *list);
int list_append( void *data, lList * list);
int list_prepend(void *data, lList * list);
//list_insert just inserts after a node
int list_insert(void* data, lList *list, lListNode * node);
int list_size(lList* list);
lListNode * findElement(void* find,lList *list );
/*applies the function function onto every element in the list.  like
the map function in scheme.
*/
int mapOntoList(iterateOver function, lList* list);
 /*I am m
  *
  */
int freeList(lList * list);
#endif /* LLIST2_H_ */
