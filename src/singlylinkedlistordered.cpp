#include "singlylinkedlistordered.hpp"
#include <cstdint>

// Singly Linked List Ordered  implementation

template  <typename T>
SinglyLinkedListOrdered<T>::SinglyLinkedListOrdered() : SinglyLinkedList<T>() {}

template  <typename T>
SinglyLinkedListOrdered<T>::~SinglyLinkedListOrdered() {}

template  <typename T>
void SinglyLinkedListOrdered<T>::insert(T item)
{
    Node<T>* newNode = new Node<T>(item);

    if (this->Empty())
    {
        newNode->next = nullptr;
        this->head = newNode; this->tail = newNode; 
    }

    else if (item >= this->tail->item)
    {
        this->tail->next = newNode;
        newNode->next = nullptr;
        this->tail = newNode;
    }

    else
    {

        Node<T>* previous = nullptr;
        Node<T>* current = this->head;

        while (current != nullptr)
        {
            if (current->item >= item) break;

            previous = current;
            current = current->next;
        }

        
        newNode->next = current;

        if (previous == nullptr)
            this->head = newNode;

        else
            previous->next = newNode;
        

        if (current == nullptr)
            this->tail = newNode;
    }

    this->size++;
}

template  <typename T>
int SinglyLinkedListOrdered<T>::search(T item) const
{
    if(this->Empty())
        throw "ERROR: Empty list";

    Node<T>* p = this->head;

    int i = 0;

    while (p != nullptr)
    {
        if (p->item > item) break;
        else if (p->item == item) return i;
        
        p = p->next;

        i++;
    }

    return -1;

}


template class SinglyLinkedListOrdered<long long>;
template class SinglyLinkedListOrdered<int>;
template class SinglyLinkedListOrdered<double>;

template class SinglyLinkedListOrdered<int64_t>;
template class SinglyLinkedListOrdered<uint32_t>;
template class SinglyLinkedListOrdered<uint64_t>;