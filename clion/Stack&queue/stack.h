//
// astack - array-based stack class
// CS-20A: Data Structures With C++
// Professor Scott E Robertson
// 3/24/2017
//
#pragma once
#include <iostream>
#include <string>
using namespace std;
namespace cs20a
{
	template<class T>
	class stack
	{
	public:
		stack();
		explicit stack(size_t capacity);
		stack(const stack<T> &rhs);
		~stack();

		stack<T>& operator =(const stack<T> & rhs);

		bool operator==(stack<T> & a) const;
		bool operator!=(stack<T> & a) const;

		void push(const T& val);
		T pop();
		T peek() const;

		void clear();

		bool empty() const;
		bool full() const;
		size_t size() const;

		void print();

		//*** Implement these methods only. ***

		bool isConsecutive(const T &data) const;
		void reverse();

		//*** *** *** *** *** *** *** *** ***

	private:
		T *elements;
		size_t _top;
		size_t _capacity;

		void makeEmpty();
		void init(size_t capacity = 2);
		void copy(const stack<T>& rhs);
		void resize(size_t newCapacity);

	};

	template<class T>
	stack<T>::stack() {
		init();
	}

	template<class T>
	stack<T>::stack(size_t capacity) {
		init(capacity);
	}

	template<class T>
	stack<T>::stack(const stack<T> &rhs) {
		init(rhs._capacity);
		copy(rhs);
	}

	template<class T>
	stack<T>::~stack()
	{
		makeEmpty();
	}

	template<class T>
	stack<T>& stack<T>::operator=(const stack<T>& rhs) {
		if (this != &rhs) {
			clear();
			copy(rhs);
		}
		return *this;
	}

	template<class T>
	bool stack<T>::operator==(stack<T>& rhs) const {
		if (_top != rhs._top)
			return false;

		for (size_t i = 0; i < _top; i++)
			if (elements[i] != rhs.elements[i])
				return false;

		return true;
	}

	template<class T>
	bool stack<T>::operator!=(stack<T>& rhs) const {
		return !(this == &rhs);
	}

	template<class T>
	bool stack<T>::empty() const {
		return (_top == 0);
	}

	template<class T>
	bool stack<T>::full() const
	{
		return (_top == _capacity);
	}

	template<class T>
	void stack<T>::clear() {
		makeEmpty();
		init();
	}

	template<class T>
	size_t stack<T>::size() const {
		return _top;
	}

	template<class T>
	void stack<T>::makeEmpty() {
		delete[] elements;
	}

	template<class T>
	void stack<T>::init(size_t capacity) {
		_top = 0;
		_capacity = capacity;
		elements = new T[capacity];
	}

	template<class T>
	void stack<T>::copy(const stack<T>& rhs) {
		for (size_t i = 0; i < rhs._top; i++)
			push(rhs.elements[i]);
	}

	template<class T>
	void stack<T>::resize(size_t minCapacity) {
		if (minCapacity < _top)
			return;

		if (minCapacity >= 0)
		{
			size_t limit = 1;
			while (limit <= minCapacity)
				limit <<= 1;

			T *tarray = new T[limit];

			for (size_t i = 0; i < _top; i++)
				tarray[i] = elements[i];

			delete[] elements;

			elements = tarray;
			_capacity = limit;
		}
	}

	template<class T>
	void stack<T>::push(const T& val) {
		if (full())
			resize(_top + 1);
		elements[_top++] = val;
	}

	template<class T>
	T stack<T>::pop() {
		return elements[--_top];
	}

	template<class T>
	T stack<T>::peek() const {
		return elements[_top - 1];
	}

	template<class T>
	void stack<T>::print()
	{
		std::cout << "top=[" << _top << "]" << "  " << endl;

		if (empty())
		{
			std::cout << "Empty stack." << endl;
			return;
		}

		std::cout << " --> ";
		for (size_t i = 0; i < _top; i++) {
			std::cout << "[" << i << "]:" << elements[i];
			if (i < (_top - 1))
				cout << " --> ";
		}
		cout << endl;
	}

	//*** Implement isConsecutive() and reverse() here. ***
	template<class T>
	bool stack<T>::isConsecutive( const T & data ) const{
		size_t p =_top-2;
//		cout<<(p+1>0)<<p<<endl;

		for (size_t i = _top-2; i+1 >0 ; i--) {
//			cout << elements[i]<<" "<<elements[i+1]<<endl;
			if(elements[i]==data && elements[i]==elements[i+1]) return true;
		}
		return false;
	}
	template<class T>
	void stack<T>::reverse(){

		T* temp= new T[_capacity];
		size_t tail=_top;
		for (size_t i = 0; i < tail; ++i) {
//			cout<<i<<" "<<peek()<<endl;
			temp[i]=pop();
//			cout<<i<<" temp "<<temp[i]<<endl;
		}
		delete[] elements;
		elements=temp;
		_top=tail;
//		cout<<" elements "<<elements[0]<<endl;

	}
}