#include "pch.h"
#include "CppUnitTest.h"
#include <exception>
#include "../date.h"
#include "../planet.h"
#include "../file_oper.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestFor3practice
{
	TEST_CLASS(FileOperationsTest) { // ����� ��� ������������ �������� � �������
public:

    TEST_METHOD(FileOperationsTest_ReadAndOutput) { // ����� ��� ������������ ������ � ������ ������ �� �����
        string path = "test.txt";
        ofstream fs(path);
        fs << "��������: Earth | ����: 2023.12.25 | ������: 6371.0" << endl;
        fs << "��������: Venera | ����: 2023.12.25 | ������: 5039.5" << endl;
        fs.close();

        try {
            ifstream ifs(path);
            vector<Planet> planetVector;
            reader(ifs, planetVector);
            output(planetVector);
        } catch (const exception& e) {
            Assert::Fail(L"Exception caught during file operations.");
        }
    }
};

    TEST_CLASS(PlanetTest) { // ����� ��� ������������ ����������� ���������� � ������� Planet
public:

    TEST_METHOD(PlanetOutputOperatorTest) { // ������������ ��������� ������ ��� ������ Planet
        Planet planet;
        planet.name = "Earth";
        planet.date.year = 2023;
        planet.date.month = 12;
        planet.date.day = 25;
        planet.radius = 6371.0;

        std::stringstream ss;
        ss << planet;

        std::string expected_output = "��������: Earth | ����: 2023.12.25 | ������: 6371.0";
        Assert::AreEqual(ss.str(), expected_output);
    }

    TEST_METHOD(PlanetInputOperatorTest) { // ������������ ��������� ����� ��� ������ Planet
        Planet planet;
        std::stringstream ss("��������: Venera | ����: 2023.12.25 | ������: 5039.5");
        ss >> planet;

        Assert::AreEqual(planet.name, std::string("Venera"));
        Assert::AreEqual(planet.radius, 5039.5);
        Assert::AreEqual(planet.date.year, 2023);
        Assert::AreEqual(planet.date.month, 12);
        Assert::AreEqual(planet.date.day, 25);  
    }

    TEST_METHOD(ValidPlanetName)
    {
        Planet planet;
        planet.name = "Earth";
        Assert::AreEqual("Earth", planet.name.c_str());
    }

    TEST_METHOD(InvalidPlanetName)
    {
        Planet planet;
        planet.name = "";
        Assert::AreNotEqual("Earth", planet.name.c_str());
    }

    TEST_METHOD(ValidPlanetRadius)
    {
        Planet planet;
        planet.radius = 6371.0; 
        Assert::AreEqual(6371.0, planet.radius);
    }

    TEST_METHOD(InvalidPlanetRadius)
    {
        Planet planet;
        planet.radius = -100.0;
        Assert::AreNotEqual(6371.0, planet.radius);
    }

    };

    TEST_CLASS(DateTest) { // ����� ��� ������������ ����������� ���������� � ������� Date
public:

    TEST_METHOD(DateOutputOperatorTest) { // ������������ ��������� ������ ��� ������ Date
        Date date;
        date.year = 2023;
        date.month = 12;
        date.day = 25;
        std::stringstream ss;
        ss << date;

        Assert::AreEqual(ss.str(), std::string("2023.12.25"));
    }

    TEST_METHOD(DateInputOperatorTest) {  // ������������ ��������� ����� ��� ������ Date
        Date date;
        std::stringstream ss("2023.12.25");
        ss >> date;

        Assert::AreEqual(date.year, 2023);
        Assert::AreEqual(date.month, 12);
        Assert::AreEqual(date.day, 21);
    }

    TEST_METHOD(DateLeapYearTest) { 
        Date date;
        date.year = 2024;
        date.month = 2;
        date.day = 29;
        std::stringstream ss;
        ss << date;

        // ���������, ��� ��� ����������� ���� ��������� ��������� ���� 29 �������
        Assert::AreEqual(ss.str(), std::string("2024.2.29"));
    }

    TEST_METHOD(DateNonLeapYearTest) {
        Date date;
        std::stringstream ss("2023.2.29");
        ss >> date;

        // ���������, ��� ��� ������������� ���� �� �������� ��������� 29 �������
        Assert::AreNotEqual(date.day, 29);
    }

    TEST_METHOD(InvalidDayInMonth)
    {
        Date date;
        date.year = 2023;
        date.month = 4; 
        date.day = 31;   

        // ���������, ��� ������������� ���������� ��� ������� ������ ������������ ���� � ������
        Assert::ExpectException<std::invalid_argument>([&]() { throw std::invalid_argument("Invalid day for April"); });
    }

    TEST_METHOD(InvalidMonth)
    {
        Date date;
        date.year = 2023;
        date.month = 13; 

        // ���������, ��� ������������� ���������� ��� ������� ������ ������������ �����
        Assert::ExpectException<std::invalid_argument>([&]() { throw std::invalid_argument("Invalid month"); });
    }

    TEST_METHOD(InvalidYear)
    {
        Date date;
        date.year = -100;  
        // ���������, ��� ������������� ���������� ��� ������� ������ ������������ ���
        Assert::ExpectException<std::invalid_argument>([&]() { throw std::invalid_argument("Invalid year"); });

        date.year = 10000; 
        // ���������, ��� ������������� ���������� ��� ������� ������ ������������ ���
        Assert::ExpectException<std::invalid_argument>([&]() { throw std::invalid_argument("Invalid year"); });
    }

    TEST_METHOD(InvalidDateFormat)
    {
        Date date;
        std::istringstream iss("2023-04-31");  

        // ���������, ��� ������������� ���������� ��� ������� ��������� ���� � ������������ �������
        Assert::ExpectException<std::invalid_argument>([&]() { iss >> date; });
    }
    };
}
