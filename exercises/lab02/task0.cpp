#include<iostream>
#include"helperFunctions.h"

double id(double x){
  return x;
}

double succ(double x){
  return x + 1;
}

double square(double x){
  return x * x;
}

void map(double* arr, size_t sz, double(*f)(double)){
  for (size_t i = 0; i < sz ; ++i){
    arr[i] = f(arr[i]);
  }
}

void mapMatrix(double** arr, size_t sz, double(*f)(double)){
  for (size_t i = 0; i < sz ; ++i){
    map(arr[i], sz, f);
  }
}

int main(){

  //testing first part of the task
  double arr[5] = {1, 2, 3, 4, 5};

  map(arr, 5, succ);
  printArray(arr); // should print 2 3 4 5 6
  printSeparationLine();

  map(arr, 5, square);
  printArray(arr); // should print 4 9 16 25 36
  printSeparationLine();

  //testing second part of the exercise

  //alternatively we should create the matrix using dynamic memory - this way we wont have trouble when passing the matrix to the function
  double matrix[3][3] = {1, 2, 3,
                      4, 5, 6,
                      7, 8, 9};
  printMatrix(matrix);
  printSeparationLine();

  double *matr[3] = {matrix[0], matrix[1], matrix[2]};

  mapMatrix(matr, 3, square);
  printMatrix_v2(matr);
  printSeparationLine();

  mapMatrix(matr, 3, succ);
  printMatrix_v2(matr);

  return 0;
}