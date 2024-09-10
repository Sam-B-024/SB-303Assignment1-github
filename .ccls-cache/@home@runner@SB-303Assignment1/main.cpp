//NAME: SAM R BURNS
//DATE: 8/31/2024
//ASSIGNMENT: 303 asignment 1
//SOURCES: 

/*#include <iostream>
#include <fstream>

const int MAX_SIZE = 100;  // Define a maximum size for the array

// Function to read integers from a file into an array
int readDataFromFile(const std::string& filename, int arr[], int maxSize) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 0; // Return 0 to indicate an error
    }

    int count = 0;
    while (file >> arr[count] && count < maxSize) {
        ++count;
    }

    file.close();
    return count; // Return the number of elements read
}

// Function to check if a certain integer exists in the array
int findIntegerInArray(const int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    int arr[MAX_SIZE];
    int size;

    // Input file name
    std::string filename = "input.txt";

    // Read data from the file
    size = readDataFromFile(filename, arr, MAX_SIZE);
    if (size == 0) {
        std::cerr << "No data read or file could not be opened." << std::endl;
        return 1;
    }

    // Input integer to search for
    int target;
    std::cout << "Enter the integer to search for: ";
    std::cin >> target;

    // Find the integer in the array
    int index = findIntegerInArray(arr, size, target);
    if (index != -1) {
        std::cout << "Integer " << target << " found at index " << index << "." << std::endl;
    } else {
        std::cout << "Integer " << target << " not found in the array." << std::endl;
    }

    return 0;
}
*/


/*#include <iostream>
#include <fstream>

const int MAX_SIZE = 100;  // Define a maximum size for the array

// Function to read integers from a file into an array
int readDataFromFile(const std::string& filename, int arr[], int maxSize) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 0; // Return 0 to indicate an error
    }

    int count = 0;
    while (file >> arr[count] && count < maxSize) {
        ++count;
    }

    file.close();
    return count; // Return the number of elements read
}

// Function to check if a certain integer exists in the array
int findIntegerInArray(const int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function to modify the value at a specific index
bool modifyValueInArray(int arr[], int size, int index, int newValue, int &oldValue) {
    if (index < 0 || index >= size) {
        return false; // Return false if index is out of bounds
    }
    oldValue = arr[index]; // Store the old value
    arr[index] = newValue; // Update the value
    return true; // Return true to indicate success
}

int main() {
    int arr[MAX_SIZE];
    int size;

    // Input file name
    std::string filename = "input.txt";

    // Read data from the file
    size = readDataFromFile(filename, arr, MAX_SIZE);
    if (size == 0) {
        std::cerr << "No data read or file could not be opened." << std::endl;
        return 1;
    }

    // Input integer to search for
    int target;
    std::cout << "Enter the integer to search for: ";
    std::cin >> target;

    // Find the integer in the array
    int index = findIntegerInArray(arr, size, target);
    if (index != -1) {
        std::cout << "Integer " << target << " found at index " << index << "." << std::endl;

        // Modify the value at the found index
        int newValue;
        int oldValue;
        std::cout << "Enter the new value for index " << index << ": ";
        std::cin >> newValue;

        if (modifyValueInArray(arr, size, index, newValue, oldValue)) {
            std::cout << "Value at index " << index << " changed from " << oldValue << " to " << newValue << "." << std::endl;
        } else {
            std::cerr << "Error: Index out of bounds." << std::endl;
        }
    } else {
        std::cout << "Integer " << target << " not found in the array." << std::endl;
    }

    return 0;
}
*/


/*
#include <iostream>
#include <fstream>

const int MAX_SIZE = 100;  // Define a maximum size for the array

// Function to read integers from a file into an array
int readDataFromFile(const std::string& filename, int arr[], int maxSize) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 0; // Return 0 to indicate an error
    }

    int count = 0;
    while (file >> arr[count] && count < maxSize) {
        ++count;
    }

    file.close();
    return count; // Return the number of elements read
}

// Function to check if a certain integer exists in the array
int findIntegerInArray(const int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function to modify the value at a specific index
bool modifyValueInArray(int arr[], int size, int index, int newValue, int &oldValue) {
    if (index < 0 || index >= size) {
        return false; // Return false if index is out of bounds
    }
    oldValue = arr[index]; // Store the old value
    arr[index] = newValue; // Update the value
    return true; // Return true to indicate success
}

// Function to add a new integer to the end of the array
bool addIntegerToArray(int arr[], int &size, int newValue, int maxSize) {
    if (size >= maxSize) {
        std::cerr << "Error: Array is full. Cannot add new value." << std::endl;
        return false; // Return false if the array is full
    }
    arr[size] = newValue; // Add the new value to the end of the array
    ++size; // Increment the size
    return true; // Return true to indicate success
}

int main() {
    int arr[MAX_SIZE];
    int size;

    // Input file name
    std::string filename = "input.txt";

    // Read data from the file
    size = readDataFromFile(filename, arr, MAX_SIZE);
    if (size == 0) {
        std::cerr << "No data read or file could not be opened." << std::endl;
        return 1;
    }

    // Input integer to search for
    int target;
    std::cout << "Enter the integer to search for: ";
    std::cin >> target;

    // Find the integer in the array
    int index = findIntegerInArray(arr, size, target);
    if (index != -1) {
        std::cout << "Integer " << target << " found at index " << index << "." << std::endl;

        // Modify the value at the found index
        int newValue;
        int oldValue;
        std::cout << "Enter the new value for index " << index << ": ";
        std::cin >> newValue;

        if (modifyValueInArray(arr, size, index, newValue, oldValue)) {
            std::cout << "Value at index " << index << " changed from " << oldValue << " to " << newValue << "." << std::endl;
        } else {
            std::cerr << "Error: Index out of bounds." << std::endl;
        }
    } else {
        std::cout << "Integer " << target << " not found in the array." << std::endl;
    }

    // Add a new integer to the end of the array
    int newInt;
    std::cout << "Enter a new integer to add to the array: ";
    std::cin >> newInt;

    if (addIntegerToArray(arr, size, newInt, MAX_SIZE)) {
        std::cout << "Integer " << newInt << " added to the end of the array." << std::endl;
    }

    // Optional: Print the updated array
    std::cout << "Updated array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
*/
//space

/*
#include <iostream>
#include <fstream>

const int MAX_SIZE = 100;  // Define a maximum size for the array

// Function to read integers from a file into an array
int readDataFromFile(const std::string& filename, int arr[], int maxSize) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 0; // Return 0 to indicate an error
    }

    int count = 0;
    while (file >> arr[count] && count < maxSize) {
        ++count;
    }

    file.close();
    return count; // Return the number of elements read
}

// Function to check if a certain integer exists in the array
int findIntegerInArray(const int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function to modify the value at a specific index
bool modifyValueInArray(int arr[], int size, int index, int newValue, int &oldValue) {
    if (index < 0 || index >= size) {
        return false; // Return false if index is out of bounds
    }
    oldValue = arr[index]; // Store the old value
    arr[index] = newValue; // Update the value
    return true; // Return true to indicate success
}

// Function to add a new integer to the end of the array
bool addIntegerToArray(int arr[], int &size, int newValue, int maxSize) {
    if (size >= maxSize) {
        std::cerr << "Error: Array is full. Cannot add new value." << std::endl;
        return false; // Return false if the array is full
    }
    arr[size] = newValue; // Add the new value to the end of the array
    ++size; // Increment the size
    return true; // Return true to indicate success
}

// Function to replace or remove the value at a specific index
bool replaceOrRemoveValue(int arr[], int &size, int index, bool replaceWithZero) {
    if (index < 0 || index >= size) {
        return false; // Return false if index is out of bounds
    }
    if (replaceWithZero) {
        arr[index] = 0; // Replace the value at the index with 0
    } else {
        // Shift elements to the left to remove the element at index
        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --size; // Decrease the size of the array
    }
    return true; // Return true to indicate success
}

int main() {
    int arr[MAX_SIZE];
    int size;

    // Input file name
    std::string filename = "input.txt";

    // Read data from the file
    size = readDataFromFile(filename, arr, MAX_SIZE);
    if (size == 0) {
        std::cerr << "No data read or file could not be opened." << std::endl;
        return 1;
    }

    // Input integer to search for
    int target;
    std::cout << "Enter the integer to search for: ";
    std::cin >> target;

    // Find the integer in the array
    int index = findIntegerInArray(arr, size, target);
    if (index != -1) {
        std::cout << "Integer " << target << " found at index " << index << "." << std::endl;

        // Modify the value at the found index
        int newValue;
        int oldValue;
        std::cout << "Enter the new value for index " << index << ": ";
        std::cin >> newValue;

        if (modifyValueInArray(arr, size, index, newValue, oldValue)) {
            std::cout << "Value at index " << index << " changed from " << oldValue << " to " << newValue << "." << std::endl;
        } else {
            std::cerr << "Error: Index out of bounds." << std::endl;
        }
    } else {
        std::cout << "Integer " << target << " not found in the array." << std::endl;
    }

    // Add a new integer to the end of the array
    int newInt;
    std::cout << "Enter a new integer to add to the array: ";
    std::cin >> newInt;

    if (addIntegerToArray(arr, size, newInt, MAX_SIZE)) {
        std::cout << "Integer " << newInt << " added to the end of the array." << std::endl;
    }

    // Replace or remove a value
    int indexToModify;
    char choice;
    std::cout << "Enter the index to replace or remove: ";
    std::cin >> indexToModify;

    std::cout << "Enter 'r' to replace with 0 or 'd' to remove the integer: ";
    std::cin >> choice;

    bool success = false;
    if (choice == 'r') {
        success = replaceOrRemoveValue(arr, size, indexToModify, true);
        if (success) {
            std::cout << "Value at index " << indexToModify << " replaced with 0." << std::endl;
        } else {
            std::cerr << "Error: Index out of bounds." << std::endl;
        }
    } else if (choice == 'd') {
        success = replaceOrRemoveValue(arr, size, indexToModify, false);
        if (success) {
            std::cout << "Integer at index " << indexToModify << " removed." << std::endl;
        } else {
            std::cerr << "Error: Index out of bounds." << std::endl;
        }
    } else {
        std::cerr << "Invalid choice. Please enter 'r' or 'd'." << std::endl;
    }

    // Optional: Print the updated array
    std::cout << "Updated array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
*/


/*
#include <iostream>
#include <fstream>
#include <stdexcept> // For std::invalid_argument and std::out_of_range

const int MAX_SIZE = 100;  // Define a maximum size for the array

// Function to read integers from a file into an array
int readDataFromFile(const std::string& filename, int arr[], int maxSize) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 0; // Return 0 to indicate an error
    }

    int count = 0;
    while (file >> arr[count] && count < maxSize) {
        ++count;
    }

    file.close();
    return count; // Return the number of elements read
}

// Function to check if a certain integer exists in the array
int findIntegerInArray(const int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function to modify the value at a specific index
bool modifyValueInArray(int arr[], int size, int index, int newValue, int &oldValue) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds."); // Throw exception if index is out of bounds
    }
    oldValue = arr[index]; // Store the old value
    arr[index] = newValue; // Update the value
    return true; // Return true to indicate success
}

// Function to add a new integer to the end of the array
bool addIntegerToArray(int arr[], int &size, int newValue, int maxSize) {
    if (size >= maxSize) {
        std::cerr << "Error: Array is full. Cannot add new value." << std::endl;
        return false; // Return false if the array is full
    }
    arr[size] = newValue; // Add the new value to the end of the array
    ++size; // Increment the size
    return true; // Return true to indicate success
}

// Function to replace or remove the value at a specific index
bool replaceOrRemoveValue(int arr[], int &size, int index, bool replaceWithZero) {
    if (index < 0 || index >= size) {
        return false; // Return false if index is out of bounds
    }
    if (replaceWithZero) {
        arr[index] = 0; // Replace the value at the index with 0
    } else {
        // Shift elements to the left to remove the element at index
        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --size; // Decrease the size of the array
    }
    return true; // Return true to indicate success
}

int main() {
    int arr[MAX_SIZE];
    int size;

    // Input file name
    std::string filename = "input.txt";

    // Read data from the file
    size = readDataFromFile(filename, arr, MAX_SIZE);
    if (size == 0) {
        std::cerr << "No data read or file could not be opened." << std::endl;
        return 1;
    }

    // Input integer to search for
    int target;
    std::cout << "Enter the integer to search for: ";
    std::cin >> target;

    // Find the integer in the array
    int index = findIntegerInArray(arr, size, target);
    if (index != -1) {
        std::cout << "Integer " << target << " found at index " << index << "." << std::endl;

        // Modify the value at the found index with exception handling
        int newValue;
        int oldValue;
        try {
            std::cout << "Enter the new value for index " << index << ": ";
            std::cin >> newValue;

            if (modifyValueInArray(arr, size, index, newValue, oldValue)) {
                std::cout << "Value at index " << index << " changed from " << oldValue << " to " << newValue << "." << std::endl;
            }
        } catch (const std::out_of_range& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        } catch (...) {
            std::cerr << "An unexpected error occurred." << std::endl;
        }
    } else {
        std::cout << "Integer " << target << " not found in the array." << std::endl;
    }

    // Add a new integer to the end of the array
    int newInt;
    std::cout << "Enter a new integer to add to the array: ";
    std::cin >> newInt;

    if (addIntegerToArray(arr, size, newInt, MAX_SIZE)) {
        std::cout << "Integer " << newInt << " added to the end of the array." << std::endl;
    }

    // Replace or remove a value
    int indexToModify;
    char choice;
    std::cout << "Enter the index to replace or remove: ";
    std::cin >> indexToModify;

    std::cout << "Enter 'r' to replace with 0 or 'd' to remove the integer: ";
    std::cin >> choice;

    bool success = false;
    try {
        if (choice == 'r') {
            success = replaceOrRemoveValue(arr, size, indexToModify, true);
            if (success) {
                std::cout << "Value at index " << indexToModify << " replaced with 0." << std::endl;
            }
        } else if (choice == 'd') {
            success = replaceOrRemoveValue(arr, size, indexToModify, false);
            if (success) {
                std::cout << "Integer at index " << indexToModify << " removed." << std::endl;
            }
        } else {
            std::cerr << "Invalid choice. Please enter 'r' or 'd'." << std::endl;
        }
    } catch (const std::out_of_range& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "An unexpected error occurred." << std::endl;
    }

    // Optional: Print the updated array
    std::cout << "Updated array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
*/




#include <iostream>
#include <fstream>
#include <stdexcept> // For std::invalid_argument, std::out_of_range, std::overflow_error

const int MAX_SIZE = 100;  // Define a maximum size for the array

// Function to read integers from a file into an array
int readDataFromFile(const std::string& filename, int arr[], int maxSize) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 0; // Return 0 to indicate an error
    }

    int count = 0;
    while (file >> arr[count] && count < maxSize) {
        ++count;
    }

    file.close();
    return count; // Return the number of elements read
}

// Function to check if a certain integer exists in the array
int findIntegerInArray(const int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function to modify the value at a specific index
bool modifyValueInArray(int arr[], int size, int index, int newValue, int &oldValue) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds."); // Throw exception if index is out of bounds
    }
    oldValue = arr[index]; // Store the old value
    arr[index] = newValue; // Update the value
    return true; // Return true to indicate success
}

// Function to add a new integer to the end of the array
bool addIntegerToArray(int arr[], int &size, int newValue, int maxSize) {
    if (size >= maxSize) {
        throw std::overflow_error("Array is full. Cannot add new value."); // Throw exception if the array is full
    }
    arr[size] = newValue; // Add the new value to the end of the array
    ++size; // Increment the size
    return true; // Return true to indicate success
}

// Function to replace or remove the value at a specific index
bool replaceOrRemoveValue(int arr[], int &size, int index, bool replaceWithZero) {
    if (index < 0 || index >= size) {
        return false; // Return false if index is out of bounds
    }
    if (replaceWithZero) {
        arr[index] = 0; // Replace the value at the index with 0
    } else {
        // Shift elements to the left to remove the element at index
        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --size; // Decrease the size of the array
    }
    return true; // Return true to indicate success
}

int main() {
    int arr[MAX_SIZE];
    int size;

    // Input file name
    std::string filename = "input.txt";

    // Read data from the file
    size = readDataFromFile(filename, arr, MAX_SIZE);
    if (size == 0) {
        std::cerr << "No data read or file could not be opened." << std::endl;
        return 1;
    }

    // Input integer to search for
    int target;
    std::cout << "Enter the integer to search for: ";
    std::cin >> target;

    // Find the integer in the array
    int index = findIntegerInArray(arr, size, target);
    if (index != -1) {
        std::cout << "Integer " << target << " found at index " << index << "." << std::endl;

        // Modify the value at the found index with exception handling
        int newValue;
        int oldValue;
        try {
            std::cout << "Enter the new value for index " << index << ": ";
            std::cin >> newValue;

            if (modifyValueInArray(arr, size, index, newValue, oldValue)) {
                std::cout << "Value at index " << index << " changed from " << oldValue << " to " << newValue << "." << std::endl;
            }
        } catch (const std::out_of_range& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        } catch (...) {
            std::cerr << "An unexpected error occurred." << std::endl;
        }
    } else {
        std::cout << "Integer " << target << " not found in the array." << std::endl;
    }

    // Add a new integer to the end of the array with exception handling
    int newInt;
    std::cout << "Enter a new integer to add to the array: ";
    std::cin >> newInt;

    try {
        if (addIntegerToArray(arr, size, newInt, MAX_SIZE)) {
            std::cout << "Integer " << newInt << " added to the end of the array." << std::endl;
        }
    } catch (const std::overflow_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "An unexpected error occurred." << std::endl;
    }

    // Replace or remove a value with exception handling
    int indexToModify;
    char choice;
    std::cout << "Enter the index to replace or remove: ";
    std::cin >> indexToModify;

    std::cout << "Enter 'r' to replace with 0 or 'd' to remove the integer: ";
    std::cin >> choice;

    bool success = false;
    try {
        if (choice == 'r') {
            success = replaceOrRemoveValue(arr, size, indexToModify, true);
            if (success) {
                std::cout << "Value at index " << indexToModify << " replaced with 0." << std::endl;
            }
        } else if (choice == 'd') {
            success = replaceOrRemoveValue(arr, size, indexToModify, false);
            if (success) {
                std::cout << "Integer at index " << indexToModify << " removed." << std::endl;
            }
        } else {
            std::cerr << "Invalid choice. Please enter 'r' or 'd'." << std::endl;
        }
    } catch (const std::out_of_range& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "An unexpected error occurred." << std::endl;
    }

    // Optional: Print the updated array
    std::cout << "Updated array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}




