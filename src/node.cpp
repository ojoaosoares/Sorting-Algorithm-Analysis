#include "node.hpp"
#include <cstdint>

// Node implementation

template <typename T>
Node<T>::Node(T item) : item(item), next(nullptr) {}

template class Node<long long>;
template class Node<int>;
template class Node<double>;

template class Node<int64_t>;
template class Node<uint32_t>;
template class Node<uint64_t>;
