# Упражнение 2 (28.02.2020г.) - Функции от по-висок ред. Шаблони на функции

## Задача 0

- Да се дефинира функция от по-висок ред, която прилага реалната едноаргументна функция f над всеки елемент на едномерен масив.
- Да се използва функцията от предната подточка, за да се дефинира функция от по-висок ред, която прилага реалната едноаргументна функция g над всеки елемент на квадратна матрица.

[Решение](./task0.cpp)

## Задача 1

Дадени са едноаргументна целочислена функция `f` и целочислен интервал `[a,b]`, такъв че `[a,b]` принадлежи на деф. област на `f`. Да се дефинира функция, която намира най - голямата стойност на f в дадения интервал.

[Решение](./task1.cpp)

## Задача 2

Реализирайте шаблон на функцията `void replace([подходящ тип] array, size_t sz, [подходящ тип] toReplace, [подходящ тип] replaceWith)`, която заменя всяко срещане на елемента `toReplace` в масива `array` с `replaceWith`.

[Решение](./task2.cpp)

## Задача 3

Допълнете структурата `Point` от миналия път, така че да репрезентира точка от n-мерно пространство. За тази структура, дефинирайте метод `distance`, който по дадена друга точка и функция `norm`, използва функцията за да намери разстоянието между двете точки. </br>
Функцията `norm` приема координати на точка от n-мерно пространство и числото `n` - размерност.

[Решение](./task3.cpp)

## Задача 4

Дадени са естествените числа `n,m` и `a`. Като се използват функции от по-висок ред да се пресместне стойността на израза:
![equation](https://latex.codecogs.com/gif.latex?%5Csum_%7Bi%3D1%7D%5En%7B%5Cprod_%7Bj%3D1%7D%5Em%7B%5Cfrac%7Ba+j%7D%7Bi+j%7D%7D%7D).

[Решение](./task4.cpp)

[_Предишно упражнение_](../lab01)
[_Следващо упражнение_](../lab03)
