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
        Stack(const Stack<T> &rhs);
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
        array= new T[5]();
        capacity=5;
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
        if(isEmpty()) throw std::out_of_range ("stack is empty, out of range");
//        for (int i = 0; i < used; ++i) {
//            cout<<"["<<array[i]<<"]";
//
//        }
//        cout<<endl;
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
        T *temp = array;
        array = new T[newCapacity];
        for (int i = 0; i < used; i++) {
            array[i]=temp[i];
        }
        capacity=newCapacity;
        delete[] temp;

    }


    template <class T>
    void Stack<T>::copy(const T *oldArray) {

    }

    template <class T>
    void Stack<T>::push(const T &value) {
        used++;
        if(isFull()) expendCapacity();
        array[used-1]=value;
//        for (int i = 0; i < used; ++i) {
//            cout<<"["<<array[i]<<"]";
//
//        }
//        cout<<endl;
    }
    template <class T>
    void Stack<T>::makeEmpty() {
        delete[] array;
        array=new T[6]();
        used=0;

    }

    template <class T>
    bool Stack<T>::isFull() {
        return capacity==used;
    }


}
#endif //CALCULATOR_STACK_H