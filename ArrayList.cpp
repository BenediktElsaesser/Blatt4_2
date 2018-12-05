//
// Created by Benedikt on 10.11.2018.
//

//#include "ArrayList.h"
#include<iostream>

namespace hfu{
    <T>ArrayList::ArrayList<T>(int size){
        array = new  T[size];
        ArrayList::size = size;
    }
    ArrayList::~ArrayList() {
        delete[] array;
        std::cout<<"Destruktor wurde aufgerufen"<<std::endl;
    }
    ArrayList::ArrayList(const ArrayList& toCopy){
        size = toCopy.size;
        array = new T[size];
        for(int i=0;i<size;i++)
            array[i] = toCopy.get(i);

    }
    double ArrayList::get(int i)const{
        try{
            if(i<0 || i>size-1)
                throw "i ist ausser des Array Bereichs";
            else{
                return array[i];
            }
        }
        catch(const char* ex)
        {
            std::cout<<"Lesefehler: "<<ex<<"  "<<i<<std::endl;
        }
    }

    void ArrayList::set(int i, T number){
        try{
            if(i<0 || i>size-1)
                throw "i ist ausser des Array Bereichs";
            array[i] = number;
        }
        catch(const char* ex)
        {
            std::cout<<"Schreibfehler: "<<ex<<"  "<<i<<std::endl;
        }
    }

    ArrayList& ArrayList::operator=(ArrayList& other){
        if (this == &other)
            return *this;
        delete[] array;
        size = other.size;
        array = new T[size];
        for(int i = 0; i < size; i++){
            array[i] = other.get(i);
        }
    }

    template <class T> std::ostream& ArrayList<T>operator<<(std::ostream& os, const ArrayList<T>ArrayList& liste){
        for(int i = 0; i<liste.size; i++){
            os << liste[i] << ", ";
        }
        return os;
    }

    double ArrayList::operator[](const int& i) const{
        return (this->array[i]);
    }

    ArrayList::ArrayList(T *array) : array(array) {}
}