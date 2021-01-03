#include <iostream>
#include "vector.h"
#include <stdexcept>

template <typename T>
Vector<T>::Vector(){
  sz = 0;
  space=0;
  elem = nullptr;//new int[0];
}

template <typename T>
Vector<T>::~Vector(){
  delete[] elem;
  std::cout << "Free allocated memory" << std::endl;
}

template <typename T>
Vector<T>::Vector(int s){
  sz = s;
  space=s;
  elem = new int[space];
  for(int i=0; i<sz; ++i){
    elem[i] = 0;
  }
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> lst){
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

template <typename T>
Vector<T>::Vector(const Vector& v){
  sz = v.sz;
  space = v.space;
  elem = new int[space];
  for(int i=0; i<sz; ++i){
    elem[i] = v.elem[i];
  }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v){
  sz = v.sz;
  space = v.space;
  delete[] elem;
  elem = new int[space];
  for(int i=0; i<sz; ++i){
    elem[i] = v.elem[i];
  }
}

template <typename T>
int& Vector<T>::operator[](const int i){
  return elem[i];
}

template <typename T>
int Vector<T>::operator[](const int i) const{
  return elem[i];
}


template <typename T>
const int Vector<T>::size() const{
  return sz;
}

template <typename T>
const int Vector<T>::capacity() const{
  return space;
}

template <typename T>
int Vector<T>::get(int i){
  if (i<sz){
    return elem[i];
  }
  else{
    throw std::invalid_argument("accessing vector out of range");
  }
}

template <typename T>
void Vector<T>::set(int i, int v){
  if (i<sz){
    elem[i] = v;
  }
  else{
    throw std::invalid_argument("accessing vector out of range");
  }

}

template <typename T>
void Vector<T>::reserve(const int i){
  if (i<=space) return;

  int* p = new int[i];
  for (int i=0; i<sz; ++i){
    p[i] = elem[i];
  }
  delete[] elem;
  elem = p;
  space = i;
}

template <typename T>
void Vector<T>::resize(const int i){
  reserve(i);
  for (int j=sz; j<i; ++j){
    elem[j] = 0;
  }
  sz = i;
}

template <typename T>
void Vector<T>::push_back(int v){
  if (space==0){
    reserve(4);
  }
  else if(sz==space){
    reserve(2*sz);
  }
  elem[sz] = v;
  sz++;
}
