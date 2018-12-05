//
// Created by Benedikt on 08.11.2018.
//

#ifndef BLATT2_BOOK_H
#define BLATT2_BOOK_H

#include<iostream>



class Book {
private:
    std::string buchtitel;
    std::string autor;
    std::string datum;
    bool status;
public:
    std::string getBuchtitel( ) const;
    std::string getAutor() const;
    std::string getDatum() const;
    bool getStatus() const;
    std::string today();
    void dump() const;
    Book(std::string autor, std::string titel);
    Book(std::string autor, std::string titel, std::string datum);
    Book(std::string autor, std::string titel, std::string datum, bool status);



    //Aufgabe 2
    std::string getBuchtitelueberKopie(Book buchkopie)const;
    std::string getBuchtitelueberReferenz(Book& buchreferenz)const;
    std::string getBuchtitelueberPointer(Book* buchpointer)const;


    //Aufgabe 3
    ~Book();
    Book(const Book& zukopieren);

    //Blatt 4
    friend bool operator==(Book&, Book&); // da man Book sonst nicht vergleichen kann
    Book();
    friend std::ostream& operator<<(std::ostream& os, const Book& out);


};

#endif //BLATT2_BOOK_H
