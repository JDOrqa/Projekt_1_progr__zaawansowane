#ifndef NODE_H
#define NODE_H

#include <memory>


template<typename T>
struct Node {
    T data;
    Node<T>* prev;
    Node<T>* next;

    explicit Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

#endif // NODE_H
