CC = gcc
CFLAGS = -g -Wall


default: intLinkedList

intLinkedList:  intLinkedList.o #lList2.o
	$(CC) $(CFLAGS) -o intLinkedList intLinkedList.o 

intLinkedList.o:  lList2.h lList2.c intLinkedList.c 
	$(CC) $(CFLAGS) -c intLinkedList.c

lList2.o: lList2.c lList2.h
	$(CC) $(CFLAGS) -c lList2.c
clean:
	$(RM) intLinkedList
	$(RM) intLinkedList.o
	$(RM) lList2.o