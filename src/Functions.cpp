#include <string>
#include <iomanip>
#include <vector>
#include <iostream>

bool checkValidLetterInput(char tester)
{
	//try-cathc to validate input
	try {
		if (tester == tolower('A')) {
			return false;
		}
		else if (tester == tolower('B')) {
			return false;
		}
		else if (tester == tolower('C')) {
			return false;
		}
		else if (tester == tolower('D')) {
			return false;
		}
		else if (tester == tolower('E')) {
			return false;
		}
		else if (tester == tolower('F')) {
			return false;
		}
		else if (tester == tolower('G')) {
			return false;
		}
		else if (tester == tolower('H')) {
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

void printItems(std::string letters, std::vector<std::string> itemNames, std::vector<double> itemPrices) {
	for (int i = 0; i < itemNames.size(); i++) {
		printf("%-1c:\t%-25s %-20.2f\n", letters.at(i), itemNames.at(i).c_str(), itemPrices.at(i));
	}
}