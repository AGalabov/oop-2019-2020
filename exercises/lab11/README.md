# Упражнение 11 (22.05.2020г.) - Изключения. Итератори.

## Изключения (Exceptions)

### Задача 1
Да се напише функция `divide`, която разделя 2 цели числа. Да се извика със знаменател 0. Нека сега се пренапише функцията така, че да хвърля смислена грешка - текстово описание на възникналият проблем. Нека сега се извика метода и се обработи грешката.

### Задача 2
Да се напише функция с един аргумент, която да хвърля различен тип грешки спрямо различни негови стойности. В `main` да се обработи подобаващо всеки различен вид грешка. Да се дефинира и подразбиращо се поведение при неразпозната грешка.

### Задача 3
Да се добави допълнителен случай за горната функция, който да хвърля собствен тип грешка и да се обработи в `main` функцията.

### Задача 4
Някои методи хвърлят "известни" изключение. Такива са например: `std::out_of_range` и `std::bad_alloc`. Напишете малка програма, която да предизвика `std::out_of_range` и след това да обработи грешката.

[Решения](./exceptions.cpp)

## Итератори

### Задача 1
Да се напише функция `print`, която по подадени итератори към начало и край на вектор печата всички негови елементи.

### Задача 2
Да се изпробват функциите `advance`, `next`, `prev` за работа с итератори. Извикайте горната функция с различните получени итератори.

### Задача 3
Да се използва функциите `copy` и `inserter`, за да се постави съдържанието на 1 вектор на случайна позиция от друг вектор.

[Решения](./iterators.cpp)

[_Предишно упражнение_](../lab09-10)\
[_Следващо упражнение_](../lab12)
