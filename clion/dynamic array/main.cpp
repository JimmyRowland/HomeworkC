#include "vector.h"
#include <iostream>
using namespace std;
using namespace std;
void print(Vector *x){
    for(int i = 0;i<x->size();i++){
        cout<<x->value_at(i)<<' ';
    };
    cout<<endl;
    cout<<"size:"<<x->size()<<endl;
    cout<<"capacity:"<<x->capacity()<<endl;
}
int main()
{
    Vector vector(5);

    vector.push_back(12.5);
    vector.push_back(13.5);
    vector.push_back(14.5);
    vector.push_back(15.5);
    vector.push_back(16.5);

    cout << "VectorDouble vector" << endl;
    cout << "Capacity of the VectorDouble : " << vector.capacity() << endl;
    cout << "Size of the VectorDouble :" << vector.size() << endl;

    for (int index = 0; index < vector.size(); index++)
        cout << "value_at(" << index << ") :" << vector.value_at(index) << endl;

    cout << "Calling change_value_at() method for index, 2 replace with 99.5 : " << endl;
    vector.change_value_at(99.5, 2);
    cout << "Now, value at index, 2 : " << vector.value_at(2) << endl;
    cout << "Insert element into the vector" << endl;
    vector.push_back(17.5);

    cout << "Size of the VectorDouble after resize method calling : " << vector.size() << endl;
    cout << "VectorDouble temp " << endl;
    cout << "Copy constructor" << endl;

    Vector temp(5);
    temp.push_back(18.5);
    temp.push_back(19.5);
    temp.push_back(20.5);

    Vector copyConstructor(temp);

    print(&copyConstructor);
    cout << "Equality operater (==) checking on vector == temp" << endl;

    if (vector == temp)
        cout << "Both vectors are equal" << endl;
    else
        cout << "Vectors are not equal" << endl;

    cout << "Assignment operator (=) checking vector = temp" << endl;
    vector = temp;
    print(&vector);

    cout << "Checking resize() function " << endl;
    vector.resize(3);
    cout << "Size of the new vector : " << vector.capacity() << endl;
    print(&vector);

    cout << "Checking reserve() function " << endl;
    vector.reserve(40);
    cout << "Reserve new memory using reserve function" << endl;
    cout << "Size of new vector" << vector.capacity() << endl;
    print(&vector);

    system("pause");
    return 0;


}