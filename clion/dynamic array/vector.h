

#ifndef DYNAMIC_ARRAY_VECTOR_H
#define DYNAMIC_ARRAY_VECTOR_H
class Vector{
public:


    Vector();
    Vector(int size);
    Vector(Vector *copyFrom);
    Vector(double copyFrom[], int size);
    void copy(Vector* copyFrom,int capacity=0);
    void push_back(double number);
    int capacity() const;
    int size() const;
    void reverse();
    void resize(int size);
    double value_at(int i) const;
    void change_value_at(int index, double value);
    friend bool operator == (const Vector& v1, const Vector& v2);
    void operator =(const Vector& v1);
    void reserve(int size);


    virtual ~Vector();



private:
    double *array;
    int max_count;
    int count=0;
};
#endif //DYNAMIC_ARRAY_VECTOR_H
