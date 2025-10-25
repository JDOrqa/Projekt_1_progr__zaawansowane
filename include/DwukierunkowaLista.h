#ifndef DWUKIERUNKOWA_LISTA_H
#define  DWUKIERUNKOWA_LISTA_H

#include "NodeFactory.h"
#include <iostream>
#include <stdexcept>
#include "Iterator.h"

/**
 * @brief Prosta implementacja listy dwukierunkowej (heap allocation).
 * W tej czêœci implementujemy podstawowe operacje: push_front/back, pop_front/back,
 * display_forward/reverse, clear, size, empty.
 *
 * Metody zwi¹zane z indeksem zostan¹ dodane w drugiej czêœci.
 */

template<typename T>
class DwukierunkowaLista {
public:
    DwukierunkowaLista() : head(nullptr), tail(nullptr), sz(0) {}
    ~DwukierunkowaLista() { clear(); }


    // iterator support (forward)
    DoublyListIterator<T> begin() { return DoublyListIterator<T>(head); }
    DoublyListIterator<T> end() { return DoublyListIterator<T>(nullptr); }

    // const overloads (opcjonalne)
    DoublyListIterator<T> begin() const { return DoublyListIterator<T>(head); }
    DoublyListIterator<T> end() const { return DoublyListIterator<T>(nullptr); }

    //  NodeFactory
    void push_front(const T& value) {
        Node<T>* n = NodeFactory<T>::createNode(value);
        n->next = head;
        if (head) head->prev = n;
        head = n;
        if (!tail) tail = n;
        ++sz;
    }

    void push_back(const T& value) {
        Node<T>* n = NodeFactory<T>::createNode(value);
        n->prev = tail;
        if (tail) tail->next = n;
        tail = n;
        if (!head) head = n;
        ++sz;
    }

    void pop_front() {
        if (!head) return;
        Node<T>* to_delete = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        NodeFactory<T>::destroyNode(to_delete);
        --sz;
    }

    void pop_back() {
        if (!tail) return;
        Node<T>* to_delete = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        NodeFactory<T>::destroyNode(to_delete);
        --sz;
    }

    void clear() {
        Node<T>* cur = head;
        while (cur) {
            Node<T>* next = cur->next;
            NodeFactory<T>::destroyNode(cur);
            cur = next;
        }
        head = tail = nullptr;
        sz = 0;
    }

    bool empty() const { return sz == 0; }
    size_t size() const { return sz; }

    void display_forward() const {
        Node<T>* cur = head;
        std::cout << "[";
        bool first = true;
        while (cur) {
            if (!first) std::cout << " <-> ";
            std::cout << cur->data;
            first = false;
            cur = cur->next;
        }
        std::cout << "]\n";
    }

    void display_reverse() const {
        Node<T>* cur = tail;
        std::cout << "[";
        bool first = true;
        while (cur) {
            if (!first) std::cout << " <-> ";
            std::cout << cur->data;
            first = false;
            cur = cur->prev;
        }
        std::cout << "]\n";
    }

    /**
 * @brief Wstawia element o zadanym indeksie (0-based)
 * @throws std::out_of_range jeœli index > size
 */
    void insertAt(size_t index, const T& value) {
        if (index > sz) throw std::out_of_range("Index out of range");
        if (index == 0) { push_front(value); return; }
        if (index == sz) { push_back(value); return; }

        Node<T>* current = head;
        for (size_t i = 0; i < index - 1; ++i)
            current = current->next;

        Node<T>* newNode = NodeFactory<T>::createNode(value);
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
        ++sz;
    }

    /**
     * @brief Usuwa element o zadanym indeksie
     * @throws std::out_of_range jeœli index >= size
     */
    void removeAt(size_t index) {
        if (index >= sz) throw std::out_of_range("Index out of range");
        if (index == 0) { pop_front(); return; }
        if (index == sz - 1) { pop_back(); return; }

        Node<T>* current = head;
        for (size_t i = 0; i < index; ++i)
            current = current->next;

        current->prev->next = current->next;
        current->next->prev = current->prev;
        NodeFactory<T>::destroyNode(current);
        --sz;
    }

    /**
     * @brief Zwraca wartoœæ elementu o zadanym indeksie
     */
    T& getAt(size_t index) {
        if (index >= sz) throw std::out_of_range("Index out of range");
        Node<T>* current = head;
        for (size_t i = 0; i < index; ++i)
            current = current->next;
        return current->data;
    }


    
    Node<T>* getHead() const { return head; }
    Node<T>* getTail() const { return tail; }

private:
    Node<T>* head;
    Node<T>* tail;
    size_t sz;
};

#endif 
