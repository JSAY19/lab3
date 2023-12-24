#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <fstream>
#include <string>
#include "date.h"
#include "planet.h"
#include "file_oper.h"
#include <vector>

using namespace std;

int main() {
    // Включаем утечки памяти
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    setlocale(LC_ALL, "Ru");

    // Указываем путь к файлу
    string path = "test.txt";

    // Создаем объект для чтения файла
    ifstream fs;

    try {
        // Открываем файл по указанному пути
        fs.open(path);

        // Проверяем, удалось ли открыть файл
        if (!fs.is_open()) {
            // В случае неудачи выбрасываем исключение с сообщением об ошибке
            throw runtime_error("Unable to open file: " + path);
        }

        // Создаем вектор объектов типа Planet для хранения данных
        vector<Planet> planetVector;

        // Читаем данные из файла и заполняем ими вектор planetVector
        reader(fs, planetVector);

        // Выводим информацию из вектора planetVector
        output(planetVector);

    }
    catch (const exception& e) {
        // Ловим исключения, выводим сообщение об ошибке
        cerr << "Exception caught: " << e.what() << endl;
    }

    // Выводим информацию об утечках памяти
    _CrtDumpMemoryLeaks();

    return 0;
}