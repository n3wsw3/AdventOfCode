#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>

int main()
{
	std::vector<std::string> input;
	std::ifstream is("../input.in");
	std::string x;
	while (!is.eof()) {
		std::getline(is, x);
		input.push_back(x);
	}

	const std::regex r("([0-9]+)-([0-9]+) ([a-z]): (.+)");

	int validCount = 0;
	for (auto& str : input) {
		std::smatch sm;
		if (std::regex_search(str, sm, r)) {
			char matchChar = ((std::string)sm[3])[0];

			// Convert string to integer and at the same time change
			// so it starts at 0 instead of 1.
			int lowerIndex = std::stoi((std::string)sm[1]) - 1;
			int upperIndex = std::stoi((std::string)sm[2]) - 1;

			std::string list = sm[4];

			// Add one to validCount if only one of the positions
			// have matchChar.
			if ((list[lowerIndex] == matchChar ||
			     list[upperIndex] == matchChar) &&
			    !(list[lowerIndex] == list[upperIndex])) {
				validCount++;
			}
		}
	}
	std::cout << validCount << std::endl;
}