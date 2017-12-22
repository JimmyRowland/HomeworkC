#include "vector.h"
#include <iostream>
#include <exception>
using namespace std;

Vector::Vector()
{
    Vector(50);
}

Vector::Vector(int size)
{
    max_count = size;
    array = new double[max_count];
}

Vector::Vector(const Vector&v)
{
    copy(v.array,v.count,v.capacity());
}

Vector::~Vector()
{
    delete [] array;
}

void Vector ::operator = (const Vector&v)

{
    copy(v.array,v.count,v.capacity());

}

bool operator == (const Vector& vlhs, const Vector& vrhs)
{
    if (vlhs.size() != vrhs.size())
        return false;
    else {
        for (int i = 0; i < vlhs.size(); i++)
            if (vlhs.value_at(i) != vrhs.value_at(i))
                return false;
    }
    return true;
}

void Vector::push_back(double val)
{
    if (count == max_count)
        resize(max_count*2);

    array[count] = val;
    count++;
}

int Vector::capacity() const
{
    return max_count;
}

int Vector::size() const
{
    return count;
}

void Vector::reserve(int size)
{
    max_count = size;
    double *arrayNew = new double[max_count];
    for (int i = 0; i < count; i++)
        arrayNew[i] = array[i];
    delete[] array;
    array = arrayNew;
}

void Vector::resize(int size)
{
    if (size > max_count)
    {
        max_count = size;
        double *newElements = new double[max_count];
        for (int i = 0; i < count; i++)
            newElements[i] = array[i];
        delete[] array;
        array = newElements;
    }
}

double Vector::value_at(int i) const
{
    if (i<0 || i>count) throw out_of_range("out of range");
    else return array[i];

}

void Vector::change_value_at(double value, int index)
{
    if(index>max_count) resize(index*2);
    array[index]=value;

}

void Vector::copy(double *v,int size, int capacity) {
    if((count+max_count)!=0) delete[] array;
    max_count=capacity;
    double* temp = new double[max_count];
    for (int i = 0; i < size; i++)
        temp[i] = v[i];
    count = size;
    array = temp;
}

