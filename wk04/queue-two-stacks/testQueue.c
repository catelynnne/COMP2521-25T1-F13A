
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

int main(void) {
	Queue q = QueueNew();

	QueueEnqueue(q, 3);

	QueueEnqueue(q, 1);

	QueueEnqueue(q, 4);

	assert(QueueDequeue(q) == 3);

	assert(QueueDequeue(q) == 1);

	QueueEnqueue(q, 1);

	QueueEnqueue(q, 5);

	assert(QueueDequeue(q) == 4);

	assert(QueueDequeue(q) == 1);

	assert(QueueDequeue(q) == 5);

	QueueFree(q);

	printf("Tests passed!\n");
}

