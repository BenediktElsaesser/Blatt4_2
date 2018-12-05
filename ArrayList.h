//
// Created by Benedikt on 10.11.2018.
//

#ifndef BLATT_2_6_ARRAYLIST_H
#define BLATT_2_6_ARRAYLIST_H

#include <iostream>


namespace hfu{
        template <class T>
        class ArrayList {
            private:
            int size;
            T *array;
            public:
            ArrayList(int size){
                    array = new  T[size];
                    ArrayList::size = size;
            };
            T get(int i)const{
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
            };
            void set(int i, T number){
                    try{
                            if(i<0 || i>size-1)
                                    throw "i ist ausser des Array Bereichs";
                            array[i] = number;
                    }
                    catch(const char* ex)
                    {
                            std::cout<<"Schreibfehler: "<<ex<<"  "<<i<<std::endl;
                    }
            };
            ~ArrayList(){
                    delete[] array;
                    std::cout<<"Destruktor wurde aufgerufen"<<std::endl;
            };
            ArrayList(const ArrayList<T>& toCopy){
                    size = toCopy.size;
                    array = new T[size];
                    for(int i=0;i<size;i++)
                            array[i] = toCopy.get(i);

            };

            ArrayList(T *array) : array(array){

            };

            ArrayList& operator=(ArrayList<T>& other){
                    if (this == &other)
                            return *this;
                    delete[] array;
                    size = other.size;
                    array = new T[size];
                    for(int i = 0; i < size; i++){
                            array[i] = other.get(i);
                    }
            };


            friend std::ostream& operator<<(std::ostream& os, const ArrayList<T>& liste){
                    for(int i = 0; i<liste.size; i++){
                            os << liste[i] << ", ";
                    }
                    return os;
            }
            T operator[](const int& i) const{
                    return (this->array[i]);
            };
        };

}

#endif //BLATT_2_6_ARRAYLIST_H
