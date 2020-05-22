#include <iostream>
#include <exception>
#include <string>
#include <vector>
// #include <stack>

// std::stack
// std::queue
// std::vector
// std::list

int main()
{

    // std::stack<int> s;
    // s.push(1);
    // s.push(2);
    // s[1];

    // std::vector<int> v;

    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);

    // v.begin(); // pointer to v[0]
    // v.end();   // pointer to v[3]

    // std::vector<int>::iterator ptr = v.begin();
    // std::vector<int>::iterator end = v.end();

    // for (ptr; ptr != end; ++ptr)
    // {
    //     std::cout << *ptr << " ";
    // }

    // ptr = v.begin();
    // std::cout << "\nChange\n";
    // advance(ptr, 2);

    // for (ptr; ptr != end; ++ptr)
    // {
    //     std::cout << *ptr << " ";
    // }

    // ptr = v.begin();
    // std::cout << "\nChange 2\n";
    // std::vector<int>::iterator ptr2 = next(ptr, 2);

    // std::cout << "\nWith old ptr\n";
    // for (ptr; ptr != end; ++ptr)
    // {
    //     std::cout << *ptr << " ";
    // }

    // std::cout << "\nWith new ptr2\n";

    // for (ptr2; ptr2 != end; ++ptr2)
    // {
    //     std::cout << *ptr2 << " ";
    // }

    // std::cout << "\nChange 3\n";
    // ptr = v.begin();
    // std::vector<int>::iterator end2 = prev(end, 1);

    // std::cout << "\nWith old end\n";
    // for (ptr; ptr != end; ++ptr)
    // {
    //     std::cout << *ptr << " ";
    // }

    // ptr = v.begin();
    // std::cout << "\nWith new end2\n";

    // for (ptr; ptr != end2; ++ptr)
    // {
    //     std::cout << *ptr << " ";
    // }

    // std::vector<int> v;

    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);

    // std::vector<int>::iterator ptr = v.begin();

    // std::vector<int>::iterator toInsert = next(v.begin(), 1);

    // std::insert_iterator<std::vector<int>> asd = inserter(v, toInsert);

    // std::vector<int> toCopy = {10, 20, 30, 40};
    // copy(toCopy.begin(), toCopy.end(), asd);

    // std::vector<int>::iterator end = v.end();

    // for (ptr; ptr != end; ++ptr)
    // {
    //     std::cout << *ptr << " ";
    // }

    // std::vector<bool> vector = {true, false};

    // std::cout << "The new std::vector after inserting elements is : ";
    // for (bool myInt : vector)
    // {
    //     std::cout << myInt << " ";
    // }

    std::vector<int> v(3, 2);

    std::vector<std::vector<int>> rows(3, std::vector<int>(3, 2));

    return 0;
}