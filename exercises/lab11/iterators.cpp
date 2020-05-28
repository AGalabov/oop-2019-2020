#include <iostream>
#include <vector>
#include <iterator>

typedef std::vector<int> IntVector;
typedef std::vector<int>::iterator IntVectorIter;

void print(IntVectorIter start, IntVectorIter end)
{
    IntVectorIter ptr = start;
    for (ptr; ptr != end; ++ptr)
    {
        std::cout << *ptr << " ";
    }
    std::cout << std::endl;
}

int main()
{
    IntVector v = {1, 2, 3, 4, 5};

    std::cout << "\n-----------------TASK 1-----------------\n";
    print(v.begin(), v.end());

    std::cout << "\n-----------------TASK 2-----------------\n";
    IntVector::iterator ptr = v.begin();
    advance(ptr, 2); // We move the ptr iterator with 2 positions

    std::cout << "Vector starting from position 2: ";
    print(ptr, v.end());

    std::cout << "Vector from position 2 to 1 element before the end: ";
    // next() and prev() generate new iterators and do not modify the passed argument
    print(next(v.begin(), 2), prev(v.end(), 1));

    std::cout << "\n-----------------TASK 3-----------------\n";
    IntVector toCopy = {10, 20, 30, 40};

    std::cout << "Initial vector: ";
    print(v.begin(), v.end());

    std::cout << "Initial vector to copy from: ";
    print(toCopy.begin(), toCopy.end());

    IntVector::iterator ToInsert = next(v.begin(), 2); // an iterator from position 3
    std::insert_iterator<IntVector> insertIterator = inserter(v, ToInsert);

    // we copy everything from the toCopy vector at the position
    // where insertIterator is placed
    copy(toCopy.begin(), toCopy.end(), insertIterator);

    std::cout << "Vector after elements of toCopy are inserted: ";
    print(v.begin(), v.end());

    return 0;
}