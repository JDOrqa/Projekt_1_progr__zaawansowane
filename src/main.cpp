#include <iostream>
#include "DwukierunkowaLista.h"
#include "Iterator.h"

int main() {
    DwukierunkowaLista<int> list;

   /* std::cout << "Dodajemy na koniec: 1, 2, 3\n";
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    std::cout << "Lista (forward): ";
    list.display_forward();
    std::cout << "Lista (reverse): ";
    list.display_reverse();

    std::cout << "Dodajemy na poczatek: 0\n";
    list.push_front(0);
    std::cout << "Lista (forward): ";
    list.display_forward();

    std::cout << "Pop back\n";
    list.pop_back();
    std::cout << "Lista (forward): ";
    list.display_forward();

    std::cout << "Pop front\n";
    list.pop_front();
    std::cout << "Lista (forward): ";
    list.display_forward();

    std::cout << "Clear\n";
    list.clear();
    std::cout << "Size after clear: " << list.size() << "\n";
    std::cout << "Empty: " << (list.empty() ? "true" : "false") << "\n";*/

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    std::cout << " iterator (naprzod): ";
    for (auto it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    std::cout << "begin/end: ";
    for (int v : list) { // because we provided begin()/end() returning compatible iterators
        std::cout << v << " ";
    }
    std::cout << "\n";


    std::cout << "\n===== TEST insert/remove/get =====\n";
    list.clear();
    list.push_back(1);
    list.push_back(3);
    list.insertAt(1, 2);
    list.display_forward(); // [1 <-> 2 <-> 3]

    std::cout << "Element index 1: " << list.getAt(1) << "\n";
    list.removeAt(1);
    list.display_forward(); // [1 <-> 3]

    return 0;
}
