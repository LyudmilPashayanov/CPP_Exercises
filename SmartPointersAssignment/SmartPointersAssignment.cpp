#include <iostream>
#include "Data.h"
#include "DataUtil.h"

int main()
{
	auto vec = Make();
	int dataPoints;
	std::cout << "How many data points would you like to add: ";
	std::cin >> dataPoints;
	std::cout << std::endl;
	Fill(*vec, dataPoints);
	DisplayData(*vec);
}