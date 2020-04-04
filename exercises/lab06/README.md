# Упражнение 6 (03.04.2020г.) - Lambda функции

## Задача 1:
Напишете функцияция `miltiplyBy`, която приема цяло число `х` и връща функция, приемаща цяло число `а` и връщаща произведението на `х` и `а`.
 
## Задача 2:
Напишете функция която приема число `y` и връща функция като тази от задача 1 (тоест връщаща нова ф-ция).
 
## Задача 3:
Напишете функция от по-висок ред (`forEach`), която преима масив от цели числа, размер и функцияция с един аргумент и прилага подадената функция над всеки елемент на масива.
* Иползвайте я като й подавате като аргумент lambda ф-ция.
* Иползвайте различни версии на ф-ции получени като резултат от ф-цията от задача 1.

[Решение 1-3](./solutions.cpp)
 
## Задача 4:
Напишете функция `sort`, която приема масив от студенти (стуктура от `fn`, `mark`, `failed` ) и размера му, както и финкция за сравнение (comparator function) и сортира масива.
* Да се пригоди фунцкия `forEach` за работа със студенти

[Решение](./students.cpp)

## Задача 5:
Напишете функциите от задача 1-4 като шаблонни.

[Решение](./templates.cpp)

## Задачи за самоподготовка:
* Напишете функции `divideFrom`, `divideBy` и `substractFrom`, `substractBy` подобни на **задача 1**, но с делене и изваждане. Забележете разликите със събиране и умножение - има значение реда на аргументите. 

_Пример:_
```cpp
substractFrom(3)(4); // result is 3 - 4 = -1
substractBy(3)(4); // result is 4 - 3 = 1
```

* Подобно на **задача 2** напишете функции `divideFromAgain`, `divideByAgain` и `substractFromAgain`, `substractByAgain`. Отново имайте предвид реда на аргументите. _Забележка:_ Тук имате повече поле за вариация на реда - 3 числа x,y,z => 6 възможни нареждания. Можете да ги изпробвате.

_Пример:_
```cpp
divideFromAgain(12)(3)(2); // result is 12 / 3 / 2 = 2
divideWithAgain(12)(3)(2); // result is 2 / 3 / 12 ~ 0.5555
```

* Напишете всяка една от функции от по-висок ред (ако все още не сте) `map`, `forEach`, `zip`, `reduce`, `each`, `some`, `find`. Извикайте ги като подавате различни **lambda** функции.
* Направете ги шаблонни.

_Пример:_
```cpp
int arr[5] = {1, 2, 3, 4, 5}; // the functions should work with dynamic arrays
size_t size = 5;
forEach<int>(arr, size, [] (const int& a) { 
    std::cout << a << " ";
}); // prints 1 2 3 4 5
each<int>(arr, size, [] (const int&a) { return a > 3}); // returns false
some<int>(arr, size, [] (const int&a) { return a > 3 && a%2 == 0}); // returns true (because of 4)
find<int>(arr, size, [] (const int&a) { return a%2 == 0}); // returns 2 ( the first occurance that satisfies the condition)
std::cout << reduce<int>(arr, size, [] (int& acc, const int& val) {
    acc += val;
}); // prints the sum: 15 (1 + 2 + 3 + 4 + 5)
double* res = map<int, double>(arr, size, [] (const int& a) {
    return 0.5 + a;
}) // res will be [1.5, 2.5, 3.5, 4.5, 5.5]
double* zipped = zip<int, double, double>(arr, res, size, [] (const int& a, const double& b) {
    return a * b;
}) // res will be [1.5, 5, 10.5, 18, 27.5]
```

* Използвайте горните функции за работа с класове. Извиквайте методите на клас в **lambda** функции.

[*Предишно упражнение*](../lab05)
