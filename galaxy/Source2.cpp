#include "pch.h"
#include "CppUnitTest.h"
#include <exception>
#include "../date.h"
#include "../planet.h"
#include "../file_oper.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_METHOD(FileOperationsTest_ReadGalaxyName) {
    string path = "test.txt";
    ofstream fs(path);
    fs << "Mlechniy put
        [
            "Mercury" 1631.11.07 2439.7
                "Venera" 1631.11.07 2439.7
                "PlanetaIustal" 1631.11.07 2439.7
        ]" << endl;
    fs.close();

    try {
        ifstream ifs(path);
        Galaxy galaxy;
        readGalaxyName(ifs, galaxy);

        Assert::AreEqual("Mlechniy put - 888", galaxy.name.c_str());
    }
    catch (const exception& e) {
        Assert::Fail(L"Exception caught during file operations.");
    }
}

TEST_METHOD(FileOperationsTest_ReadGalaxyName) {
    string path = "test.txt";
    ofstream fs(path);
    fs << "GalaxyName: Mlechniy put - 888" << endl;
    fs.close();

    try {
        ifstream ifs(path);
        Galaxy galaxy;
        readGalaxyName(ifs, galaxy); 

        Assert::AreEqual("Mlechniy put - 888", galaxy.name.c_str());
    }
    catch (const exception& e) {
        Assert::Fail(L"Exception caught during file operations.");
    }
}