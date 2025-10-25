#ifndef NODE_FACTORY_H
#define NODE_FACTORY_H

#include "Node.h"

/**
 * @brief Prosta fabryka wêz³ów — wzorzec Factory.
 * Pozwala odseparowaæ tworzenie wêz³ów (przydatne np. do testów, mocków itp.)
 */


template<typename T>
class NodeFactory {
public:
   
    static Node<T>* createNode(const T& value) {
        return new Node<T>(value); 
    }

   
    static void destroyNode(Node<T>* node) {
        delete node; 
    }
};

#endif