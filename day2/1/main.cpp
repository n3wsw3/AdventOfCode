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

			// Count how many of matchChar there is in the
			// string
			int count = 0;
			for (auto& c : (std::string)sm[4]) {
				if (matchChar == c) {
					count++;
				}
			}

			int lowerBound = std::stoi((std::string)sm[1]);
			int upperBound = std::stoi((std::string)sm[2]);

			// Add one to validCount if the count is between the
			// bounds set.
			if (lowerBound <= count && count <= upperBound) {
				validCount++;
			}
		}
	}
	std::cout << validCount << std::endl;
}