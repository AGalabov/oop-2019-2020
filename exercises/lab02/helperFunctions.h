void printSeparationLine(){
  std::cout << "----------" << std::endl;
}

template <typename T, size_t sz>
void printArray(const T(&array)[sz]){
  for (size_t i = 0; i < sz; ++i){
    std::cout << array[i] << " ";
  }

  std::cout << std::endl;
}

template <typename T>
void printArrayPointer(const T* array, size_t sz){
  for (size_t i = 0; i < sz; ++i){
    std::cout << array[i] << " ";
  }

  std::cout << std::endl;
}

template <typename T, size_t sz>
void printMatrix(const T(&array)[sz][sz]){
  for(size_t i = 0; i < sz; ++i){
    printArray(array[i]);
  }
}

template <typename T, size_t sz>
void printMatrix_v2(T*(&array)[sz]){
  for(size_t i = 0; i < sz; ++i){
    printArrayPointer(array[i], sz);
  }
}

template<typename T>
void copyInSameSizeArrays(T* original, T* copyTo, size_t sz){
  for(size_t i = 0;i < sz; ++i){
     copyTo[i] = original[i];
    }
}