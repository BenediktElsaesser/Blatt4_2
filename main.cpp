#include <iostream>
#include "ArrayList.h"
#include "Book.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    hfu::ArrayList <int> C = hfu::ArrayList<int>(5);
    C.set(0,1);
    C.set(1,1);
    C.set(2,3);
    C.set(3,3);
    C.set(4,4);
    hfu::ArrayList <float> D = hfu::ArrayList<float>(5);
    D.set(0,1.1);
    D.set(1,1.1);
    D.set(2,3.1);
    D.set(3,3.1);
    D.set(4,4.2);
    hfu::ArrayList<Book> E = hfu::ArrayList<Book>(3);
    Book book1 = Book("Benedikt", "Aufgabe 4");
    Book book2 = Book("Franz", "Aufgabe 2");
    Book book3 = Book("Hans", "OOP");
    E.set(0,book1);
    E.set(1,book2);
    E.set(2,book3);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Liste int: " << C << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Liste float: " << D << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Liste Book: " << E << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Kopieerg: " << book1.getBuchtitelueberKopie(book2) << std::endl;

    std::cout << "Referenzerg: " << book1.getBuchtitelueberReferenz(book2) << std::endl;

    std::cout << "Pointererg: " << book1.getBuchtitelueberPointer(&book2) << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    return 0;
}