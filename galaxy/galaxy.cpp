#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>

#include "planet.h"

using namespace std;


struct Galaxy {
    string name;
    vector<Planet> planets;

    friend ostream& operator<<(ostream& os, const Galaxy& galaxy);
    friend istream& operator>>(istream& is, Galaxy& galaxy);
};


std::ostream& operator<<(std::ostream& os, const Galaxy& galaxy) {
    os << "Galaxy Name: " << "Mlechniy put" << "\n";
    os << "Planets:\n";
    for (const auto& planet : galaxy.planets) {
        os << planet << "\n"; 
    }
    return os;
}

std::istream& operator>>(std::istream& is, Galaxy& galaxy) {
    string name;
    getline(is, name);
    if (is.fail()) {
        throw runtime_error("Ошибка при чтении названия галактики");
    }

 
    string avbChars = "abcdef ";
    if (is.fail()) {
        throw runtime_error("Ошибка при чтении доступных символов");
    }

    // ***

    // Обработка каждого символа
    for (int i = 0; i < name.size(); i++) {
        bool exist = false;

        for (char c : avbChars) {
            if (c == name[i]) {
                exist = true;
                break; // Можно выйти из цикла, если символ найден
            }
        }

        if (exist && name[i] == ' ') {
            cout << galaxy.name;
        }
    }

    char bracket = 0;
    is >> bracket;
    if (bracket != '[') {
        throw runtime_error("В названии встретился допустимый символ");
    }

    Planet tplanet;

    // Считываем данные о планетах из файла
    while (is.good()) {
        char bracket = 0;
        is >> bracket;
        if (bracket == ']') {
            break;
        }

        is.unget();

        is >> tplanet;
        galaxy.planets.push_back(tplanet);
    }


}

// ----------------------------------------------------------

int main() {
    setlocale(LC_ALL, "RU");
    ifstream file("test.txt");
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла." << endl;
        return 1;
    }

    Galaxy galaxy;
    string line;

    file >> galaxy;
    std::cout << galaxy;

    return 0;

    getline(file, galaxy.name);
    // Ищем открывающую скобку
    while (std::getline(file, line)) {
        if (line.find('[') != std::string::npos) {
            break;
        }
    }

    vector<Planet> planets;
    Planet tplanet;

    // Считываем данные о планетах из файла
    while (file >> tplanet) {
        planets.push_back(tplanet);
    }

    // Выводим информацию о планетах
    for (const auto& planet : planets) {
        std::cout << planet << std::endl;
    }

    while (getline(file, line)) {
        stringstream ss(line);
        Planet planet;

 
        if (ss >> quoted(planet.name) >> planet.date >> planet.radius) {
            galaxy.planets.push_back(planet);
        }
        else {
            cerr << "Почти победа??" << endl;
        }
    }

    cout << "Galaxy: " << galaxy.name << endl;
    for (const auto& planet : galaxy.planets) {
        cout << "Planet: " << planet.name << ", Date: " << planet.date << ",  : " << planet.radius  << endl;
    }

    file.close();
    return 0;
}