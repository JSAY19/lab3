#pragma once
#include <fstream>
#include <vector>
#include "planet.h"

void reader(std::ifstream& ist, std::vector<Planet>& planetVector);
void output(std::vector<Planet>& planetVector);

void reader(std::ifstream& ist, std::vector<galaxy>& planetVector);
void output(std::vector<galaxy>& planetVector);
