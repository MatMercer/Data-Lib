#include <iostream>
#include "../datalib/queue.h"

using namespace std;

int main() {
    Queue<string> queue = Queue<string>(3);

    queue.enqueue("First");
    queue.enqueue("Second");
    queue.enqueue("Third");

    queue.dequeue();

    queue.enqueue("Forty");

    queue.dequeue();
    queue.dequeue();

    queue.enqueue("Fifth");
    queue.enqueue("Sixth");

    queue.dequeue();

    queue.enqueue("Seventy");

    while (!queue.empty()) {
        cout << queue.dequeue() << endl;
    }

    return 0;
}

// Explicit instantiations of all the templates used in the file
template
class Queue<int>;
template
class Queue<string>;
