#include <iostream>
#include "vector.h"
#include <stdexcept>

Vector::Vector(){
  sz = 0;
  elem = nullptr;//new int[0];
}

Vector::~Vector(){
  delete[] elem;
  std::cout << "Free allocated memory" << std::endl;
}

Vector::Vector(int s){
  sz = s;
  elem = new int[sz];
  for(int i=0; i<sz; ++i){
    elem[i] = 0;
  }
}

Vector::Vector(std::initializer_list<int> lst){
  int lst_len = lst.size();
  sz = lst_len;
  elem = new int[sz];
  int i=0;
  for(auto it=lst.begin(); it!=lst.end(); ++it){
    elem[i] = *it;
    i+=1;
  }
}

Vector::Vector(const Vector& v){
  sz = v.sz;
  elem = new int[sz];
  for(int i=0; i<sz; ++i){
    elem[i] = v.elem[i];
  }
}

Vector& Vector::operator=(const Vector& v){
  sz = v.sz;
  delete[] elem;
  elem = new int[sz];
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

