#include "DynamicIntArray.h"

namespace cs20a {

	// ***  Code goes here ***
	DynamicIntArray::DynamicIntArray() {
		elements = new int[1];
		elements[0] = 0;
		capacity = 1;
		used = 0;
	}
	DynamicIntArray::DynamicIntArray(int size) {
		elements = new int[size];
		
		for (int i = 0; i < size; i++) {
			elements[i] = 0;
		}
		capacity = size;
	
		used = 0;
		
	}
	DynamicIntArray::DynamicIntArray(const DynamicIntArray& rhs) {
		capacity = rhs.capacity;
		used = rhs.used;
		elements = new int[capacity];
		for (int i=0; i < rhs.used; i++) {
			elements[i] = rhs.elements[i];
		}
	}

	DynamicIntArray::~DynamicIntArray() {
		printf("An array is deleted");
		delete[] elements;
		
	}
	DynamicIntArray & DynamicIntArray::operator=(const DynamicIntArray & rhs)
	{
		capacity = rhs.capacity;		
		used = rhs.used;
		delete[] elements;
		elements = new int[capacity];
		
		for (int i=0; i < rhs.used; i++) {
			elements[i] = rhs.elements[i];
		}
		return *this;
	}
	bool DynamicIntArray::isEmpty() const {
		if (used == 0) {
			return true;
		}
		return false;
	}
	int DynamicIntArray::getUsed() const {
		return used;
	};

	int DynamicIntArray::getCapacity() const {
		return capacity;
	};

	void DynamicIntArray::add(int element) {
		if (getCapacity() == getUsed()) {
			expandCapacity();
		}
		elements[used] = element;
		used += 1;
	};
	void DynamicIntArray::insert(int i, int element) {
		while (i+1>=getCapacity()) {
			expandCapacity();
		}
		for (int x = used; x > i; x--) {
			elements[x] = elements[x - 1];

		}
		elements[i] = element;
		used += 1;
	};
	int DynamicIntArray::remove(int i) {
		if (used == 0) {
			return 0;
		}
		if (i >= used) {
			throw std::logic_error("Out of index");
		}
		int temp = elements[i];
		for (int x = i; x < used - 1; x++) {
			elements[x] = elements[x + 1];
		}
		elements[used-1] = 0;
		used -= 1;
		return temp;
	};

	void DynamicIntArray::clear(){
		for (int i = 0; i < used; i++) {
			elements[i] = 0;
		}
		used = 0;
	};

	int &DynamicIntArray::operator [](int i) {
		if ((i + 1) > capacity) {
			throw std::logic_error("Out of index");
		}
		return elements[i];
	}
	void DynamicIntArray::expandCapacity()
	{
		int*temp = elements;
		elements = new int[capacity * 2];
		for (int i = 0; i < capacity; i++) {
			elements[i] = temp[i];

		}
		for (int i = capacity; i < capacity * 2; i++) {
			elements[i] = 0;
		}
		capacity *= 2;
		delete[] temp;

	}
	;

	std::ostream & operator<<(std::ostream & outs, const DynamicIntArray & d)
	{
		std::cout << '[';
		for (int i = 0; i < d.used-1; i++) {
			std::cout << d.elements[i] << ", ";
		}
		if (d.used != 0)
			std::cout << d.elements[d.used - 1];
		std::cout << ']' << std::endl;
		return outs;
	}

	bool operator==(const DynamicIntArray & d1, const DynamicIntArray & d2)
	{
		if (d1.used != d2.used ||d1.capacity !=d2.capacity) {
			return false;
		}
		for (int i = 0; i < d1.used; i++) {
			if (d1.elements[i] != d2.elements[i]) {
				return false;
			}

		}
		return true;
	}

}