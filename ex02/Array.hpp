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

    T *getArray() const;
    unsigned int getSize() const;

private:
    T *arr;
    unsigned int size;
};

std::ostream &operator<<(std::ostream &o, Array const &infile);

#endif
