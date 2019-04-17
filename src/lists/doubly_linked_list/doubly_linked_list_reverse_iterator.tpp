#include "doubly_linked_list_reverse_iterator.h"

template <typename T>
DoublyLinkedListReverseIterator<T>::
DoublyLinkedListReverseIterator(NodePtr current)
    : Parent(current) {}

template <typename T>
DoublyLinkedListReverseIterator<T>&
DoublyLinkedListReverseIterator<T>::operator ++ () {
    Parent::current = Parent::current->prev;
    return *this;
}


template <typename T>
DoublyLinkedListReverseIterator<T>&
DoublyLinkedListReverseIterator<T>::operator -- () {
    Parent::current = Parent::current->next;
    return *this;
}
