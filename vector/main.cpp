#include <iostream>
#include "vector.h"

using namespace std;

void print_array(ostream& os, int* a, int sz){
  for(int i=0; i<sz; ++i){
    os << a[i] << " ";
  }
  os << endl;
}

void print_vector(ostream& os, Vector* v){
  for(int i=0; i<v->size(); ++i){
    os << v->get(i)<< " ";
  }
  os << endl;
}

int main()
{

  int* p = new int[10];
  cout << "Sizeof operator test" << endl;
  cout << sizeof(char) << endl;
  cout << sizeof(int) << endl;
  cout << sizeof(int*) << endl;

  for(int i=0; i<10; ++i){
    p[i] = i+100;
  }

  cout << "Printing values of an array" << endl;
  print_array(cout, p, 10);



  int* p2 = new int[11];

  for(int i=0; i<11; ++i){
    p2[i] = i+100;
  }
  print_array(cout, p2, 11);

  delete[] p;
  delete[] p2;


  Vector v1(10);
  Vector v2(11);

  for(int i=0; i<v1.size(); ++i){
    v1.set(i, i+100);
  }

  for(int i=0; i<v2.size(); ++i){
    v2.set(i, i+100);
  }

  print_vector(cout, &v1);
  print_vector(cout, &v2);

  // Drill Second part
  int* l = new int{7};
  int* l1 = l;

  cout << "Pointer: "<< l1 << " and its value "<< *l1<<  endl;

  // Chapter 18
  // Initializer list
  Vector v_init1{3, 4, 6};
  Vector v_init2 = {3, 4, 6};
  cout << "Vector with initialized with initializer list" << endl;
  print_vector(cout, &v_init1);
  print_vector(cout, &v_init2);

  // Copy constructor
  Vector v_copy = v_init1;//or v_copy{v_init1}
  cout << "Copy constructor" << endl;
  print_vector(cout, &v_copy);
  v_copy.set(0,0);
  print_vector(cout, &v_init1);
  print_vector(cout, &v_copy);


  // Copy assignment
  Vector v_copy2;
  v_copy2 = v_copy;
  cout << "Copy assignment" << endl;
  print_vector(cout, &v_copy2);
  v_copy2.set(0,1);
  print_vector(cout, &v_copy);
  print_vector(cout, &v_copy2);

}

