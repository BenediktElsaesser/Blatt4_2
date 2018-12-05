//
// Created by Benedikt on 08.11.2018.
//

#include "Book.h"
#include <ctime>    //für today Funktion
#include <sstream>  //für today Funktion

std::string Book::getBuchtitel( ) const{
    return buchtitel;
}
std::string Book::getAutor() const{
    return autor;
}
std::string Book::getDatum() const{
    return datum;
}
bool Book::getStatus() const{
    return status;
}
void Book::dump() const{
    std::cout<<"---------------------------"<<std::endl;
    std::cout<<"Buchtitel: "<<buchtitel<<std::endl;
    std::cout<<"Autor: "<<autor<<std::endl;
    std::cout<<"Datum: "<<datum<<std::endl;
    std::cout<<"Status: "<<status<<std::endl;
    std::cout<<"---------------------------"<<std::endl;
}
std::string Book::today(){

    std::stringstream teststring;
    std::string ausgabe;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    teststring<<1900 + ltm->tm_year<<"-"<<1+ltm->tm_mon<<"-"<<ltm->tm_mday;   //YYYY-MM-DD
    ausgabe = teststring.str();
    return ausgabe;
}

Book::Book(std::string autor, std::string titel): autor(autor), buchtitel(titel),datum(today()), status(true){
}
Book::Book(std::string autor, std::string titel, std::string datum): autor(autor), buchtitel(titel), datum(datum), status(true) {
}
Book::Book(std::string autor, std::string titel, std::string datum, bool status): autor(autor), buchtitel(titel), datum(datum), status(status){
}
Book::Book() : autor(""), buchtitel(""), datum(today()), status(true){
}






//Aufgabe 2
std::string Book::getBuchtitelueberKopie(Book buchkopie)const{
    return buchkopie.buchtitel;
}
std::string Book::getBuchtitelueberReferenz(Book& buchreferenz)const{
    return buchreferenz.buchtitel;
}
std::string Book::getBuchtitelueberPointer(Book* buchpointer)const{
    return (*buchpointer).buchtitel;
}



//Aufgabe 3
//Destruktor
Book::~Book(){
    std::cout<<"Destruktor fuer: "<< getBuchtitel()<<std::endl;
}

//Kopierkonstruktor
Book::Book(const Book& zukopieren): buchtitel(zukopieren.buchtitel), autor(zukopieren.autor), datum(zukopieren.datum), status(zukopieren.status){
    std::cout<<"Kopierkonstruktor"<<std::endl;
}

bool operator==(Book& left, Book& right){
    if(left.buchtitel == right.buchtitel && left.autor == right.autor && left.datum == right.datum && left.status == right.status) {
        return true;
    }else {
        return false;
    }
}
std::ostream& operator<<(std::ostream& os, const Book& out){
    os << out.buchtitel << ", " << out.autor << ", " << out.datum << ", " << out.status;

    return os;
}