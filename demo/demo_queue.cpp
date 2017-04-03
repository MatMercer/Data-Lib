#include <iostream>
#include "../datalib/queue.h"

using namespace std;

void debugDequeue(Queue<string> *queue) {
    cout << "Removed the element: " << queue->dequeue() << "." << endl;
}

void debugQueue(Queue<string> *queue, string added) {
    queue->enqueue(added);
    cout << "Added the element: " << added << "." << endl;
}


int main() {
    Queue<string> queue = Queue<string>(3);

    debugQueue(&queue, "First");
    debugQueue(&queue, "Second");
    debugQueue(&queue, "Third");
    debugQueue(&queue, "Forty");

    debugDequeue(&queue);
    debugDequeue(&queue);
    debugDequeue(&queue);

    debugQueue(&queue, "Fifty");

    cout << endl << "The remaining elements are: " << endl;
    queue.printQueue();

    return 0;
}

// Explicit instantiations of all the templates used in the file
template
class Queue<int>;

template
class Queue<string>;
