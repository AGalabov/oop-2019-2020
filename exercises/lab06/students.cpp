#include <iostream>
#include <fstream>
#include <functional>

struct Student
{
    double mark;
    long fn;
    bool failed;
};

using comparatorFunction = std::function<bool(Student, Student)>;

void sort(Student *arr, size_t size, comparatorFunction func)
{
    for (size_t i = 0; i < size - 1; ++i)
    {
        for (size_t j = i + 1; j < size; ++j)
        {
            if (func(arr[i], arr[j]))
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

void forEach(Student *arr, size_t size, std::function<void(Student &)> func)
{
    for (size_t i = 0; i < size; ++i)
    {
        func(arr[i]);
    }
}

int main()
{

    // I am using a .txt file so that you can easily read the conent of the uploaded file
    // Try to do it with a binary file
    std::ifstream in("Students.txt", std::ios::in);

    size_t size;
    in >> size;

    Student *arr = new Student[size];

    for (size_t i = 0; i < size; ++i)
    {
        in >> arr[i].fn;
        in >> arr[i].mark;
        in >> arr[i].failed;
    }

    in.close();

    // Sets a flag for std::cout to print bool values as true/false and not 1/0
    std::cout << std::boolalpha;

    std::cout << "\n==========Initial array=============\n";
    forEach(arr, size, [](Student a) {
        std::cout << a.fn << " " << a.mark << " " << a.failed << std::endl;
    });

    std::cout << "\n==========Sorted in ascending order by fn=============\n";
    sort(arr, size, [](Student a, Student b) { return a.fn > b.fn; });
    forEach(arr, size, [](Student a) {
        std::cout << a.fn << " " << a.mark << " " << a.failed << std::endl;
    });

    std::cout << "\n==========Sorted in descending order by mark=============\n";
    sort(arr, size, [](Student a, Student b) { return a.mark < b.mark; });
    forEach(arr, size, [](Student a) {
        std::cout << a.fn << " " << a.mark << " " << a.failed << std::endl;
    });

    std::cout << "\n==========Sorted - passed first=============\n";
    sort(arr, size, [](Student a, Student b) { return a.failed < b.failed; });
    forEach(arr, size, [](Student a) {
        std::cout << a.fn << " " << a.mark << " " << a.failed << std::endl;
    });

    delete[] arr;

    return 0;
}