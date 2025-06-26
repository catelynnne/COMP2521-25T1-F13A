// Implementation of the Queue ADT using two stacks

#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"
#include "Stack.h"

struct queue {
	Stack s1;
	Stack s2;
};

/**
 * Creates a new, empty Queue
 */
Queue QueueNew(void) {
	Queue q = malloc(sizeof(struct queue));
	if (q == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	q->s1 = StackNew();
	q->s2 = StackNew();
	return q;
}

/**
 * Frees memory allocated to a Queue
 */
void QueueFree(Queue q) {
	StackFree(q->s1);
	StackFree(q->s2);
	free(q);
}

/**
 * Adds an item to the end of a Queue
 */
void QueueEnqueue(Queue q, Item it) {
	// TODO
}

/**
 * Removes an item from the front of a Queue
 * Assumes that the Queue is not empty
 */
Item QueueDequeue(Queue q) {
	// TODO
	return 0;
}
