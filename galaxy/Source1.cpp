#include <iostream>
#include <iomanip>
#include "Header1.h"
#include <exception>
#include "date.h"

using namespace std;

// Перегрузка оператора << для вывода информации о планете в поток вывода
ostream& operator<<(ostream& os, Galaxy& galaxy) {
    // Формируем строку с данными о galaxy
    os << "Name: " << setw(7) << galaxy.name;
    return os; // Возвращаем поток вывода
}


// Перегрузка оператора >> для чтения информации о galaxy из потока ввода
istream& operator>>(istream& is, Galaxy& galaxy) {
    try {
        is >> galaxy.name;

        galaxy.name = galaxy.name.substr(1, galaxy.name.size() - 2);
    }
    catch (const std::exception& e) {
        // Обработка ошибок чтения данных, если они возникнут
        std::cerr << "Error while reading galaxy: " << e.what() << std::endl;
    }

    return is; // Возвращаем поток ввода
}