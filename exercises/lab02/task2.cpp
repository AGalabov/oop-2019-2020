#include<iostream>
#include<cstring>

template<typename T>
void replace(T* array,size_t sz, T toReplace, T replaceWith){
  for(size_t i = 0; i < sz; ++i){
    if(array[i] == toReplace){
      array[i] = replaceWith;
    }
  }
}

int main(){
  char testString[] = "Replacing a with b";
  std::cout << testString << std::endl;

  replace(testString, strlen(testString), 'a', 'b');
  std::cout << testString << std::endl;

  return 0;
}