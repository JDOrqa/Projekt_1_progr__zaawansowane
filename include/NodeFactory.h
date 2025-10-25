#ifndef NODE_FACTORY_H
#define NODE_FACTORY_H

#include "Node.h"

/**
 * @brief Prosta fabryka w�z��w � wzorzec Factory.
 * Pozwala odseparowa� tworzenie w�z��w (przydatne np. do test�w, mock�w itp.)
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