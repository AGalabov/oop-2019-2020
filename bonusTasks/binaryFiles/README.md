# Двоични файлове

## Малко теория и изочници
Двоичните файлове са с неформатиран вход и изход (записаната информация е просто в байтове). За разликата от текстовите те "не могат" да се четат от човек, но предоставят възможност за пряк достъп, посредством указатели за четене и писане.

### Отваряне на файл
Отварянето на файл става чрез функцията `open`, която приема като аргумент име на файл и режим на отваряне - комбинация от флагове, разделени от оператора `|`(OR).

| Флаг        | Ефект          |
| :---------: | :-------------: |
| ios::in     | Отваря файлът за четене      |
| ios::out    | Отваря файлът за писане       |
| ios::binary | Отваря файлът в двоичен режим |
| ios::ate    | Отваря файл с указатели сочещи към края му     |
| ios::app    | Писането във файл става като се долепя към края му     |
| ios::trunc  | Отваря файл, зачиствайки предишните му данни ако е в режим за писане     |

 Повече [Тук](http://www.cplusplus.com/doc/tutorial/files/)

### Get указател
Сочи към мястото, от което да започне четенето на данни
* `tellg` - връща позицията на указателя в байтове от началото. Повече [Тук](http://www.cplusplus.com/reference/istream/istream/tellg/)
* `seekg` - мести указателя за четене. Повече [Тук](http://www.cplusplus.com/reference/istream/istream/seekg/)

### Put указател
Сочи към мястото, от което да започне писането на данни
* `tellp` - връща позицията на указателя в байтове от началото. Повече [Тук](http://www.cplusplus.com/reference/ostream/ostream/tellp/)
* `seekp` - мести указателя за писане. Повече [Тук](http://www.cplusplus.com/reference/ostream/ostream/seekp/)

### Работа с двоични файлове
* `read` - чете от файл. Повече [ТУК](http://www.cplusplus.com/reference/istream/istream/read/)
* `write` - записва във файл. Повече [ТУК](http://www.cplusplus.com/reference/ostream/ostream/write/)
* `close` - затваря файлът
 
## Задача 1

Създайте 2 различни точки - `p1` и `p2` (обекти от класа `Point`). Запишете данните за тях в двоичен файл `points.bin`. Прочетете данните за нова точка `p3` от новосъздадения файл като:
* нека `p3` да вземе данните записани от `p1`
* нека `p3` да вземе данните записани от `p2`

_Забележка:_ Решение на тази задача с малко коментари може да видите [ТУК](./main.cpp), но ви съветваме да я решите и сами.

## Задача 2

Да се напише програма която въвежда данни за 10 двумерни точки (обекти на класа `Point`) и ги записва в файл `pointsData.bin`

## Задача 3

Да се напише програма която приема цяло число `n` в интервала `[0, 10]` и прочита данни за `n` двумерни точки (обекти на класа `Point`) от файла `pointsData.bin`(първите `n` във файла) и ги изпечатва на конзолата

## Задача 4

Да се напише програма която приема цяло положително число `n` и прочита данни за `n`-тата по ред точка във файла `pointsData.bin` и я изпечатва на конзолата. Ако такава точка липсва да се изпечата съобщение на конзолата.

## Задача 5

Да се напише програма която проверява размера на файла `pointsData.bin`. Да се изпише на конзолата колко байта е и информация за колко точки е записана в него, приемайки, че е плътно записан само и единствено с информация за точки.

## Задача 6

Да се напише програма която спрямо намереният в предходната задача размер създава динамично заделен масив от точки `points` и прочита данните за него от файла в обратен ред (`points[0]` да съдържа информацията за последната точка във файла, `points[1]` - предпоследната и тн.)
