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

using namespace std;

int main()
{
    //input and output streams
    ifstream fin;
    ofstream fout;

    //variables
    string continueOrNo, userName, letterCount = "abcdefgh";
    bool keepAsking = true;

    //variables for data in file
    string itemName, itemPrice;
    vector<string> items;
    vector<double> prices;



    do {
        fin.open("Items.txt");
        cout << "What is your name?\t";
        getline(cin, userName, '\n');

        //run through the file in its entirety 
        while (!fin.eof()) {
            //take the item name first and append to items vector
            getline(fin, itemName);
            items.push_back(itemName);

            //take the prices and append to prices vector
            getline(fin, itemPrice);
            double d = stod(itemPrice);
            prices.push_back(d);
        }

        //loop through all of the items and provide a list of the items that the user can add to his/her shopping list
        printItems(letterCount, items, prices);
        cout << endl;

        while (keepAsking) {
            cout << "What would you like to purchase today? Please enter the corresponding letter to the food item you want.  ";

        }



    
        string e;
        cout << "Is there another person that wants to play? Enter a Y if so and any other letter to break. ";
        cin >> continueOrNo;
        for (int i = 0; i < continueOrNo.length(); i++) {
            e += tolower(continueOrNo.at(i));
        }
        fin.close();
    } while (continueOrNo.at(0) == 'y' || continueOrNo == "yes");




}

