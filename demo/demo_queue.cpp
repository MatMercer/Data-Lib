#include <iostream>
#include "../datalib/queue.h"

using namespace std;

void debugDequeue(Queue<string> *queue) {
    cout << "Removed the element: " << queue->dequeue() << "." << endl;
}

void debugEnqueue(Queue<string> *queue, string added) {
    queue->enqueue(added);
    cout << "Added the element: " << added << "." << endl;
}

void debugQueueSize(Queue<string> *queue) {
     cout << endl << "The size of the queue is: " << queue->queueSize() << endl;
}


int main() {
    Queue<string> queue = Queue<string>(1);

    debugQueueSize(&queue);

    debugEnqueue(&queue, "First");
    debugEnqueue(&queue, "Second");

    debugQueueSize(&queue);

    debugEnqueue(&queue, "Third");
    debugEnqueue(&queue, "Forty");

    debugQueueSize(&queue);

    debugDequeue(&queue);
    debugDequeue(&queue);

    debugEnqueue(&queue, "Fifty");
    debugEnqueue(&queue, "Sixty");
    debugEnqueue(&queue, "Seventy");
    debugEnqueue(&queue, "Eighty");
    debugEnqueue(&queue, "Ninety");
    debugEnqueue(&queue, "Tenth");

    debugDequeue(&queue);
    debugDequeue(&queue);
    debugDequeue(&queue);
    debugDequeue(&queue);
    debugDequeue(&queue);

    debugQueueSize(&queue);

    cout << endl << "The remaining elements are: " << endl;
    queue.printQueue();

    return 0;
}

// Explicit instantiations of all the templates used in the file
template
class Queue<int>;

template
class Queue<string>;
