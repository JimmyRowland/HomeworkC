//
// Created by toor on 4/3/17.
//

#ifndef CALCULATOR_STACK_H
#define CALCULATOR_STACK_H
#include <stdexcept>
using namespace std;
namespace cs20a{
    template <class T>
    class Stack{
    public:
        Stack();
        explicit Stack(const Stack<T> &rhs);
        ~Stack();
        void push(const T &value);
        T pop();
        T top();
        bool isEmpty();
        void makeEmpty();
        bool isFull();
        T* getArray();
        int getUsed();

    private:
        T *array;
        int capacity;
        int used;
        void expendCapacity(int newCapacity);
        void expendCapacity();
        void copy(const T *oldArray);
    };

    template <class T>
    Stack<T>::Stack() {
        array= new T[50]();
        capacity=50;
        used=0;

    }


    template <class T>
    Stack<T>::Stack(const Stack<T> &rhs) {
        array=new T[rhs.capacity];
        for (int i = 0; i < rhs.used; i++) {
            array[i]=rhs.array[i];
        }
        capacity=rhs.capacity;
        used=rhs.used;

    }

    template <class T>
    Stack<T>::~Stack() {
        delete[] array;


    }

    template <class T>
    T Stack<T>::pop() {
        if(isEmpty()) {
            cout<<"used "<<used<<"array "<<array<<endl;
            throw std::out_of_range ("stack is empty, out of range");}

//        if(isEmpty()) cout<< "stack is empty, out of range"<<endl;
//        for (int i = 0; i < used; ++i) {
//            cout<<"["<<array[i]<<"]";
//
//        }
//        cout<<endl;
//        T *temp = array;
        cout<<"pop "<<"used "<<used<<"array "<<array<<" last "<<array[used-1]<<endl;
        return array[--used];
    }

    template <class T>
    int Stack<T>::getUsed(){
        return used;
    }

    template <class T>
    T Stack<T>::top() {
        return array[used-1];
    }

    template <class T>
    bool Stack<T>::isEmpty() {
        return used==0;
    }
    template <class T>
    T* Stack<T>::getArray() {
        return array;
    }
    template <class T>
    void Stack<T>::expendCapacity(int newCapacity) {
        if (newCapacity<capacity) return;
        T *temp = array;
        array = new T[newCapacity];
        for (int i = 0; i < used; i++) {
            array[i]=temp[i];
        }
        capacity=newCapacity;
        delete[] temp;

    }
    template <class T>
    void Stack<T>::expendCapacity() {
        int newCapacity=capacity*2;
//        capacity*=2;
        T *temp = array;
//
        array = new T[newCapacity];
//        T *temp = new T[newCapacity];
//


        for (int i = 0; i < used; i++) {

            array[i]=temp[i];
//            temp[i]= array[i];
        }
        capacity=newCapacity;

//        delete[] array;
        delete[] temp;
//        array = temp;

    }


    template <class T>
    void Stack<T>::copy(const T *oldArray) {

    }

    template <class T>
    void Stack<T>::push(const T &value) {
        used++;
        if(isFull())

            expendCapacity();

        array[used-1]=value;
//        for (int i = 0; i < used; ++i) {
//            cout<<"["<<array[i]<<"]";
//
//        }
//        cout<<endl;
        cout<<"value "<<value<<" used "<<used<<" array "<<array<<" last "<<array[used-1]<<endl;
    }
    template <class T>
    void Stack<T>::makeEmpty() {
        delete[] array;
        array=new T[50]();
        capacity=50;
        used=0;

    }

    template <class T>
    bool Stack<T>::isFull() {
        return capacity==used;
    }


}
#endif //CALCULATOR_STACK_H
