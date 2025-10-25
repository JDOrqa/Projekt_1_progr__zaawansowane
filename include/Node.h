/**
 * @file Node.h
 * @brief Deklaracja szablonowej struktury Node – pojedynczego wêz³a listy dwukierunkowej.
 * @date 2025-10-25
 * @author Szymon Kraj
 */

#ifndef NODE_H
#define NODE_H

 /**
  * @brief Szablonowa struktura wêz³a listy dwukierunkowej.
  * @tparam T Typ danych przechowywany w wêŸle.
  */
template<typename T>
struct Node {
    T data;
    Node<T>* prev;
    Node<T>* next;

    /**
     * @brief Konstruktor inicjalizuj¹cy dane w wêŸle.
     * @param value Wartoœæ przechowywana w wêŸle.
     */

    explicit Node(const T& value); // deklaracja konstruktora
};

#endif // NODE_H

