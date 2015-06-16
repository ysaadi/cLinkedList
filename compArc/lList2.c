/*
 * lList2.c
 *
 *  Created on: Jun 6, 2015
 *      Author: yaman
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lList2.h"


lList * list_new(size_t eleSize, freeFunction freeFn, comparator compare){
lList * newList= calloc(1,sizeof(lList));
newList->comparetwo=compare;
newList->freeFn=freeFn;
newList->elementSize=eleSize;
return newList;
}
lListNode *createNode(void* data){
	lListNode * newNode= malloc(sizeof(lListNode));
	newNode->data=data;
	return newNode;
}
int list_append(void* data, lList * list){
	lListNode *newNode= createNode(data);
	if(list->tail==0){
		if(list->first!=0){
			//error;
			return -1;
		}
		list->tail=list->first=newNode;
	}
	else{
		list->tail->Next=newNode;
		list->tail=newNode;
	}
	list->listSize++;
	return 0;
}
int list_prepend(void* data, lList * list){
	lListNode *newNode= createNode(data);
	if(list->first!=0){
		if(list->tail==0){
				//error;
				return -1;
			}
		list->tail=list->first=newNode;
	}
	newNode->Next=list->first;
	list->first=newNode;
	list->listSize++;
	return 0;
}
int list_insert(void* data, lList *list, lListNode * node){

	 if(node== list->tail){
		return list_append(data,list);

	}
	else{
		lListNode *newNode=createNode(data);
		newNode->Next=node->Next;
		node->Next=newNode;
		list->listSize++;
		return 0;
	}
}
int list_size(lList *list){
	return list->listSize;
}
lListNode * findElement(void* find,lList *list ){
	lListNode * ptr=list->first;
		if( ptr==0){
			return 0;
		}
		else{
			int i;
			do{
				i=list->comparetwo(ptr->data,find);
				if(i==0){
					return ptr;
				}
				ptr=ptr->Next;
			}while(ptr!=0);
		}
		return 0;
	}
int mapOntoList(iterateOver function, lList *list){
	lListNode * ptr=list->first;
	if( ptr==0){
		return 0;
	}
	else{
		do{
			function(ptr->data);
			ptr=ptr->Next;
		}while(ptr!=0);
	}
	return 0;
}
int freeList(lList * list){
	freeFunction freeFn=list->freeFn;
	lListNode * ptr=list->first;
	lListNode * prev;
	if( ptr==0){
		return 0;
	}
	else{
		do{
			freeFn(ptr->data);
			prev=ptr;
			ptr=ptr->Next;
			free(prev);
		}while(ptr!=0);
	}
	return 0;
}
