//
// cqueue - circular queue (array-based)
// CS-20A: Data Structures With C++
// Professor Scott E Robertson
// 3/24/2017
//
#pragma once
#include <string>
using namespace std;
namespace cs20a
{
	template<class T>
	class queue {
	public:
		queue();
		explicit queue(size_t capacity);
		queue(const queue<T> &rhs);
		~queue();

		queue<T>& operator =(const queue<T> & rhs);

		bool operator==(queue<T> & rhs) const;
		bool operator!=(queue<T> & rhs) const;

		void enqueue(const T& val);
		T dequeue();
		T peek() const;

		void clear();

		bool empty() const;
		bool full() const;
		size_t size() const;

		void print();

		//*** Implement these methods only. ***

		size_t count(const T &data) const;
		bool isDecreasing() const;

		//*** *** *** *** *** *** *** *** ***

	private:
		T* elements;
		size_t _front, _size, _capacity;

		void makeEmpty();
		void init(size_t capacity = 2);
		void copy(const queue<T>& rhs);
		void resize(size_t newCapacity);

	};

	template<class T>
	queue<T>::queue() {
		init();
	}

	template<class T>
	queue<T>::queue(size_t capacity) {
		init(capacity);
	}

	template<class T>
	queue<T>::~queue() {
		makeEmpty();
	}

	template<class T>
	queue<T>::queue(const queue<T> &rhs) {
		init(rhs._capacity);
		copy(rhs);
	}

	template<class T>
	queue<T>& queue<T>::operator=(const queue<T>& rhs) {
		if (this != &rhs) {
			clear();
			copy(rhs);
		}
		return *this;
	}

	template<class T>
	bool queue<T>::operator==(queue<T>& rhs) const {
		if (_size != rhs._size)
			return false;

		size_t size = 0;
		size_t i = _front;
		size_t j = rhs._front;

		while (size++ < _size) {
			if (elements[i] != rhs.elements[j])
				return false;

			i = ((i + 1) % _capacity);
			j = ((j + 1) % rhs._capacity);
		}

		return true;
	}

	template<class T>
	bool queue<T>::operator!=(queue<T>& rhs) const {
		return !(this == &rhs);
	}

	template<class T>
	void queue<T>::clear() {
		makeEmpty();
		init();
	}

	template<class T>
	bool queue<T>::empty() const {
		return _size == 0;
	}

	template<class T>
	bool queue<T>::full() const {
		return _size == _capacity;
	}

	template<class T>
	size_t queue<T>::size() const {
		return _size;
	}

	template<class T>
	void queue<T>::makeEmpty() {
		delete[] elements;
	}

	template<class T>
	void queue<T>::init(size_t capacity) {
		_front = _size = 0;
		_capacity = capacity;
		elements = new T[_capacity];
	}

	template<class T>
	void queue<T>::copy(const queue<T>& rhs) {
		size_t i = rhs._front;
		while (_size < rhs._size) {
			enqueue(rhs.elements[i]);
			i = ((i + 1) % rhs._capacity);
		}
	}

	template<class T>
	void queue<T>::resize(size_t minCapacity) {
		if (minCapacity < _size)
			return;

		if (minCapacity >= 0)
		{
			size_t limit = 1;
			while (limit <= minCapacity)
				limit <<= 1;

			T *tarray = new T[limit];

			for (size_t i = 0; i < _size; i++)
				tarray[i] = elements[(i + _front) % _capacity];

			delete[] elements;

			elements = tarray;
			_capacity = limit;
		}
	}
	template<class T>
	void queue<T>::enqueue(const T& val) {
		if (full())
			resize(_size + 1);

		elements[(_front + _size) % _capacity] = val;
		_size++;
	}

	template<class T>
	T queue<T>::dequeue() {
		T  item = elements[_front];
		_front = (_front + 1) % _capacity;
		_size--;

		return item;
	}

	template<class T>
	T queue<T>::peek() const {
		return elements[_front];
	}

	template<class T>
	void queue<T>::print() {
		cout << "front=[" << _front << "]" << "  ";
		cout << "rear=[" << (_front + _size) % _capacity << "]" << endl;

		if (empty())
		{
			cout << "Empty queue." << endl;
			return;
		}

		size_t i = _front;
		size_t rear = (_front + _size) % _capacity;

		std::cout << " --> ";
		do
		{
			std::cout << "[" << i << "]:" << elements[i];
			i = (i + 1) % _capacity;
			if (i != rear)
				cout << " --> ";
		} while (i != rear);

		std::cout << endl;
	}

	//*** Implement count() and isDecreasing() here. ***
	template<class T>
	bool queue<T>::isDecreasing() const{
		if(size()<2) return true;
		cout<<"test"<<endl;
		for (size_t i = 0; i <size()-1; i++) {
			cout<<(i+1+_front)%_capacity<<" : "<<elements[(i+1+_front)%_capacity]<<" vvvvv "<<(i+_front)%_capacity<<" : "<<elements[(i+_front)%_capacity]<<endl;
			if(elements[(i+1+_front)%_capacity]>elements[(i+_front)%_capacity]) return false;
		}
		return true;

	}
	template<class T>
	size_t queue<T>::count(const T & data) const{
		size_t counter=0;
		for (size_t i = 0; i < size(); i++) {
			cout<<i<<":"<<elements[(_front+i)%_capacity]<<endl;
			if (elements[(_front+i)%_capacity]== data) counter++;

		}
		return counter;
	}
}