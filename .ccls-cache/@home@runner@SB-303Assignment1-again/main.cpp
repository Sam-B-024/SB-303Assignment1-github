//NAME: SAM R BURNS
//DATE: 8/31/2024
//ASSIGNMENT: 303 asignment 1
//SOURCES: 

#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

// Function to check if an integer exists in the array and return its index
int find(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;  // Return the index if the value is found
        }
    }
    return -1;  // Return -1 if the value is not found
}

// Function to modify the value of an integer in the array and return the old and new values
pair<int, int> modify(int arr[], int index, int newValue, int size) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");  // Throw an exception if index is invalid
    }
    int oldValue = arr[index];
    arr[index] = newValue;
    return {oldValue, newValue};  // Return both the old and new values
}

// Function to add a new integer to the end of the array (with try-catch)
void add(int arr[], int &size, int capacity, int newValue) {
    if (size >= capacity) {
        throw overflow_error("Array is full");  // Throw an exception if array is full
    }
    arr[size++] = newValue;
}

// Function to replace the value at a given index with 0 or remove the integer
void removeOrZero(int arr[], int &size, int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");  // Throw an exception if index is invalid
    }
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];  // Shift elements to the left
    }
    size--;  // Decrease size of the array
}

int main() {
    const int capacity = 100;  // Maximum capacity of the array
    int arr[capacity];
    int size = 0;

    // Reading data from file
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

    while (true) {
        cout << "\nMenu: \n";
        cout << "1. Find an integer in the array\n";
        cout << "2. Modify an integer in the array\n";
        cout << "3. Add a new integer to the array\n";
        cout << "4. Remove an integer from the array\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
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
                break;

            case 3:  // Add a new integer to the array
                cout << "Enter the value to add: ";
                cin >> value;
                add(arr, size, capacity, value);
                cout << "Value added successfully.\n";
                break;

            case 4:  // Remove an integer from the array
                cout << "Enter the index to remove: ";
                cin >> index;
                removeOrZero(arr, size, index);
                cout << "Value removed successfully.\n";
                break;

            case 5:  // Exit the program
                cout << "Exiting program...\n";
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

