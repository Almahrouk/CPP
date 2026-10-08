#include <iostream>

template <typename T> 
void iter(T *arr, const size_t size, void (*function)(T&))
{
    for(size_t i = 0; i < size; i++)
        function(arr[i]);
}

template <typename T> 
void iter(const T *arr, const size_t size, void (*function)(const T&))
{
    for(size_t i = 0; i < size; i++)
        function(arr[i]);
}