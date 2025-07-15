#include "Array.hpp"
#include <iostream>

template <typename T>
Array<T>::Array()
{
    std::cout << GREY << "Array default constructor" << RESET << std::endl;
    return;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    std::cout << GREY << "Array param constructor" << RESET << std::endl;
    arr = new T[n]();
    return;
}

template <typename T>
Array<T>::Array(Array const &other)
{
    std::cout << GREY << "Array copy constructor" << RESET << std::endl;
    /*TODO*/;
    return;
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &other)
{
    std::cout << GREY << "Array copy assignment operator" << RESET << std::endl;
    if (this != &other)
    {
        /*TODO*/;
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    std::cout << GREY << "Array destructor" << RESET << std::endl;
    return;
}

/********************************************/
/********************************************/
/****** MEMBER FUNCTIONS ******/

template <typename T>
T *Array<T>::getArray() const
{
    return this->arr;
}

template <typename T>
unsigned int Array<T>::getSize() const
{
    return this->size;
}

/********************************************/
/********************************************/
/****** STREAM ******/

std::ostream &operator<<(std::ostream &o, const Array &infile)
{
    o << "";
    return o;
}

/********************************************/
/********************************************/
/****** PRIVATE ******/
