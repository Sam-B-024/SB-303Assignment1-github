//NAME: SAM R BURNS
//DATE: 8/31/2024
//ASSIGNMENT: 303 asignment 1
//SOURCES: CHATGPT for base coding understanding/start, CHATGPT helped explain "throw std::overflow_error" and how to modify and array. 303 class Syed Jawad Hussain Shah, PhD Candidate for base understanding of arrays. 

//Main.cpp
#include <iostream>
#include <fstream>
#include "array.h"
using namespace std;

int main() {
    const int capacity = 100;  // Maximum capacity of the array
    int arr[capacity];
    int size = 0;

    // Reading data from input file
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    while (inputFile >> arr[size]) {
        size++;
        if (size >= capacity) {
            cout << "Array reached maximum capacity!" << endl;
            break;
        }
    }
    inputFile.close();

    int choice, index, value;
    // Show menu and excute user choice
    while (true) {
        cout << "\nMenu: \n";
        cout << "1. Find an integer in the array\n";
        cout << "2. Modify an integer in the array\n";
        cout << "3. Add a new integer to the array\n";
        cout << "4. Remove an integer from the array\n";
        cout << "5. Exit\n";
        cout << "Enter a number through 1-5: ";
        cin >> choice;

try {
            switch (choice) {
            case 1:  // Find an integer in the array
                cout << "Enter the value to find: ";
                cin >> value;
                index = find(arr, size, value);
                if (index != -1) {
                    cout << "Value found at index: " << index << endl;
                } else {
                    cout << "Value not found in the array.\n";
                }
                break;

            case 2:  // Modify an integer in the array
                cout << "Enter the index to modify: ";
                cin >> index;
                cout << "Enter the new value: ";
                cin >> value;
                {
                    auto result = modify(arr, index, value, size);
                    cout << "Old value: " << result.first << ", New value: " << result.second << endl;
                }
                printArray(arr, size);
                break;

            case 3:  // Add a new integer to the array
                cout << "Enter the value to add: ";
                cin >> value;
                add(arr, size, capacity, value);
                cout << "Value added successfully.\n";
                printArray(arr, size);
                break;

            case 4:  // Remove or replace integer in array
                cout << "Enter the index to modify: ";
                cin >> index;
                cout << "Do you want to remove the integer or replace it with 0? Enter 1 for removal or enter 0 to replace with 0.";
                bool remove;
                cin >> remove;
                removeOrZero(arr, size, index, remove);
                cout << (remove ? "Value removed." : "Value replaced with 0.") << endl;
                printArray(arr, size);
                break;

            case 5:  // Exit the program
                cout << "Exiting program. See you later!\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
            }
        }
        catch (out_of_range &e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (overflow_error &e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}