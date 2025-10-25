/**
 * @file Iterator.h
 * @brief Deklaracja szablonowego iteratora dla listy dwukierunkowej.
 * @date 2025-10-25
 */

#ifndef ITERATOR_H
#define ITERATOR_H

#include "Node.h"
#include <iterator>

 /**
  * @brief Szablonowy iterator klasy DoublyLinkedList.
  * @tparam T Typ danych przechowywanych w liœcie.
  */

template<typename T>
class DoublyListIterator {
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using reference = T&;
    using pointer = T*;

    explicit DoublyListIterator(Node<T>* ptr);
    reference operator*() const;
    pointer operator->() const;

    DoublyListIterator& operator++();  // ++it
    DoublyListIterator operator++(int); // it++
    DoublyListIterator& operator--();  // --it
    DoublyListIterator operator--(int); // it--

    bool operator==(const DoublyListIterator& other) const;
    bool operator!=(const DoublyListIterator& other) const;

private:
    Node<T>* current;
};

#endif // ITERATOR_H
