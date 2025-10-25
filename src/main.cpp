
/**
 * @file main.cpp
 * @brief Program testowy listy dwukierunkowej DoublyLinkedList.
 * @date 2025-10-25
 */

#include <iostream>
#include "DwukierunkowaLista.h"
#include <string>

 /**
  * @example main.cpp
  * Ten przyk³ad demonstruje u¿ycie listy dwukierunkowej:
  * dodawanie, usuwanie, iterowanie i czyszczenie elementów.
  */

int main() {
    std::cout << " TEST 1: push_front / push_back \n";
    DwukierunkowaLista<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(0);

    std::cout << "Lista (forward): ";
    list.display_forward();   // [0 <-> 1 <-> 2 <-> 3]
    std::cout << "Lista (reverse): ";
    list.display_reverse();   // [3 <-> 2 <-> 1 <-> 0]
    std::cout << "Rozmiar: " << list.size() << "\n\n";

    std::cout << " TEST 2: pop_front / pop_back \n";
    list.pop_front(); // usuwa 0
    list.pop_back();  // usuwa 3
    list.display_forward();   // [1 <-> 2]
    std::cout << "Rozmiar po usunieciu: " << list.size() << "\n\n";

    std::cout << "TEST 3: insertAt / removeAt / getAt \n";
    list.clear();
    list.push_back(10);
    list.push_back(30);
    list.insertAt(1, 20); // wstawiamy 20 miêdzy 10 a 30
    list.display_forward(); // [10 <-> 20 <-> 30]

    std::cout << "Element index 0: " << list.getAt(0) << "\n";
    std::cout << "Element index 1: " << list.getAt(1) << "\n";
    std::cout << "Element index 2: " << list.getAt(2) << "\n";

    list.removeAt(1); // usuñ 20
    list.display_forward();   // [10 <-> 30]
    std::cout << "Rozmiar po removeAt: " << list.size() << "\n\n";

    std::cout << " TEST 4: iteratory (forward i backward) \n";
    list.clear();
    list.push_back(5);
    list.push_back(10);
    list.push_back(15);

    std::cout << "Iteracja do przodu: ";
    for (auto it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    std::cout << "Iteracja z uzyciem range-for: ";
    for (int x : list) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::cout << "Iteracja wstecz (od konca): ";
    Node<int>* cur = list.getTail();
    while (cur) {
        std::cout << cur->data << " ";
        cur = cur->prev;
    }



    std::cout << "\n\n";

    std::cout << " TEST 5: clear / empty \n";
    list.clear();
    std::cout << "Lista po clear: ";
    list.display_forward();
    std::cout << "Pusta? " << (list.empty() ? "TAK" : "NIE") << "\n";
    std::cout << "Rozmiar: " << list.size() << "\n";

    std::cout << "\nWszystkie testy wykonane poprawnie \n";
    return 0;
}
