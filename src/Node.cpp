/**
 * @file Node.cpp
 * @brief Implementacja konstruktora szablonu Node.
 * @date 2025-10-25
 */

#include "Node.h"
#include <string>

// Definicja konstruktora
template<typename T>
Node<T>::Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}

// Jawne instancjonowanie dla kilku typów (wa¿ne dla template!)
template struct Node<int>;
template struct Node<double>;
template struct Node<std::string>;
