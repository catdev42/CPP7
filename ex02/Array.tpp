#include "Array.hpp"

template <typename T>
Array<T>::Array() : arr(new T[0]()), _size(0)
{
    std::cout << GREY << "Array default constructor" << RESET << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]()), _size(n)
{
    std::cout << GREY << "Array parametrized constructor" << RESET << std::endl;
}

template <typename T>
Array<T>::Array(Array const &other) : arr(new T[other._size]()), _size(other.size())
{
    std::cout << GREY << "Array copy constructor" << RESET << std::endl;
    for (unsigned int i = 0; i < _size; i++)
        arr[i] = other.arr[i];
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &other)
{
    std::cout << GREY << "Array copy assignment operator" << RESET << std::endl;
    if (&other != this)
    {
        delete[] arr;
        arr = new T[other._size]();
        for (unsigned int i = 0; i < other._size; i++)
            arr[i] = other.arr[i];
    }

    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] arr;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= _size)
        throw OutOfBoundsException();
    return arr[i];
}

template <typename T>
T const &Array<T>::operator[](unsigned int i) const
{
    if (i >= _size)
        throw OutOfBoundsException();
    return arr[i];
    // return const arr[i]; // try if this makes an error
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

// if (this != &other)
// {
//     delete[] arr;
//     _size = other._size;
//     arr = new T[_size];
//     for (unsigned int i = 0; i < _size; i++)
//         arr[i] = other.arr[i];
// }

// std::ostream &operator<<(std::ostream &o, const Array &infile)
// {
//     o << "";
//     return o;
// }
