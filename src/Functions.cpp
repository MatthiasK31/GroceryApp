#include <string>
#include <iomanip>
#include <vector>
#include <iostream>
#include <fstream>

bool checkValidLetterInput(char tester)
{
	std::ofstream fout("ShoppingList.txt");

	//try-catch to validate input
	try {
		if (tester == 'a') {
			return false;
		}
		else if (tester == 'b') {
			return false;
		}
		else if (tester == 'c') {
			return false;
		}
		else if (tester == 'd') {
			return false;
		}
		else if (tester == 'e') {
			return false;
		}
		else if (tester == 'f') {
			return false;
		}
		else if (tester == 'g') {
			return false;
		}
		else if (tester == 'h') {
			return false;
		}
		else {
			return true;
		}
	}
	catch (std::invalid_argument& e) {
		//prompt user for valid input/continue loop
		return true;
	}
	return false;

}

bool checkValidNumInput(std::string tester)
{
	//try-catch to validate input
	try {
		double temp = std::stod(tester);
		int num = std::stoi(tester); // error trap this with a try/catch block

		if (temp != num) {
			return true;
		}
		if (num < 0) {
			return true;
		}
	}
	catch (std::invalid_argument& e) {
		//prompt user for valid input/continue loop
		return true;
	}
	return false;
}

void printItems(std::string letters, std::vector<std::string> itemNames, std::vector<double> itemPrices) {
	for (int i = 0; i < itemNames.size(); i++) {
		printf("%-1c:\t%-25s %-20.2f\n", letters.at(i), itemNames.at(i).c_str(), itemPrices.at(i));
	}
}