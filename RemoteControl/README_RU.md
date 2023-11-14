# Адаптер для удаленного управления QYT-KT7900D ([EN](README.md))

Адаптер позволяет программно нажимать на кнопки передней панели станции через последовательный порт. Это может быть полезно для тесной интеграции с каким-либо сторонним ПО (например Telegram Bot).  Поддерживаемые команды:

- ```+``` "Вверх"
- ```-``` "Вниз"
- ```e``` "Exit/ABCD"
- ```m``` "Menu"
- ```t``` Включает передачу
- ```s``` Выключает передачу

Данного набора команд достаточно чтобы программно изменить большинство настроек станции или выбрать нужный канал (каналы)

### Компоненты

- [Arduino Nano](https://docs.arduino.cc/hardware/nano)
- [PC817 x 4](https://www.farnell.com/datasheets/73758.pdf)
- 4 резистора 220 Ом
- 3 резистора 1К
- тонкие провода
- разьем 7 или 8 пинов
- макетная плата
- Коннектор RJ45 
- какой-нибудь мелкий MOSFET (я взял с дохлой батареи ноута)

### Инструменты

- Паяльник =)
- [Fritzing](https://github.com/fritzing/fritzing-app/releases) чтобы посмотреть файл схемы ![RemoteControl.fzz](https://github.com/satcom-uhf/QYT-KT7900D/blob/main/RemoteControl/RemoteControl.fzz)
- [Arduino IDE](https://www.arduino.cc/en/software) чтобы скомпилировать и загрузить скетч ![RemoteControl.ino](https://github.com/satcom-uhf/QYT-KT7900D/blob/main/RemoteControl/RemoteControl.ino) в Arduino

## Схема
![Scheme](Scheme.png)

### Шаг 1. Смонтируйте и припаяйте все копоненты на плату согласно схеме
![Board1](BreadBoard1.png)
![Board2](BreadBoard2.png)

### Шаг 2. Откройте прошивку  ![RemoteControl.ino](https://github.com/satcom-uhf/QYT-KT7900D/blob/main/RemoteControl/RemoteControl.ino) с помощью Arduino IDE и загрузите ее в Arduino Nano
### Шаг 3. Снимите переднюю панель и подключите провода к указанным точкам

![ConnectionPoints](FrontPanelPoints.png)
![Wires](FrontPanelWires.png)
### Шаг 4. Приклейте разьем суперклеем
![Connector](Connector.png)

### Шаг 5. Подключите адаптер
![Connected](Connected.png)
 Готово!
