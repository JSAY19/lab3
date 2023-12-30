#pragma once // ������ �� �������������� ��������� ������������� �����
#ifndef DATE_H // �������� ������� ����� DATE_H ��� �������������� �������������� ���������
#define DATE_H // ����������� ����� DATE_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Date {
public:
    int year = 0; // ������������� ������ ������ �� ���������
    int month = 0;
    int day = 0;

    // ����������� �� ���������
    Date() = default;

    // ����������� ��� ��������� ������������� �� ������
    Date(std::initializer_list<int> list) : year(0), month(0), day(0) {
        if (list.size() == 3) { // �������� ������� ���� ��������� � ������ �������������
            auto it = list.begin(); // �������� ��� �������� ��������� ������
            year = *it; // ������ ������� ������ - ���
            ++it;
            month = *it; // ������ ������� ������ - �����
            ++it;
            day = *it; // ������ ������� ������ - ����
        }
        else {
            // ���� ������ ������������� �� �������� ��� ��������, ����������� ����������
            throw std::invalid_argument("������ ������������� ������ ��������� ��� ��������.");
        }
    }
};

// ���������� ��������� >> ��� ����� ���� �� ������
istream& operator >> (istream& ist, Date& date);
// ���������� ��������� << ��� ������ ���� � �����
ostream& operator << (ostream& ost, const Date& date);

#endif // ���������� ������� ��� DATE_H