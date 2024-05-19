#ifndef NODE
#define NODE

template <typename T>
class SinglyLinkedList;

template <typename T>
class SinglyLinkedListOrdered;

template <typename T>
class SinglyLinkedListUnordered;

template <typename T>
class Node
{
    private :
        T item;
        Node<T> *next;

    public:
        Node(T item);

    template <typename K>
    friend class SinglyLinkedList;
    template <typename K>
    friend class SinglyLinkedListOrdered;
    template <typename K>
    friend class SinglyLinkedListUnordered;
};


#endif