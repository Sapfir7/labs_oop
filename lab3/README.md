# **Лабораторная работа *03*** #


## Цель ##
- Изучение механизмов работы с наследованием в С++;
- Изучение механизма перегрузки операций 

## Задание для *13* варианта ## 
 Разработать классы согласно варианту задания, классы должны наследоваться от базового 
класса Figure. Фигуры являются фигурами вращения. 
Фигуры 13 варианта:
- Ромб
- 5-угольник 
- 6-угольник

Все классы должны поддерживать набор общих методов: 
1. Вычисление геометрического центра фигуры вращения; 
2. Вывод в стандартный поток вывода std::cout координат вершин фигуры через 
перегрузку оператора << для std::ostream; 
3. Чтение из стандартного потока данных фигур через перегрузку оператора >> для 
std::istream 
4. Вычисление площади фигуры через перегрузку оператора приведения к типу double; 
Создать программу, которая позволяет: 
• Вводить из стандартного ввода std::cin фигуры, согласно варианту задания. 
• Сохранять созданные фигуры в массив (по аналогии с предыдущей лабораторной 
работой Array) указатели на фигуру (Figure*) 
• Фигуры должны иметь переопределенные операции копирования (=), перемещения (=) и 
сравнения (==) 
• Вызывать для всего массива общие функции (1-3 см. выше).Т.е. распечатывать для 
каждой фигуры в массиве геометрический центр и площадь. 
• Необходимо уметь вычислять общую площадь фигур в массиве. 
• Удалять из массива фигуру по индексу;
