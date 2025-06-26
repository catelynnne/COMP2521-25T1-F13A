
#ifndef QUEUE_H
#define QUEUE_H

typedef int Item;

typedef struct queue *Queue;

/**
 * Creates a new, empty Queue
 */
Queue QueueNew(void);

/**
 * Frees memory allocated to a Queue
 */
void QueueFree(Queue q);

/**
 * Adds an item to the end of a Queue
 */
void QueueEnqueue(Queue q, Item it);

/**
 * Removes an item from the front of a Queue
 * Assumes that the Queue is not empty
 */
Item QueueDequeue(Queue q);

#endif
