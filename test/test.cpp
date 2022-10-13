#include "test.h"
#include "../index.h"
#include "termcolor.hpp"

#include <iostream>
#include <string>

using namespace std;

string boolString(bool value) {
	return value ? "TRUE" : "FALSE";
}

struct Option {
		bool toBe;
		int year;
};

Option options[] = {
		{
				false,
				200
		},
		{
				true,
				1960
		},
		{
				false,
				1953
		},
		{
				true,
				1632
		},
		{
				true,
				2020
		}
};

void printGreen(const string& test, const string& result) {
	cout << termcolor::green << "TEST " << "\"" << test << "\"" << " PASSED! RESULT: " << result;
}

void printRed(const string& test, const string& expected, const string& result) {
	cout << termcolor::red << "TEST " << "\"" << test << "\"" << " FAILED! EXPECTED: \"" << expected << "\" INSTEAD OF \"" << result << "\"!";
}

void test() {
	int optionsLength = sizeof(options) / sizeof(options[0]);

	for (int i = 0; i < optionsLength; i++) {
		Option option = options[i];

		bool result = isLeap(option.year);

		cout << endl;

		if (result == option.toBe) {
			printGreen(to_string(option.year), boolString(result));
		} else {
			printRed(to_string(option.year), boolString(option.toBe), boolString(result));
		}

		cout << endl;
	}
}