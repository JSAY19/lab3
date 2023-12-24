#pragma once // Защита от множественного включения заголовочного файла

#ifndef PLANET_H // Проверка наличия метки PLANET_H для предотвращения множественного включения
#define PLANET_H // Определение метки PLANET_H

#include <iostream>
#include <string>
#include "date.h"
#include <exception>

using namespace std;

// Определение структуры Planet
struct Planet {
	string name;
	Date date;
	double radius;

	// Конструктор по умолчанию для инициализации радиуса планеты
	Planet() {
		radius = 0;
	}
};

// Прототипы перегруженных операторов для работы с типом Planet
std::ostream& operator<< (std::ostream& os, Planet& planet);
std::istream& operator>> (std::istream& is, Planet& planet);

#endif // Завершение условия для PLANET_H