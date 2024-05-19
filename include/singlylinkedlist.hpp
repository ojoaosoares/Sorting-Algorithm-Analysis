#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include "list.hpp"
#include "node.hpp"

template  <typename T>
class SinglyLinkedList : public  List<T>
{

    protected :
        Node<T>* head;
        Node<T>* tail;
        virtual Node<T>* getPosition(int index, bool before = false) const;
    
    public :
        SinglyLinkedList();
        ~SinglyLinkedList();
        
        virtual T getItem(int index) const override;
        virtual T removeBegin() override;
        virtual T removeEnd() override;
        virtual T removeIndex(int index) override;
        virtual int search(T item) const = 0;
        virtual void copyArray(T* array, int size);
        virtual void printList() const override;
        virtual void clear() override;

};


#endif