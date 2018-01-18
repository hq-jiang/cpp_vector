#ifndef VECTOR
#define VECTOR

class Vector{

    int sz;
    int* elem;

  public:


    Vector();
    ~Vector();
    Vector(int s); // Initialize vector with size
    Vector(std::initializer_list<int> lst); // Initialize with initializer list
    Vector(const Vector& v); // Initialize Vector with existing vector
    Vector& operator=(const Vector& v); //  Pass vector assignment

    int size() const {return sz;}

    int get(int i);
    void set(int i, int v);

};

#endif // VECTOR

