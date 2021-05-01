/*
Matthias Kim
AP Create Task
May 3rd, 2021
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "Header.h"


int main()
{
    //input and output streams
    std::ifstream fin;
    std::ofstream fout;

    std::string userName, continueOrNo;

    //string variables for data in file
    std::string itemName, itemPrice;


    do {
        fin.open("Items.txt");
        std::cout << "What is your name?" << std::endl;
        std::cin >> userName;

        while (!fin.eof()) {
            std::getline(fin, itemName);
            std::cout << itemName << std::endl;
            std::getline(fin, itemPrice);
            std::cout << itemPrice << std::endl;
        }

        std::string e;
        std::cout << "Is there another person that wants to play? Enter a Y if so and any other letter to break. ";
        std::cin >> continueOrNo;
        for (int i = 0; i < continueOrNo.length(); i++) {
            e += tolower(continueOrNo.at(i));
        }
        fin.close();
    } while (continueOrNo.at(0) == 'y' || continueOrNo == "yes");



    
}

