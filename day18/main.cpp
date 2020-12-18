#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "expresly.h"

int main()
{
	std::vector<std::string> input;
	std::ifstream is("input.in");
	std::string x;
	while (!is.eof()) {
		std::getline(is, x);
		input.push_back(x);
	}

	long long total1 = 0;

	expresly::Options op;

	op.addOperator("*", 1, false, [](std::vector<double> v) {
		double val = v[0];
		for (std::size_t i = 1; i < v.size(); i++) {
			val *= v[i];
		}
		return val;
	});
	op.addOperator("/", 1, false, [](std::vector<double> v) {
		double val = v[0];
		for (std::size_t i = 1; i < v.size(); i++) {
			val /= v[i];
		}
		return val;
	});
	op.addOperator("+", 1, false, [](std::vector<double> v) {
		double val = 0;
		for (auto& d : v) {
			val += d;
		}
		return val;
	});
	op.addOperator("-", 1, false, [](std::vector<double> v) {
		double val = v[0];
		for (std::size_t i = 1; i < v.size(); i++) {
			val -= v[i];
		}
		return val;
	});

	for (auto& exp : input) {
		total1 += expresly::expression::eval(exp, op);
	}

	long long total2 = 0;

	op.addOperator("+", 2, false, [](std::vector<double> v) {
		double val = 0;
		for (auto& d : v) {
			val += d;
		}
		return val;
	});

	for (auto& exp : input) {
		total2 += expresly::expression::eval(exp, op);
	}

	std::cout << "1st: " << total1 << " 2nd: " << total2 << std::endl;
}