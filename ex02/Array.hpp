#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

#ifndef COLOR
#define COLOR
#define GREY "\033[0;30m"
#define RESET "\033[0m"
#endif

template <typename T>
class Array
{
public:
    Array<T>();
    Array<T>(unsigned int);
    Array(Array const &other);
    Array &operator=(Array const &other);
    ~Array();

    unsigned int size() const;

    T &operator[](unsigned int i);
    const T &operator[](unsigned int i) const;

    class OutOfBoundsException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Index is out of bounds";
        }
    };

private:
    T *arr;
    unsigned int _size;
};

// std::ostream &operator<<(std::ostream &o, Array const &infile);

#include "Array.tpp"

#endif
