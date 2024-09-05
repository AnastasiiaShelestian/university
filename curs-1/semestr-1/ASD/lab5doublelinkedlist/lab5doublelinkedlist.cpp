#include <iostream>
#include <assert.h>
using namespace std;

struct Node
{
    int value;
    Node* next;
    Node* prev;
};

struct DoubleLinkedList
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
    newNode->prev = nullptr;
    return newNode;
}

DoubleLinkedList* createList() {
    DoubleLinkedList* list = new DoubleLinkedList;
    list->length = 0;
    list->first = nullptr;
    list->last = nullptr;
    return list;
}

Node* find(DoubleLinkedList* list, int value) {
    for (Node* i = list->first; i != nullptr; i = i->next)
    {
        if (i->value == value)
            return i;
    }
    return nullptr;
}

Node* insertAfter(DoubleLinkedList* list, Node* node, int value) {
    Node* newNode = createNode(value);
    if (list->first == nullptr)
    {
        list->first = newNode;
        list->last = list->first;
    }
    else if (node == nullptr) {
        newNode->next = list->first;
        list->first = newNode;
        newNode->next->prev = newNode;
    }
    else
    {
        newNode->prev = node;
        newNode->next = node->next;
        if(newNode->prev)
            newNode->prev->next = newNode;
        if (newNode->next)
            newNode->next->prev = newNode;
        if (newNode->next == nullptr)
        {
            list->last = newNode;
        }
    }
    list->length++;
    return newNode;
}

Node* insertBefore(DoubleLinkedList* list, Node* node, int value) {
    Node* newNode;
    if (list->first == nullptr || node == nullptr) {
        newNode = insertAfter(list, nullptr, value);
    }
    else
    {
        newNode = createNode(value);
        newNode->prev = node->prev;
        newNode->next = node;
        if (newNode->prev)
            newNode->prev->next = newNode;
        if (newNode->next)
            newNode->next->prev = newNode;
        if (newNode->prev == nullptr)
        {
            list->first = newNode;
        }
    }
    list->length++;
    return newNode;
}

void remove(DoubleLinkedList* list, Node* node) {

    if (node == nullptr) {
        Node* temp = list->first->next;
        delete list->first;
        list->first = list->first->next;
        list->first->prev = nullptr;
    }
    else
    {
        if(node->next)
            node->next->prev = node->prev;
        if(node->prev)
            node->prev->next = node->next;
        delete node;
    }
    list->length--;
}

void assertNoCycles(DoubleLinkedList* list)
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
    DoubleLinkedList* list = createList();
    Node* node1 = insertAfter(list, nullptr, 5);
    Node* node2 = insertAfter(list, node1, 11);
    Node* node4 = insertAfter(list, node2, 12);
    Node* node3 = insertBefore(list, node4, 3);
    assert(list->length == 4);
    assertNoCycles(list);

    assert(list->first->value == 5);
    assert(list->last->value == 12);
    assert(list->last->prev->value == 3);

    Node* res = find(list, 11);
    assert(res->value == 11);
    assert(res->prev->value == 5);

    res = find(list, 5);
    assert(res->value == 5);
    assert(res->next->value == 11);
    assert(res->prev == nullptr);

    remove(list, node2);
    assert(list->first->next->value == 3);
    assert(list->first->next->prev->value == 5);
}
