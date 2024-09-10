//array.cpp
#include "array.h"
#include <iostream>
#include <fstream>
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
std::pair<int, int> modify(int arr[], int index, int newValue, int size) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");  // Throw an exception if index is invalid
    }
    int oldValue = arr[index];
    arr[index] = newValue;
    return {oldValue, newValue};  // Return both the old and new values
}

// Function to add a new integer to the end of the array
void add(int arr[], int &size, int capacity, int newValue) {
    if (size >= capacity) {
        throw std::overflow_error("Array is full");  // Throw an exception if array is full
    }
    arr[size++] = newValue;
}

// Function to either remove the value at a given index or replace it with 0
void removeOrZero(int arr[], int &size, int index, bool remove) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");  // Throw exception if index invalid
    }

    if (remove) {
        // Remove the value by shifting the elements left
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];  // Shift array elements to left
        }
        size--;  // Decrease size of array
    } else {
        // Replace the value at the index with 0
        arr[index] = 0;
    }
}

// Function to print the current state of the array
void printArray(const int arr[], int size) {
    cout << "Current array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}