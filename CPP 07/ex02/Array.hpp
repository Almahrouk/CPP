#include <iostream>

template <typename T> 
class Array
{
    private:
        T array;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &src);
        Array &opeartor=(const Array &src);

        T &operator[](int index);
        unsigned int size() const;
};

Array::Array()
{
    this->array = 0;
}

Array::Array(unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
        this->array[i] = 0;
}

Array::Array(const Array &src)
{
    for (unsigned int i = 0; i < this->size(); i++)
    {
        this->array[i] = src.array[i];
    }
}

unsigned int size() const
{
    unsigned int n = 0;
    while(this->array[i])
    {
        n++;
    }
    return n;
}
