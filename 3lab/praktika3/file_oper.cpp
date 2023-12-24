#include "file_oper.h"
#include <iostream>

void reader(ifstream& ist, vector<Planet>& planetVector) {
    Planet planet;
    // ������ ������ �� ������ � ��������� ������ planetVector
    while (ist >> planet) {
        planetVector.push_back(planet);
    }
    // ������
    if (!ist.eof() && ist.fail()) {
        // ���� �� ������� ��������� ������ �� ������ ��� �������� ������, ������� ��������� �� ������
        cerr << "Error reading from the input stream." << endl;
    }
}

void output(vector<Planet>& planetVector) {
    // ������� ������ �� ������� planetVector
    for (Planet& planet : planetVector) {
        cout << planet << endl;
    }
}