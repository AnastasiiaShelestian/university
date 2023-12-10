#include <iostream>
#include <assert.h>
using namespace std;

struct Node
{
    int value;
    Node* next;
};

struct Queue
{
    Node* first;
    Node* last;
    int length;
};

Node* createNode(int value)
{
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;
    return newNode;
}

Queue* createQueue() {
    Queue* queue = new Queue;
    queue->length = 0;
    queue->first = nullptr;
    queue->last = nullptr;
    return queue;
}

bool isEmpty(Queue* queue) {
    if (queue->first == nullptr && queue->last == nullptr)
    {
        return true;
    }
    return false;
}

void enqueue(Queue* queue, int value) {
    Node* newNode = createNode(value);
    if (isEmpty(queue))
    {
        queue->first = newNode;
        queue->last = newNode;
    }
    else
    {
        queue->last->next = newNode;
        queue->last = newNode;
    }
    queue->length++;
}

int dequeue(Queue* queue) {
    int value = -1;
    if (!isEmpty(queue)) {
        value = queue->first->value;
        Node* temp = queue->first->next;
        delete queue->first;
        queue->first = temp;
    }
    queue->length--;
    return value;
}

void test1() {
    Queue* queue = createQueue();
    enqueue(queue, 5);
    enqueue(queue, 10);
    enqueue(queue, 7);
    enqueue(queue, 11);

    assert(queue->length == 4);
    assert(queue->first->value == 5);
    assert(queue->last->value == 11);
}

void test2() {
    Queue* queue = createQueue();
    enqueue(queue, 2);
    enqueue(queue, 4);
    enqueue(queue, 3);

    assert(queue->length == 3);
    assert(queue->first->value == 2);
    assert(queue->last->value == 3);
    
    dequeue(queue);
    assert(queue->length == 2);
    assert(queue->first->value == 4);
}

void test3() {
    Queue* queue = createQueue();
    assert(isEmpty(queue) == true);
    assert(queue->length == 0);

    enqueue(queue, 5);
    enqueue(queue, 10);

    assert(isEmpty(queue) == false);
    assert(queue->length == 2);
}

int main()
{
    test1();
    test2();
    test3();
}
