/**
 * @file Iterator.cpp
 * @brief Implementacja iteratora dla listy dwukierunkowej.
 * @date 2025-10-25
 */

#include "Iterator.h"
#include <string>

template<typename T>
DoublyListIterator<T>::DoublyListIterator(Node<T>* ptr) : current(ptr) {}

template<typename T>
typename DoublyListIterator<T>::reference DoublyListIterator<T>::operator*() const {
    return current->data;
}

template<typename T>
typename DoublyListIterator<T>::pointer DoublyListIterator<T>::operator->() const {
    return &(current->data);
}

template<typename T>
DoublyListIterator<T>& DoublyListIterator<T>::operator++() {
    if (current) current = current->next;
    return *this;
}

template<typename T>
DoublyListIterator<T> DoublyListIterator<T>::operator++(int) {
    DoublyListIterator temp = *this;
    ++(*this);
    return temp;
}

template<typename T>
DoublyListIterator<T>& DoublyListIterator<T>::operator--() {
    if (current) current = current->prev;
    return *this;
}

template<typename T>
DoublyListIterator<T> DoublyListIterator<T>::operator--(int) {
    DoublyListIterator temp = *this;
    --(*this);
    return temp;
}

template<typename T>
bool DoublyListIterator<T>::operator==(const DoublyListIterator& other) const {
    return current == other.current;
}

template<typename T>
bool DoublyListIterator<T>::operator!=(const DoublyListIterator& other) const {
    return current != other.current;
}

// Jawne instancjonowanie
template class DoublyListIterator<int>;
template class DoublyListIterator<double>;
template class DoublyListIterator<std::string>;
