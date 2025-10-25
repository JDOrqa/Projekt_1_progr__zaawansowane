
/**
 * @file NodeFactory.cpp
 * @brief Implementacja metod fabryki wêz³ów listy.
 * @date 2025-10-25
 */

#include "NodeFactory.h"
#include <string>
template<typename T>
Node<T>* NodeFactory<T>::createNode(const T& value) {
    return new Node<T>(value);
}

template<typename T>
void NodeFactory<T>::destroyNode(Node<T>* node) {
    delete node;
}

// Jawne instancjonowanie
template class NodeFactory<int>;
template class NodeFactory<double>;
template class NodeFactory<std::string>;
