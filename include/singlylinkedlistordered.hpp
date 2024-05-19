#ifndef SINGLY_LINKED_LIST_ORDERED
#define SINGLY_LINKED_LIST_ORDERED

#include "singlylinkedlist.hpp"

template  <typename T>
class SinglyLinkedListOrdered : public  SinglyLinkedList<T>
{   
    public :
        SinglyLinkedListOrdered();
        ~SinglyLinkedListOrdered();

        void insert(T item);
        int search(T item) const override;

};


#endif