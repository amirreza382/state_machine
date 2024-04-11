// LinkedList.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


// Definition of Node class
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T data) : data(data), next(nullptr), prev(nullptr) {}
};

// Difinition of LinkedList
template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    ~LinkedList();

    void addNode(T data);
    Node<T>* getHead() const { return head; }
    Node<T>* getTail() const { return tail; }
};

template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* currentNode = head;
    while (currentNode) {
        Node<T>* nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    head = tail = nullptr;  // Set pointers to nullptr after deletion
}


// Function for adding node and creating the linked list
template <typename T>
void LinkedList<T>::addNode(T data) {

    Node<T>* newNode = new Node<T>(data);

    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

#endif // LINKEDLIST_H
