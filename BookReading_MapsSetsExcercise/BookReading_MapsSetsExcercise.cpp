#include <iostream>
#include <set>
#include <fstream>
#include <sstream>
#include <map>


void ReadWords()
{
	std::map<std::string, int> words;
	std::map<std::string,std::set<int>> wordsLines;
	std::ifstream istream{ "words.txt" };
	if (!istream)
	{
		std::cout << "Error opening file." << std::endl;
	}
	else
	{
		std::string line;
		int currentLine = 1;
		while (std::getline(istream, line))
		{
			std::istringstream lineStream{ line };
			std::string word;
			while (lineStream >> word)
			{
				if (words.count(word) > 0)
				{
					words.at(word)++;
					wordsLines.at(word).insert(currentLine);

				}
				else
				{
					words.insert(std::pair<std::string, int>{ word, 1});
					wordsLines.insert(std::pair<std::string, std::set<int>>{ word, std::set<int> {currentLine}});
				}
			}
			currentLine++;
		}
	}
	istream.close();
}


int main()
{
	ReadWords();
}