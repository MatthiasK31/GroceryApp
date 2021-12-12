#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include "Header.h"

#pragma warning(disable:4996)

using namespace std;

int main()
{
    //input and output streams
    ifstream fin("Items.txt");
    ofstream fout("ShoppingList.txt");
    FILE* pFile = fopen("ShoppingList.txt", "a");


    //variables
    string continueOrNo, userName, letterCount = "abcdefgh";
    string answerChoice;
    string reply, currentItem, newItem;

    string price;
    double newPrice = 0;

    string item;
    int numberOfItems;
    int count = 0;
    double totalItems, totalCost, multiplier = 0;
    bool keepAsking = true, yesOrNo = true, notOnList = false;

    //variables for data in file
    string itemName, itemPrice;
    vector<string> items;
    vector<double> prices;
    vector<double> payment;

    do {
        //ask for name and print top message in file
        userName = askAndPrintName();
        fprintf(pFile, "Grocery Shopping List for: %s\n------------------------------------------\n", userName.c_str());


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
            if (count == 0)
                cout << "What would you like to purchase today?" << endl;
            cout << "Please enter the corresponding letter to the food item you want(Press N to break) : ";
            getline(cin, answerChoice);
            answerChoice = tolower(answerChoice.at(0));
            //switch-case statement to check that the input satisfies the conditions of being a letter from a to h 
            switch (answerChoice.at(0)) {
            case 'a':
                currentItem = "Lettuce";
                multiplier = 2.39;
                break;
            case 'b':
                currentItem = "Loaf of Bread";
                multiplier = 2.59;
                break;
            case 'c':
                currentItem = "Tortilla Chips";
                multiplier = 3.19;
                break;
            case 'd':
                currentItem = "Gum";
                multiplier = 0.99;
                break;
            case 'e':
                currentItem = "Soda";
                multiplier = 1.19;
                break;
            case 'f':
                currentItem = "Gallon o/ Milk";
                multiplier = 4.39;
                break;
            case 'g':
                currentItem = "Muffin";
                multiplier = 0.89;
                break;
            case 'h':
                currentItem = "Water";
                multiplier = 0.99;
                break;
            case 'n': {
                keepAsking = false;
                break;
            }
            default: {
                //allows the user to enter an item not on the menu of items
                cout << "Would you like to enter another item that is not listed?\nType Y if so or type anything else to redo your answer choice.\t";
                cin.ignore(INT_MAX, '\n');
                getline(cin, reply);
                string temp;

                //turn response into full lowercase
                for (int i = 0; i < reply.length(); i++) {
                    temp += tolower(reply.at(i));
                }
                reply = temp;
                //take the name and price of the item
                if (reply.at(0) == 'y' || reply == "yes") {
                    notOnList = true;
                    cout << "Enter the name of the item:\t";
                    getline(cin, currentItem);
                    cout << "Enter the price of this item:\t";
                    getline(cin, price);
                    newPrice = stod(price);
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
                //ask how many of the item the user would like to purchase; error trap and loop until a positive integer is entered
                cout << "How many of this item would you like to purchase?\t";
                getline(cin, item);
                numberOfItems = stoi(item);
                yesOrNo = checkValidNumInput(to_string(numberOfItems));

                while (yesOrNo) {
                    cout << "\tEnter a valid number:\t";
                    getline(cin, item);
                    numberOfItems = stoi(item);
                    yesOrNo = checkValidNumInput(to_string(numberOfItems));
                }
                //calculate the total cost of the selected item and its quantity based on the type of item entered
                if (notOnList) {
                    totalCost = newPrice * numberOfItems;
                }
                else {
                    totalCost = multiplier * numberOfItems;
                }
                payment.push_back(totalCost);

                //print the item and the cost of all the items into a separate file
                //new file pointer; print out formatted table
                if (numberOfItems == 1)
                    currentItem += " x1";
                else
                    currentItem += " x" + to_string(numberOfItems);
                fprintf(pFile, "%-35s$%-10.2f\n", currentItem.c_str(), totalCost);
                count++;
            }
        }

        //calculate total and print out final statement
        double subtotal = 0;
        char* charC;
        charC = new char[userName.length() + 1];
        strcpy(charC, userName.c_str());
        for (int i = 0; i < payment.size(); i++) {
            subtotal += payment.at(i);
        }
        fprintf(pFile, "-----------------------------------------\n");
        fprintf(pFile, "%s, your total today is $%.2f\n\n\n", charC, subtotal);



        //ask for new person to enter data, if not, break program
        string e;
        cout << "Is there another person that wants to shop? Enter a Y if so and any other letter to break. ";
        getline(cin, continueOrNo);
        for (int i = 0; i < continueOrNo.length(); i++) {
            e += tolower(continueOrNo.at(i));
        }
        cin.clear();
        yesOrNo = true;
        keepAsking = true;

    } while (continueOrNo.at(0) == 'y' || continueOrNo == "yes");

    //close input/output streams
    fout.close();
    fin.close();
}