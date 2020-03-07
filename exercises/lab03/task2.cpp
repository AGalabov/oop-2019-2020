#include <iostream>

class Array
{
private:
    int *array;
    size_t size;

public:
    Array();
    Array(const int *, size_t);
    ~Array();
    int *getArray();
    size_t getSize();
    void setArray(const int *, size_t);

    void forEach(void (*)(const int));
    void forEach(void (*)(int &));
    int fold(int, int (*)(int, const int));
};

Array::Array()
{
    this->array = nullptr;
    this->size = 0;
}

Array::Array(const int *arr, size_t size)
{
    this->size = size;
    this->array = new int[size];
    for (size_t i = 0; i < size; ++i)
    {
        this->array[i] = arr[i];
    }
}

Array::~Array()
{
    delete[] this->array;
    // You can uncomment the next line to see when the memory is cleared

    // std::cout << "Memory cleared\n";
}

int *Array::getArray()
{
    return this->array;
}

size_t Array::getSize()
{
    return this->size;
}

void Array::setArray(const int *arr, size_t size)
{
    delete[] this->array;

    this->size = size;
    this->array = new int[size];
    for (size_t i = 0; i < size; ++i)
    {
        this->array[i] = arr[i];
    }
}

void Array::forEach(void (*func)(const int))
{
    for (size_t i = 0; i < this->size; ++i)
    {
        func(this->array[i]);
    }
}

void Array::forEach(void (*func)(int &))
{
    for (size_t i = 0; i < this->size; ++i)
    {
        func(this->array[i]);
    }
}

int Array::fold(int startValue, int (*func)(int, const int))
{
    int accumulatorValue = startValue;
    for (size_t i = 0; i < this->size; ++i)
    {
        accumulatorValue = func(accumulatorValue, this->array[i]);
    }
    return accumulatorValue;
}

// Note that those functions are not methods of the class
void print(const int x)
{
    std::cout << x << " ";
}

void increment(int &x)
{
    ++x;
}

void square(int &x)
{
    x *= x;
}

int sum(int a, int b)
{
    return a + b;
}

int prod(int a, int b)
{
    return a * b;
}

int main()
{
    size_t n;
    std::cin >> n;

    int *testArray = new int[n];

    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> testArray[i];
    }

    Array arr(testArray, n);

    arr.forEach(print);

    std::cout << "\n\nSum = " << arr.fold(0, sum) << std::endl;
    std::cout << "Prod = " << arr.fold(1, prod) << std::endl;

    arr.forEach(increment);
    std::cout << "\n\nAfter incrementation:\n";
    arr.forEach(print);

    arr.forEach(square);
    std::cout << "\n\nAfter square:\n";
    arr.forEach(print);

    std::cout << "\n\nSum = " << arr.fold(0, sum) << std::endl;
    std::cout << "Prod = " << arr.fold(1, prod) << std::endl;

    return 0;
}