/**
 * @file Node.h
 * @brief Deklaracja szablonowej struktury Node � pojedynczego w�z�a listy dwukierunkowej.
 * @date 2025-10-25
 * @author Szymon Kraj
 */

#ifndef NODE_H
#define NODE_H

 /**
  * @brief Szablonowa struktura w�z�a listy dwukierunkowej.
  * @tparam T Typ danych przechowywany w w�le.
  */
template<typename T>
struct Node {
    T data;
    Node<T>* prev;
    Node<T>* next;

    /**
     * @brief Konstruktor inicjalizuj�cy dane w w�le.
     * @param value Warto�� przechowywana w w�le.
     */

    explicit Node(const T& value); // deklaracja konstruktora
};

#endif // NODE_H

