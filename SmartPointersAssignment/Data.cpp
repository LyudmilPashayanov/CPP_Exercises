#include "Data.h"

Data::Data(int data)
	: numberData{data} {
	std::cout << "Constructor of data: " << data << std::endl;
}

Data::~Data()
{
	std::cout << "Deconstruct of data: " << numberData << std::endl;
}

void Data::DisplayData()
{
	std::cout << "Object with data: " << numberData << std::endl;
}
