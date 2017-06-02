#include "../datalib/linked_queue.h"

using namespace std;

void debugDequeue(LinkedQueue<string> *queue) {
    cout << "Removed the element: " << queue->dequeue() << "." << endl;
}

void debugEnqueue(LinkedQueue<string> *queue, string added) {
    queue->enqueue(added);
    cout << "Added the element: " << added << "." << endl;
}


int main() {
    LinkedQueue<string> queue = LinkedQueue<string>();

    debugEnqueue(&queue, "First");
    debugEnqueue(&queue, "Second");

    debugEnqueue(&queue, "Third");
    debugEnqueue(&queue, "Forty");

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


    cout << endl << "The remaining elements are: " << endl;
    queue.printLinkedQueue();

    return 0;
}

// Explicit instantiations of all the templates used in the file

template
class LinkedQueue<string>;

template
class Node<string>;
