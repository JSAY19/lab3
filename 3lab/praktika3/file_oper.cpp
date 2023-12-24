#include "file_oper.h"
#include <iostream>

void reader(ifstream& ist, vector<Planet>& planetVector) {
    Planet planet;
    // Читаем данные из потока и добавляем вектор planetVector
    while (ist >> planet) {
        planetVector.push_back(planet);
    }
    // Ошибка
    if (!ist.eof() && ist.fail()) {
        // Если не удалось прочитать данные из потока или возникла ошибка, выводим сообщение об ошибке
        cerr << "Error reading from the input stream." << endl;
    }
}

void output(vector<Planet>& planetVector) {
    // Выводим данные из вектора planetVector
    for (Planet& planet : planetVector) {
        cout << planet << endl;
    }
}