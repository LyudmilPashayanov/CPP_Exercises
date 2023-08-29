#pragma once
#include <vector>
#include <memory>
#include "Data.h"

std::unique_ptr<std::vector<std::unique_ptr<Data>>> Make();
void Fill(std::vector<std::unique_ptr<Data>> &vec, int num);
void DisplayData(const std::vector<std::unique_ptr<Data>>& vector);

