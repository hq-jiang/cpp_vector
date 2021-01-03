#ifndef VECTOR
#define VECTOR

#include <initializer_list>

class Vector{

    int sz;
    int space;
    int* elem;

  public:

    Vector();
    ~Vector();
    Vector(int s); // Initialize vector with size
    Vector(std::initializer_list<int> lst); // Initialize with initializer list
    Vector(const Vector& v); // Initialize Vector with existing vector
    Vector& operator=(const Vector& v); //  Pass vector assignment
    int& operator[](const int i);
    int operator[](const int i) const;

    const int size() const;
    const int capacity() const;

    int get(int i);
    void set(int i, int v);

    void reserve(const int i);
    void resize(const int i);
    void push_back(int v);

};

#include "vector.inl"

#endif // VECTOR

