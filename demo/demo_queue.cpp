#include <iostream>
#include "../datalib/queue.h"

using namespace std;

int main() {
    Queue<int> queue = Queue<int>(3);
}

// Explicit instantiations of all the templates used in the file
template
class Queue<int>;
