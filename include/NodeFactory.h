/**
 * @file NodeFactory.h
 * @brief Deklaracja klasy NodeFactory � wzorzec fabryki do tworzenia w�z��w listy.
 * @date 2025-10-25
 */

#ifndef NODE_FACTORY_H
#define NODE_FACTORY_H

#include "Node.h"
 /**
  * @brief Szablonowa klasa fabryczna tworz�ca i usuwaj�ca w�z�y listy.
  * @tparam T Typ danych przechowywany w w�le.
  */
template<typename T>
class NodeFactory {
public:
    /**
    * @brief Tworzy nowy w�ze� z podan� warto�ci�.
    * @param value Warto�� do zapisania w w�le.
    * @return Wska�nik na nowy w�ze�.
    */

    static Node<T>* createNode(const T& value);
    static void destroyNode(Node<T>* node);
    /**
    * @brief Usuwa wskazany w�ze� z pami�ci.
    * @param node Wska�nik na w�ze� do usuni�cia.
    */
};

#endif // NODE_FACTORY_H

