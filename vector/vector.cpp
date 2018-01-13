#include <iostream>
#include "vector.h"

Vector::Vector(){
  sz=0;
  elem=nullptr;
}

Vector::~Vector(){
  delete[] elem;
  std::cout << "DEBUG: Free allocated memory" << std::endl;
}

Vector::Vector(int s){
  sz = s;
  elem = new int[s];
  for(int i; i<sz; ++i){
    elem[i] = 0;
  }
}

Vector::Vector(std::initializer_list<int> lst){
  sz = lst.size();
  elem = new int[sz];
  std::copy(lst.begin(), lst.end(), elem);
}


Vector::Vector(const Vector& v){
  sz = v.sz;
  elem = new int[v.sz];
  std::copy(v.elem, v.elem+sz, elem);
}

Vector& Vector::operator=(const Vector& v){
  delete[] elem;
  int *p = new int[v.size()];
  std::copy(v.elem, v.elem+v.size(), p);
  elem = p;
  sz = v.size();
  return *this;
}

int Vector::get(int i){
  return elem[i];
}

void Vector::set(int i, int v){
  elem[i] = v;
}
