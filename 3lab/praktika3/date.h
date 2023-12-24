#pragma once // Защита от множественного включения заголовочного файла
#ifndef DATE_H // Проверка наличия метки DATE_H для предотвращения множественного включения
#define DATE_H // Определение метки DATE_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Date {
    int day;
    int month;
    int year;

    // Конструктор по умолчанию для инициализации переменных даты нулями
    Date() : day(0), month(0), year(0) {}

    // Конструктор для поддержки инициализации из списка
    Date(std::initializer_list<int> list) {
        if (list.size() == 3) { // Проверка наличия трех элементов в списке инициализации
            auto it = list.begin(); // Итератор для перебора элементов списка
            year = *it; // Первый элемент списка - год
            ++it;
            month = *it; // Второй элемент списка - месяц
            ++it;
            day = *it; // Третий элемент списка - день
        }
        else {
            // Если список инициализации не содержит три элемента, выбрасываем исключение
            throw std::invalid_argument("Список инициализации должен содержать три элемента.");
        }
    }
};

// Перегрузка оператора >> для ввода даты из потока
istream& operator >> (istream& ist, Date& date);
// Перегрузка оператора << для вывода даты в поток
ostream& operator << (ostream& ost, Date& date);

#endif // Завершение условия для DATE_H