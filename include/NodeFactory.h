/**
 * @file NodeFactory.h
 * @brief Deklaracja klasy NodeFactory – wzorzec fabryki do tworzenia wêz³ów listy.
 * @date 2025-10-25
 */

#ifndef NODE_FACTORY_H
#define NODE_FACTORY_H

#include "Node.h"
 /**
  * @brief Szablonowa klasa fabryczna tworz¹ca i usuwaj¹ca wêz³y listy.
  * @tparam T Typ danych przechowywany w wêŸle.
  */
template<typename T>
class NodeFactory {
public:
    /**
    * @brief Tworzy nowy wêze³ z podan¹ wartoœci¹.
    * @param value Wartoœæ do zapisania w wêŸle.
    * @return WskaŸnik na nowy wêze³.
    */

    static Node<T>* createNode(const T& value);
    static void destroyNode(Node<T>* node);
    /**
    * @brief Usuwa wskazany wêze³ z pamiêci.
    * @param node WskaŸnik na wêze³ do usuniêcia.
    */
};

#endif // NODE_FACTORY_H

