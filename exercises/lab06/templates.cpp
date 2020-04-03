#include <iostream>
#include <fstream>
#include <functional>
 
template <typename T>
using tToT = std::function<T(T)>;

template <typename T>
tToT<T> multiplyBy(T x) {
    return [x] (T a) -> T {return x * a;};
}

template <typename T>
using tToVoid = std::function<void(T&)>;

template <typename T>
void forEach(T* arr, size_t size, tToVoid<T> func)
{
    for(size_t i=0; i<size; ++i)
    {
        func(arr[i]);
    }
}

template <typename T, typename K> 
K* map(T* arr, size_t size, std::function<K(T)> func)
{
    K* result = new K[size];
    for(size_t i=0; i<size; ++i)
    {
        result[i] = func(arr[i]);
    }
    return result;
}

template <typename T>  
void sort(T* arr, size_t size, std::function<bool(T,T)> func)
{
    for(size_t i=0; i < size - 1; ++i)
    {
        for(size_t j = i + 1; j<size; ++j)
        {
            if(func(arr[i], arr[j]))
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

struct Student{
    double mark;
    long fn;
    bool failed;
};

int main() {
    
    std::cout << "=========================TASK1======================" << std::endl << std::endl;
    int a = 3;

    tToT<int> intMultBy3 = multiplyBy(3);
    tToT<double> doubleMultBy3 = multiplyBy(3.0); //This is a double function
    tToT<double> anotherDoubleMultBy3 = multiplyBy<double>(3); // This is also a double function

    // returns 9
    std::cout << intMultBy3(3) << std::endl;
    // return 9 because it is expecting an integer and casts 3.5 as 3
    std::cout << intMultBy3(3.5) << std::endl;
    
    // actually return 10.5
    std::cout << doubleMultBy3(3.5) << std::endl;

    std::cout << "=========================TASK3======================" << std::endl << std::endl;

    // With integers
    int intArr[5] = {1, 5, 2, 4, 3};

    std::cout << ">>>> With int array:\nInitial array: ";
    //Note how we have to pass the template type argument int
    forEach<int>(intArr, 5, [] (int& a) { std::cout << a << " ";});

    sort<int>(intArr, 5, [] (int a,int b) { return a > b;});
    std::cout << "\nSortedArray: ";
    forEach<int>(intArr, 5, [] (int& a) { std::cout << a << " ";});


    // With Students
    std::cout << "\n\n>>>> With Students array:\n";
    size_t size;
    std::ifstream in("Students.txt", std::ios::in);

    in >> size;
    Student* studentsArr = new Student[size];

    //Note how we have to pass the template type argument Student
    //Note that we pass the ifstream in by reference - we cannot "copy" this type of object
    forEach<Student>(studentsArr, size, [&in] (Student& student) { 
        in >> student.fn >> student.mark >> student.failed;
    });
    in.close();

    // Sets a flag for std::cout to print bool values as true/false and not 1/0
    std::cout << std::boolalpha;

    std::cout << "Initial Students array:\n";
    forEach<Student>(studentsArr, size,  [] (Student a) { 
        std::cout << a.fn << " " << a.mark << " " << a.failed << std::endl;
     });

    sort<Student>(studentsArr, size, [] (Student a,Student b) { return a.fn > b.fn; });
    std::cout << "\nSorted Students array:\n";
    forEach<Student>(studentsArr, size,  [] (Student a) { 
        std::cout << a.fn << " " << a.mark << " " << a.failed << std::endl;
    });


    // With doubles
    std::cout << "\n\n>>>> With doubles array:\n";

    //Note how we have to pass both of the template arguments Student and double
    double* marksArray = map<Student, double>(studentsArr, size, [] (Student s) { return s.mark; });

    std::cout << "Initial Student marks (double) array:\n";
    forEach<double>(marksArray, size,  [] (double a) { 
        std::cout << a << " ";
    });

    sort<double>(marksArray, size, [] (double a, double b) { return a < b; });
    std::cout << "\nSorted Student marks (double) array: \n";
    forEach<double>(marksArray, size,  [] (double a) { 
        std::cout << a << " ";
    });
     
    delete [] marksArray;

    delete[] studentsArr;

    return 0;
}