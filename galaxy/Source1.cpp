#include <iostream>
#include <iomanip>
#include "Header1.h"
#include <exception>
#include "date.h"

using namespace std;

// ���������� ��������� << ��� ������ ���������� � ������� � ����� ������
ostream& operator<<(ostream& os, Galaxy& galaxy) {
    // ��������� ������ � ������� � galaxy
    os << "Name: " << setw(7) << galaxy.name;
    return os; // ���������� ����� ������
}


// ���������� ��������� >> ��� ������ ���������� � galaxy �� ������ �����
istream& operator>>(istream& is, Galaxy& galaxy) {
    try {
        is >> galaxy.name;

        galaxy.name = galaxy.name.substr(1, galaxy.name.size() - 2);
    }
    catch (const std::exception& e) {
        // ��������� ������ ������ ������, ���� ��� ���������
        std::cerr << "Error while reading galaxy: " << e.what() << std::endl;
    }

    return is; // ���������� ����� �����
}