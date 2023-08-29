#include "DataUtil.h"

std::unique_ptr<std::vector<std::unique_ptr<Data>>> Make()
{
	return std::make_unique<std::vector<std::unique_ptr<Data>>>();
}

void Fill(std::vector<std::unique_ptr<Data>>& vec, int num)
{
	for (size_t i = 0; i < num; i++)
	{
		int dataToFill;
		std::cout << "[" << i + 1 << "] Insert the data you want to add: " ;
		std::cin >> dataToFill;
		std::cout << std::endl;
		vec.push_back(std::make_unique<Data>(dataToFill));
	}
}

void DisplayData(const std::vector<std::unique_ptr<Data>>& vec) 
{
	for(std::unique_ptr<Data> const &data : vec)
	{
		data->DisplayData();
	}
}
