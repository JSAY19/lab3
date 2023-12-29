#include <iostream>
#include <fstream>
#include "date.h"
#include <exception>

using namespace std;


bool IsLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

std::istream& operator>>(std::istream& is, Date& date) {
    try {
        is >> date.year;
        is.get();
        is >> date.month;
        is.get();
        is >> date.day;

        // Ошибка даты1
        if (date.month == 2 && date.day == 29 && !IsLeapYear(date.year)) {
            throw std::runtime_error("Invalid date: Not a leap year, but day is 29 in February.");
        }

    }
    catch (const std::exception& e) {
        // Ошибка даты2
        std::cerr << "Error while reading Date data: " << e.what() << std::endl;
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, Date& date) {
    os << date.year << "." << date.month << "." << date.day;
    return os;
}
