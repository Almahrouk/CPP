#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T> 
class Array
{
    private:
        T *_array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &src);
        
        // template <typename T> 
        Array<T> &operator=(const Array<T> &src);

        T &operator[](unsigned int index);
        const T &operator[](unsigned int index) const;
        unsigned int size() const;

        // class OutOfRangeException : public std::exception
        // {
        //     public:
        //         virtual const char *what() const throw();
        // };
        ~Array();
};

template <typename T> 
Array<T>::Array()
{
    this->_array = NULL;
    this->_size = 0;
}

template <typename T> 
Array<T>::Array(unsigned int n)
{
    this->_array = new T[n];
    this->_size = n;
    
    // for (unsigned int i = 0; i < n; i++)
    //     this->array[i] = 0;
}

template <typename T> 
Array<T>::Array(const Array &src)
{
    // this->_array = new T[src.n];
    // this->_size = src.n;
    // for (unsigned int i = 0; i < this->size(); i++)
    // {
    //     this->array[i] = src.array[i];
    // }
    this->_array = NULL;
    this->_size = 0;
    *this = src;
}

template <typename T> 
Array<T> &Array<T>::operator=(const Array<T> &src)
{
    if (this != &src)
    {
        T *temp = new T[src._size];
        for (unsigned int i = 0; i < _size; i++)
        temp[i] = src._array[i];
        delete[] _array;
        _array = temp;
        _size = src._size;
    }
    return *this;
}

template <typename T> 
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("Index out of range");
    return _array[index];
}

template <typename T> 
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::out_of_range("Index out of range");
    return _array[index];
}

template <typename T> 
unsigned int Array<T>::size() const
{
    return _size;
}

template <typename T> 
Array<T>::~Array()
{
    delete[] _array;
}

#endif