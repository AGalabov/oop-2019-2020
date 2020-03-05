#include <iostream>
#include <cstring>
#include "helperFunctions.h"

template <typename T>
void replace(T *array, size_t sz, T toReplace, T replaceWith)
{
  for (size_t i = 0; i < sz; ++i)
  {
    if (array[i] == toReplace)
    {
      array[i] = replaceWith;
    }
  }
}

int main()
{

  bool testBoolArray[] = {true, false, true};
  printArray(testBoolArray);

  replace(testBoolArray, 3, false, true);
  printArray(testBoolArray);

  printSeparationLine();

  char testString[] = "Replacing a with b";
  std::cout << testString << std::endl;

  replace(testString, strlen(testString), 'a', 'b');
  std::cout << testString << std::endl;

  printSeparationLine();

  int testIntArray[] = {1, 2, 3, 2, 5};
  printArray(testIntArray);

  replace(testIntArray, 5, 2, 6);
  printArray(testIntArray);

  return 0;
}