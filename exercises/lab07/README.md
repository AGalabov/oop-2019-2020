# Упражнение 7 (10.04.2020г.) - Наследяване

## Дефиниции и примерни решения на задачите, решавани в час

## Задача 0

Напишете клас `Identity`, който съдържа една член данна - цяло число и имплементирайте необходимите методи.

[дефиниция](./Identity.h)
[имплементация](./Identity.cpp)

## Задача 1

Дефинирайте и имплементирайте клас `Entity`, който съдържа две числа - координати X,Y и имплементирайте методи за промяна и печатане на координатите.

[дефиниция](./Entity.h)
[имплементация](./Entity.cpp)

## Задача 2

Създайте клас `Player`, който наследява класовете `Identity` и `Entity` от предните задачи. Класът трябва също така да съдържа и име на играча - указател към низ и неотр. цяло число - точките живот на играча.

[дефиниция](./Player.h)
[имплементация](./Player.cpp)

## Задача 3

Дефинирайте и имплементирайте клас `Mage`, който наследява класа `Player` от предишната задача. Дефинирайте следните член-данни - `mana` - цяло неотр. число съдържащо колчеството магически точки на магьосника и `spellStrength` - силата на магията на магьосника. Дефинирайте метод за атака.

[дефиниция](./Mage.h)
[имплементация](./Mage.cpp)

[*Предишно упражнение*](../lab06)