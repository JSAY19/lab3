#include <iostream>
#include <iomanip>
#include "planet.h"
#include <exception>
#include "date.h"

using namespace std;


// Перегрузка оператора << для вывода информации о планете в поток вывода
ostream & operator<<(ostream & os, Planet & planet) {
    // Формируем строку с данными о планете для вывода
    os << "Name: " << setw(7) << planet.name << " | " << "Date: " << planet.date << " | " << "Radius: " << planet.radius;
    return os; // Возвращаем поток вывода
}


// Перегрузка оператора >> для чтения информации о планете из потока ввода
istream& operator>>(istream& is, Planet& planet) {
    try {
        is >> planet.name; // Читаем имя планеты из потока
        // Удаляем первый и последний символ (в данном случае, скобки) из имени планеты
        planet.name = planet.name.substr(1, planet.name.size() - 2);
        is >> planet.date; // Читаем дату планеты из потока
        is >> planet.radius; // Читаем радиус планеты из потока
    }
    catch (const std::exception& e) {
        // Обработка ошибок чтения данных, если они возникнут
        std::cerr << "Error while reading Planet data: " << e.what() << std::endl;
    }

    return is; // Возвращаем поток ввода
}