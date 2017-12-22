#include "dyn_arr.h"
#include <iostream>
using namespace std;

VectorDouble::VectorDouble()
{
	elements = new double[maxCount];
	count = 0;
}

VectorDouble::VectorDouble(int size)
{
	maxCount = size;
	elements = new double[maxCount];
	count = 0;
}

VectorDouble::VectorDouble(const VectorDouble&v)
{
	double *tempelements = new double[v.count];
	count = v.size();
	for (int i = 0; i < v.size(); i++)
		tempelements[i] = v.value_at(i);
	elements = tempelements;
}

VectorDouble::~VectorDouble()
{
	delete [] elements;
}

void VectorDouble ::operator = (const VectorDouble&v)
{
	double* temp = new double[v.count];
	for (int i = 0; i < v.size(); i++)
		temp[i] = v.value_at(i);

	count = v.size();
	elements = temp;
}

bool operator == (const VectorDouble& v1, const VectorDouble& v2)
{
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

void VectorDouble::push_back(double val)
{
	if (count == maxCount)
		expandCapacity();

	elements[count] = val;
	count++;
}

int VectorDouble::capacity() const
{
	return maxCount;
}

int VectorDouble::size() const
{
	return count;
}

void VectorDouble::reserve(int size)
{
	maxCount = size;
	double *newElements = new double[maxCount];
	for (int i = 0; i < count; i++)
		newElements[i] = elements[i];
	delete[] elements;
	elements = newElements;
}

void VectorDouble::resize(int size)
{
	if (size > 0)
	{
		maxCount = size;
		double *newElements = new double[maxCount];
		for (int i = 0; i < count; i++)
			newElements[i] = elements[i];
		delete[] elements;
		elements = newElements;
	}
}

double VectorDouble::value_at(int i) const
{
	if (i<0 || i>count)
	{
		return 0;
	}
	else
	{
		return elements[i];
	}
}

void VectorDouble::change_value_at(double newVal, int index)
{
	for (int i = 0; i < v.count; i++)
		outs << v.elements[i] << endl;
	return outs;
}

void VectorDouble::expandCapacity()
{
	maxCount = 2 * maxCount;
	double *newElements = new double[maxCount];
	for (int i = 0; i < count; i++)
		newElements[i] = elements[i];
	delete[] elements;
	elements = newElements;
}