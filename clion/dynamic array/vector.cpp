
#include <iostream>
#include "vector.h"
#include <stdexcept>

using namespace std;

Vector::Vector() {
    Vector(50);

}

Vector::~Vector() {
delete[] array;
}

Vector::Vector(int size) {
    max_count=size;
    array= new double[size]();

}

Vector::Vector(Vector* copyFrom) {
    count=copyFrom->count;
    max_count=copyFrom->max_count;
    double *tempelements = new double[max_count];
    for(int i=0;i<count;i++){
        tempelements[i]=copyFrom->array[i];
    }
    array=tempelements;
}

void Vector::push_back(double number) {
    if (count==max_count) resize(max_count*2);
    array[count]=number;
//    cout<<array[count];
    count++;

}

void Vector::copy(Vector* copyFrom,int capacity) {
    if(capacity) max_count=copyFrom->count*2;
    else max_count=capacity;
    double *newArray=new double [max_count];
    count=copyFrom->count;
    for(int i = 0;i<copyFrom->count;i++){
        newArray[i]=copyFrom->array[i];
    }
    delete[] array;
    array=newArray;

}

int Vector::capacity() const {
    return max_count;
}

int Vector::size() const {
    return count;
}

void Vector::reverse() {
    double temp;
    for(int i=0;i<count/2;i++){
        temp=array[i];
        array[i]=array[count-i-1];
    }
}

void Vector::resize(int size) {
    if(size<=count) cout<<'New capacity is less than the current size'<<endl;
    else{
        max_count= size*2;
        count=size;
        double *arrayNew=new double[max_count];
        for (int i=0;i<size;i++){
            arrayNew[i]=array[i];
        }
        delete[]array;
        array=arrayNew;
    }
}


double Vector::value_at(int i) const {
    if (i<count) return array[i];
    else throw std::out_of_range ("stack is empty, out of range");
}

void Vector::change_value_at(int index, double value) {
    if (index>=count) {resize(index*2);count=index+1;}
    else count++;
    array[index]=value;
    if(index>=count);

}

Vector::Vector(double copyFrom[],int size) {
    max_count=size*2;
    count=size;
    array=new double[max_count]();
    for(int i=0;i<size;i++){
        array[i]=copyFrom[i];
    }
}

bool operator==(const Vector &v1, const Vector &v2) {
    bool equal = true;
    if (v1.size() != v2.size())
        equal = false;
    else {
        for (int i = 0; i < v1.size(); i++)
            if (v1.value_at(i) != v2.value_at(i))
                equal = false;
    }
    return equal;
}


void Vector ::operator = (const Vector&v)
    {
        double* temp = new double[v.count];
        for (int i = 0; i < v.size(); i++)
            temp[i] = v.value_at(i);

        count = v.size();
        array = temp;
    }

void Vector::reserve(int size)
{
    max_count = size;
    double *newElements = new double[max_count];
    for (int i = 0; i < count; i++)
        newElements[i] = array[i];
    delete[] array;
    array = newElements;
}



