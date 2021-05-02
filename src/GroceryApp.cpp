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

#pragma warning(disable:4996)

using namespace std;

int main()
{
    //input and output streams
    ifstream fin("Items.txt");
    ofstream fout("ShoppingList.txt");

    //variables
    string continueOrNo, userName, letterCount = "abcdefgh";
    string answerChoice;
    double numberOfItems;
    int count = 0;
    double totalItems, totalCost, multiplier = 0;
    bool keepAsking = true, yesOrNo = true;
    vector<string> sendToFile;

    //variables for data in file
    string itemName, itemPrice;
    vector<string> items;
    vector<double> prices;



    do {
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
            cout << "What would you like to purchase today? Please enter the corresponding letter to the food item you want (Press N to break):  ";
            cin >> answerChoice;
            answerChoice = tolower(answerChoice.at(0));
            //switch-case statement to check that the input satisfies the conditions of being a letter from a to h 
            switch (answerChoice.at(0)) {
                case 'a':
                    fout << "Lettuce";
                    multiplier = 2.39;
                    break;
                case 'b':
                    fout << "Loaf of Bread";
                    multiplier = 2.59;
                    break;
                case 'c':
                    fout << "Tortilla Chips";
                    multiplier = 3.19;
                    break;
                case 'd':
                    fout << "Gum";
                    multiplier = 0.99;
                    break;
                case 'e':
                    fout << "Soda";
                    multiplier = 1.19;
                    break;
                case 'f':
                    fout << "Gallon o/ Milk";
                    multiplier = 4.39;
                    break;
                case 'g':
                    fout << "Muffin";
                    multiplier = 0.89;
                    break;
                case 'h':
                    fout << "Water";
                    multiplier = 0.99;
                    break;
                case 'n':{
                    keepAsking = false;
                    break;
                }
                default: {
                    string reply, newItem;
                    double newPrice;
                    cout << "Would you like to enter another item that is not listed?\nType Y if so or type anything else to redo your answer choice.\t";
                    cin.ignore(INT_MAX, '\n');
                    getline(cin, reply);
                    string temp;
                    for (int i = 0; i < reply.length(); i++) {
                        temp += tolower(reply.at(i));
                    }
                    reply = temp;
                    if (reply.at(0) == 'y' || reply == "yes") {
                        cout << "Enter the name of the item:\t";
                        getline(cin, newItem);
                        cout << "Enter the price of this item:\t";
                        cin >> newPrice;
                            
                        sendToFile.push_back(newItem);
                        fout << sendToFile.at(count);
                        count++;

                    }
                    else {
                        continue;
                    }
                }
            }
            
            if (tolower(answerChoice.at(0)) == 'n') {
                break;
            }
            else {
                cout << "How many of this item would you like to purchase?\t";
                cin >> numberOfItems;
                yesOrNo = checkValidNumInput(to_string(numberOfItems));

                while (yesOrNo) {
                    cout << "\tEnter a valid number:\t";
                    cin.clear();
                    cin >> numberOfItems;
                    yesOrNo = checkValidNumInput(to_string(numberOfItems));
                }

                totalCost = multiplier * numberOfItems;

                fout << fixed;
                fout << "\t\t\t\t" << setprecision(2) << totalCost << endl;
                totalCost = 0; totalItems = 0; answerChoice = "";
            }
        }

        

        string e;
        cout << "Is there another person that wants to play? Enter a Y if so and any other letter to break. ";
        cin >> continueOrNo;
        for (int i = 0; i < continueOrNo.length(); i++) {
            e += tolower(continueOrNo.at(i));
        }
        cin.clear();
        yesOrNo = true;
        keepAsking = true;
        
    } while (continueOrNo.at(0) == 'y' || continueOrNo == "yes");
    fout.close();
    fin.close();



}

