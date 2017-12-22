#ifndef DYN_ARR_H
#define DYN_ARR_H


class VectorDouble
{
public:
	VectorDouble();
	VectorDouble(int size);
	VectorDouble(const VectorDouble&v);

	~VectorDouble();
	void push_back(double val);
	double value_at(int i) const;
	void change_value_at(double newVal, int index);
	int size() const;
	int capacity() const;
	void reserve(int);
	void resize(int);
	friend ostream& operater << (ostream& outs, const VectorDouble& v);
	friend bool operator == (const VectorDouble& v1, const VectorDouble& v2);
	void operator =(const VectorDouble& v1);

private:
	void expandCapacity();
	double *elements;
	int maxCount;
	int count;

};

#endif DYN_ARR_H