
/**
 * @file DwukierunkowaLista.cpp
 * @brief Implementacja metod szablonu klasy DwukierunkowaLista.
 * @date 2025-10-25
 */

#include "DwukierunkowaLista.h"
#include <string>

template<typename T>
DwukierunkowaLista<T>::DwukierunkowaLista() : head(nullptr), tail(nullptr), sz(0) {}

template<typename T>
DwukierunkowaLista<T>::~DwukierunkowaLista() { clear(); }

/**
 * @brief Dodaje element na pocz¹tek listy.
 * @param value Wartoœæ do dodania.
 */

template<typename T>
void DwukierunkowaLista<T>::push_front(const T& value) {
    Node<T>* n = NodeFactory<T>::createNode(value);
    n->next = head;
    if (head) head->prev = n;
    head = n;
    if (!tail) tail = n;
    ++sz;
}

template<typename T>
void DwukierunkowaLista<T>::push_back(const T& value) {
    Node<T>* n = NodeFactory<T>::createNode(value);
    n->prev = tail;
    if (tail) tail->next = n;
    tail = n;
    if (!head) head = n;
    ++sz;
}




template<typename T>
void DwukierunkowaLista<T>::pop_front() {
    if (!head) return;
    Node<T>* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    NodeFactory<T>::destroyNode(temp);
    --sz;
}

template<typename T>
void DwukierunkowaLista<T>::pop_back() {
    if (!tail) return;
    Node<T>* temp = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    NodeFactory<T>::destroyNode(temp);
    --sz;
}

template<typename T>
void DwukierunkowaLista<T>::clear() {
    Node<T>* cur = head;
    while (cur) {
        Node<T>* next = cur->next;
        NodeFactory<T>::destroyNode(cur);
        cur = next;
    }
    head = tail = nullptr;
    sz = 0;
}

template<typename T>
bool DwukierunkowaLista<T>::empty() const { return sz == 0; }

template<typename T>
size_t DwukierunkowaLista<T>::size() const { return sz; }

template<typename T>
void DwukierunkowaLista<T>::display_forward() const {
    Node<T>* cur = head;
    std::cout << "[";
    while (cur) {
        std::cout << cur->data;
        if (cur->next) std::cout << " <-> ";
        cur = cur->next;
    }
    std::cout << "]\n";
}

template<typename T>
void DwukierunkowaLista<T>::display_reverse() const {
    Node<T>* cur = tail;
    std::cout << "[";
    while (cur) {
        std::cout << cur->data;
        if (cur->prev) std::cout << " <-> ";
        cur = cur->prev;
    }
    std::cout << "]\n";
}

template<typename T>
void DwukierunkowaLista<T>::insertAt(size_t index, const T& value) {
    if (index > sz) throw std::out_of_range("Index out of range");
    if (index == 0) { push_front(value); return; }
    if (index == sz) { push_back(value); return; }

    Node<T>* cur = head;
    for (size_t i = 0; i < index - 1; ++i) cur = cur->next;

    Node<T>* n = NodeFactory<T>::createNode(value);
    n->next = cur->next;
    n->prev = cur;
    cur->next->prev = n;
    cur->next = n;
    ++sz;
}

template<typename T>
void DwukierunkowaLista<T>::removeAt(size_t index) {
    if (index >= sz) throw std::out_of_range("Index out of range");
    if (index == 0) { pop_front(); return; }
    if (index == sz - 1) { pop_back(); return; }

    Node<T>* cur = head;
    for (size_t i = 0; i < index; ++i) cur = cur->next;
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    NodeFactory<T>::destroyNode(cur);
    --sz;
}

template<typename T>
T& DwukierunkowaLista<T>::getAt(size_t index) {
    if (index >= sz) throw std::out_of_range("Index out of range");
    Node<T>* cur = head;
    for (size_t i = 0; i < index; ++i) cur = cur->next;
    return cur->data;
}

template<typename T>
DoublyListIterator<T> DwukierunkowaLista<T>::begin() { return DoublyListIterator<T>(head); }

template<typename T>
DoublyListIterator<T> DwukierunkowaLista<T>::end() { return DoublyListIterator<T>(nullptr); }


template<typename T>
Node<T>* DwukierunkowaLista<T>::getHead() const {
    return head;
}

template<typename T>
Node<T>* DwukierunkowaLista<T>::getTail() const {
    return tail;
}


// Jawne instancjonowanie
template class DwukierunkowaLista<int>;
template class DwukierunkowaLista<double>;
template class DwukierunkowaLista<std::string>;
