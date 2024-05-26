## Домашнее задание №2

### Задание 1. Выбор направления

Проблематика: сейчас змейка “наезжает” на свой хвост.
Написать функцию, которая будет проверять корректность выбранного
направления. Змейка не может наступать на хвост, поэтому необходимо
запретить:
● перемещение справа-налево (при движении RIGHT нажатие стрелки
влево),
● перемещение сверху-вниз (при движении UP нажатие стрелки вниз),
● перемещение слева-направо (при движении LEFT нажатие стрелки
вправо),
● перемещение снизу-вверх (при движении DOWN нажатие стрелки
вверх).
Функция должна иметь вид:
int checkDirection(snake_t\* snake, int32_t key).

### Задание 2. Управление WASD

Добавить возможность управления змейкой клавишами WSAD (вне
зависимости от раскладки и регистра).
Зависимости от регистра в соответствии с таблицей.
W, w Вверх
S, s Вниз
A, a Влево
D, d Вправо
Для решения предлагается сделать массив кодов управления struct
control_buttons default_controls[CONTROLS]. CONTROLS – определяем
количество элементов массива.
В необходимых функциях в цикле необходимо сравнивать с каждым типом
управления в цикле: for (int i = 0; i < CONTROLS; i++)
