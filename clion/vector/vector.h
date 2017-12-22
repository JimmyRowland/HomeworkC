#ifndef DYN_ARR_H
#define DYN_ARR_H


class Vector
{
public:
    Vector();
    Vector(int size);
    Vector(const Vector& v);
    ~Vector();
    void push_back(double val);
    double value_at(int i) const;
    void change_value_at(double newVal, int index);
    int size() const;
    int capacity() const;
    void reserve(int);
    void resize(int);
    friend bool operator == (const Vector& vlhs, const Vector& vrhs);
    void operator =(const Vector& v1);

private:
    void copy(double *v,int size, int capacity);
    double *array;
    int max_count=0;
    int count=0;

};

#endif DYN_ARR_H