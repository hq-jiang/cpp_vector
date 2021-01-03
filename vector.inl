#include <iostream>
#include "vector.h"
#include <stdexcept>

Vector::Vector(){
  sz = 0;
  space=0;
  elem = nullptr;//new int[0];
}

Vector::~Vector(){
  delete[] elem;
  std::cout << "Free allocated memory" << std::endl;
}

Vector::Vector(int s){
  sz = s;
  space=s;
  elem = new int[space];
  for(int i=0; i<sz; ++i){
    elem[i] = 0;
  }
}

Vector::Vector(std::initializer_list<int> lst){
  int lst_len = lst.size();
  sz = lst_len;
  space = lst_len;
  elem = new int[space];
  int i=0;
  for(auto it=lst.begin(); it!=lst.end(); ++it){
    elem[i] = *it;
    i+=1;
  }
}

Vector::Vector(const Vector& v){
  sz = v.sz;
  space = v.space;
  elem = new int[space];
  for(int i=0; i<sz; ++i){
    elem[i] = v.elem[i];
  }
}

Vector& Vector::operator=(const Vector& v){
  sz = v.sz;
  space = v.space;
  delete[] elem;
  elem = new int[space];
  for(int i=0; i<sz; ++i){
    elem[i] = v.elem[i];
  }
}

int& Vector::operator[](const int i){
  return elem[i];
}

int Vector::operator[](const int i) const{
  return elem[i];
}


const int Vector::size() const{
  return sz;
}

const int Vector::capacity() const{
  return space;
}

int Vector::get(int i){
  if (i<sz){
    return elem[i];
  }
  else{
    throw std::invalid_argument("accessing vector out of range");
  }
}

void Vector::set(int i, int v){
  if (i<sz){
    elem[i] = v;
  }
  else{
    throw std::invalid_argument("accessing vector out of range");
  }

}

void Vector::reserve(const int i){
  if (i<=space) return;

  int* p = new int[i];
  for (int i=0; i<sz; ++i){
    p[i] = elem[i];
  }
  delete[] elem;
  elem = p;
  space = i;
}


void Vector::resize(const int i){
  reserve(i);
  for (int j=sz; j<i; ++j){
    elem[j] = 0;
  }
  sz = i;
}

void Vector::push_back(int v){
  if (space==0){
    reserve(4);
  }
  else if(sz==space){
    reserve(2*sz);
  }
  elem[sz] = v;
  sz++;
}
