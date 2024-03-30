#include <iostream>
#include <assert.h>
using namespace std;

struct Node
{
    int value;
    Node* next;
};

struct SingleLinkedList
{
    Node* first;
    Node* last;
    int length;
};

struct FindNodeResult {
    Node* previous;
    Node* current;
};

Node* createNode(int value)
{
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;
    return newNode;
}

SingleLinkedList* createList() {
    SingleLinkedList* list = new SingleLinkedList;
    list->length = 0;
    list->first = nullptr;
    list->last = nullptr;
    return list;
}

FindNodeResult find(SingleLinkedList* list, int value) {
    FindNodeResult result;
    result.previous = nullptr;
    result.current = list->first;

    for (Node* i = list->first; i != nullptr; i = i->next) 
    {
        if (i->value == value)
            return result;
        else
        {
            result.previous = i;
            result.current = i->next;
        }
    }
    return result;
}


Node* insertAfter(SingleLinkedList* list, Node* node, int value) {
    Node* newNode = createNode(value);
    if (list->first == nullptr)
    {
        list->first = newNode;
        list->last = list->first;
    }
    else if (node == nullptr) {
        newNode->next = list->first;
        list->first = newNode;
    }
    else 
    {
        newNode->next = node->next;
        node->next = newNode;
        if (newNode->next == nullptr)
        {
            list->last = newNode;
        }
    }
    list->length++;
    return newNode;
}

void removeAfter(SingleLinkedList* list, Node* node) {

    if (node == nullptr) {
        Node* temp = list->first->next;
        delete list->first;
        list->first = list->first->next;
    }
    else
    {
        Node* temp = node->next->next;
        delete node->next;
        node->next = temp;
    }
    list->length--;
}

void assertNoCycles(SingleLinkedList* list)
{
    if (list != nullptr)
    {
        int length = 0;
        for (Node* i = list->first; i != nullptr; i = i->next)
        {
            length++;
        }
        assert(list->length == length);
    }
}

int main()
{
    SingleLinkedList* list = createList();
    Node* node1 = insertAfter(list, nullptr, 5);
    Node* node2 = insertAfter(list, node1, 11);
    Node* node3 = insertAfter(list, node2, 12);
    assert(list->length == 3); 
    assert(list->first->value == 5);
    assert(list->last->value == 12);
    assertNoCycles(list);

    FindNodeResult res = find(list, 11);
    assert(res.current->value == 11);
    assert(res.previous->value == 5);

    res = find(list, 5);
    assert(res.current->value == 5);
    assert(res.current->next->value == 11);
    assert(res.current->next->next->value == 12);
    assert(res.previous == nullptr);

    removeAfter(list, res.current);
    assert(list->first->value == 5);
    assert(list->first->next->value == 12);
}
