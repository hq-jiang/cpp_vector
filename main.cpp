#include <iostream>
#include "vector.h"

using namespace std;
/*
void print_array(ostream& os, int* a, int sz){
  for(int i=0; i<sz; ++i){
    os << a[i] << " ";
  }
  os << endl;
}
*/
void print_vector(ostream& os, Vector* v){
  if (v->size()>0){
    for(int i=0; i<v->size(); ++i){
      os << v->get(i)<< " ";
    }
    os << endl;
  }
  else {
    printf("Empty vector\n");
  }
}

int main()
{
  // Default constructor
  printf("Vector via default constructor: ");
  Vector v_default; // Question: Do we have to use delete if p is nullptr?
  printf("successful\n");
  print_vector(cout, &v_default);


  // Constructor with size
  printf("Vector via size constructor: ");
  Vector v_sized(4);
  printf("successful\n");
  print_vector(cout, &v_sized);

  // Check sizes
  printf("Default vector size: %d \n", v_default.size());
  printf("Predefined sized vector size: %d \n", v_sized.size());

  // Set values and get values
  printf("Set and get values\n");
  for(int i=0; i<v_sized.size(); ++i){
    v_sized.set(i, i);
  }
  print_vector(cout, &v_sized);

  // Initialize with initializer list
  printf("Vector via initializer list: ");
  Vector v_init{1,2,3,4,5};
  printf("successful\n");
  print_vector(cout, &v_init);

  // Assign vector with an other vector;
  printf("Vector via other vector: ");
  Vector v_vector(v_init);
  printf("successful\n");
  print_vector(cout, &v_vector);

  // Use = operator for vector
  printf("Use = operator: ");
  Vector v_equals{1,2,3};
  v_equals = v_init;
  printf("successful\n");
  print_vector(cout, &v_equals);

  // Use [] operator for access
  Vector v_brck_op = v_init;
  const Vector v_const = v_init;
  printf("Use [] operator: \n");
  for(int i=0; i<v_brck_op.size(); ++i){
    printf("%d ", v_brck_op[i]);
  }
  printf("\n");
  printf("Use [] operator on const vector: \n");
  for(int i=0; i<v_const.size(); ++i){
    printf("%d ", v_const[i]);
  }
  printf("\n");
  printf("successful\n");



}

