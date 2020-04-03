#include <iostream>
#include <functional>
 
// A function that accepts an integer and return an integer
using intToInt = std::function<int(int)>;

// A function that accepts an integer and returns an intToInt type function
using intToFunctionOfAnotherInt = std::function<intToInt(int)>;

// Task 1:
intToInt multiplyBy(int x) {
    return [x] (int a) -> int{return x * a;};
}
 
// Task 2;
intToFunctionOfAnotherInt multiplyByAgain(int y) {
    return [y] (int x) {
        return [x, y] (int a) { return x*y*a; };
    };
}

// Task 3
// A function that accepts an integer by reference and doesn not return anything (void)
using intRefToVoid = std::function<void(int&)>;

intRefToVoid refMultiplyBy(int x) {
    return [x] (int& a) { a *= x;};
}

void forEach(int* arr, size_t size, intRefToVoid func)
{
    for(size_t i=0; i<size; ++i)
    {
        func(arr[i]);
    }
}
 
int main() {
    std::cout << "=========================TASK1======================" << std::endl << std::endl;
    int a = 3;

    // Creates callable objects (functions) of type intToInt
    intToInt multBy3 = multiplyBy(3);
    intToInt multBy5 = multiplyBy(5);

    std::cout << multBy3(a) << " " << multBy5(a) << std::endl;

    std::cout << "=========================TASK2======================" << std::endl << std::endl;

    // Creates a callable object (a function) of type intToFunctionOfAnotherInt
    intToFunctionOfAnotherInt multBy2 = multiplyByAgain(2);

    intToInt multBy2And4 = multBy2(4);
    intToInt multBy2And7 = multBy2(7);

    std::cout << multBy2And4(a) << " " << multBy2And7(a) << std::endl;


    std::cout << "=========================TASK3======================" << std::endl << std::endl;

    size_t size;
    
    std::cout << "Enter size: ";
    std::cin >> size;

    int* arr = new int[size];

    // Reads all elements of the array.
    // Note the reference passing.
    forEach(arr, size, [] (int& a) { std::cin >> a;});

    // Prints all elemens of the array with spaces
    std::cout << "Start array: ";
    forEach(arr, size, [] (int& a) { std::cout << a << " ";});
    std::cout << std::endl;

    // Use a function created in the previous tasks
    // NOTE: this is not a function that receives an argument by reference, therefore doesn't change the array
    forEach(arr, size, multBy3);

    // Prints all elemens of the array with commas (very simple to change the way we print stuff)
    std::cout << "No change in the array: ";
    forEach(arr, size, [] (int& a) { std::cout << a << ",";});
    std::cout << std::endl;

    intRefToVoid refMultBy3 = refMultiplyBy(3);
    // This one will update
    forEach(arr, size, refMultBy3);

    // Prints all elemens of the array
    std::cout << "Changed array: ";
    forEach(arr, size, [] (int& a) { std::cout << a << " ";});
    std::cout << std::endl;

    delete [] arr;

    return 0;
 }