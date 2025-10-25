#ifndef NODE_H
#define NODE_H

#include <memory>
/**
 * @brief Prosty w�ze� listy dwukierunkowej (template).
 * Doxygen-friendly komentarze.
 */

// Szablon struktury w�z�a dla listy dwukierunkowej
template<typename T>
struct Node {
    T data;        
    Node<T>* prev;  
    Node<T>* next;  

   
                                   //chyba od t�d do pliku Node.cpp tak samo pewnie z factory
    explicit Node(const T& value) : data(value), prev(nullptr), next(nullptr) {} // to do innegi pliku 
   
};

#endif // NODE_H
