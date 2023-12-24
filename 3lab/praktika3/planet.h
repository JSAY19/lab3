#pragma once // ������ �� �������������� ��������� ������������� �����

#ifndef PLANET_H // �������� ������� ����� PLANET_H ��� �������������� �������������� ���������
#define PLANET_H // ����������� ����� PLANET_H

#include <iostream>
#include <string>
#include "date.h"
#include <exception>

using namespace std;

// ����������� ��������� Planet
struct Planet {
	string name;
	Date date;
	double radius;

	// ����������� �� ��������� ��� ������������� ������� �������
	Planet() {
		radius = 0;
	}
};

// ��������� ������������� ���������� ��� ������ � ����� Planet
std::ostream& operator<< (std::ostream& os, Planet& planet);
std::istream& operator>> (std::istream& is, Planet& planet);

#endif // ���������� ������� ��� PLANET_H