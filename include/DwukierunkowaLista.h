
/**
 * @file DwukierunkowaLista.h
 * @brief Deklaracja szablonowej klasy DwukierunkowaLista.
 * @date 2025-10-25
 */

#ifndef DWUKIERUNKOWA_LISTA_H
#define  DWUKIERUNKOWA_LISTA_H

#include "NodeFactory.h"
#include <iostream>
#include <stdexcept>
#include "Iterator.h"

 /**
  * @brief Szablonowa implementacja listy dwukierunkowej.
  * @tparam T Typ danych przechowywanych w liœcie.
  */

template<typename T>
class DwukierunkowaLista {
public:
    DwukierunkowaLista();
    ~DwukierunkowaLista();

    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    void clear();
    bool empty() const;
    size_t size() const;

    void display_forward() const;
    void display_reverse() const;

    void insertAt(size_t index, const T& value);
    void removeAt(size_t index);
    T& getAt(size_t index);

    DoublyListIterator<T> begin();
    DoublyListIterator<T> end();
    // dostêp do surowych wskaŸników (potrzebne do testów / iteracji wstecz)
    Node<T>* getHead() const;
    Node<T>* getTail() const;

private:
    Node<T>* head;
    Node<T>* tail;
   
    size_t sz;
};

#endif 
