//array.h
#ifndef ARRAY_H
#define ARRAY_H

#include <utility> // Include utility header for std::pair
#include <stdexcept> // Include standard exceptions header for handling errors

// Returns index of the value, or -1 if not found
int find(int arr[], int size, int value);

// Modifies the value at index, returns old and new values
std::pair<int, int> modify(int arr[], int index, int newValue, int size);

// Adds a new value to the array, modifies size
void add(int arr[], int &size, int capacity, int newValue);

// Removes or replaces value at index, modifies size
void removeOrZero(int arr[], int &size, int index, bool remove);

// Prints the current state of the array
void printArray(const int arr[], int size);

#endif