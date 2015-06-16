/*
 * intLinkedList.c
 *
 *  Created on: Jun 16, 2015
 *      Author: yaman
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lList2.h"
#include "lList2.c"

int intComparator(void * in1, void * in2){
	int* i1=(int*) in1;
	int* i2=(int*) in2;
	return *i2-*i1;
}

void intFreeFunc(void * in){
	//int* num= (int*) in;
	free(in);
	return;
}

int printInts(void * in){
	int* num= (int*) in;
	printf("%d\n", *num);
	return 0;
}

int main(int argc, char** argv){
	lList * list;
	freeFunction freeFun= &intFreeFunc;
	comparator intCompare= &intComparator;
	iterateOver printFun= &printInts;
	list=list_new(sizeof(int),freeFun, intCompare );


}
