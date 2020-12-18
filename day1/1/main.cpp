#include <fstream>
#include <iostream>
#include "../../helper/measure.h"
#include <vector>

int addTo2020(std::vector<int> input)
{
	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < input.size(); j++) {
			if (input[i] + input[j] == 2020) {
				return input[i] * input[j];
			}
		}
	}
	return -1;
}

int main()
{
	std::vector<int> input;
	std::ifstream is("../input.in");
	int x;
	while (is >> x) {
		input.push_back(x);
	}

	auto [answer, time] = measure::function(addTo2020, input);
	std::cout << "Answer: " << answer << " in " << time.count() << " μs"
		  << std::endl;
}