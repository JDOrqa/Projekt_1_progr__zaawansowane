#ifndef ITERATOR_H
#define ITERATOR_H

#include "Node.h"
#include <iterator>

/**
 * @brief Prosty forward iterator dla DoublyLinkedList.
 * Implementacja minimalna: operator++, operator*, operator==, operator!=
 */

template<typename T>
class DoublyListIterator {
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using reference = T&;
    using pointer = T*;
    using difference_type = std::ptrdiff_t;

    explicit DoublyListIterator(Node<T>* ptr) : current(ptr) {}

    reference operator*() const { return current->data; }
    pointer operator->() const { return &(current->data); }

    // pre-increment
    DoublyListIterator& operator++() {
        if (current) current = current->next;
        return *this;
    }

    // post-increment
    DoublyListIterator operator++(int) {
        DoublyListIterator tmp = *this;
        ++(*this);
        return tmp;
    }

    bool operator==(const DoublyListIterator& other) const { return current == other.current; }
    bool operator!=(const DoublyListIterator& other) const { return current != other.current; }

private:
    Node<T>* current;
};

#endif // ITERATOR_H
