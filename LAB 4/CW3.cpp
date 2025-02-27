#include <iostream>
#include <stdexcept> // For std::out_of_range

class DynamicArray {
private:
    int* arr;   // Pointer to the dynamically allocated array
    int len;    // The size of the array

public:
    // Default constructor: initializes an empty array
    DynamicArray() : arr(nullptr), len(0) {}

    // Parameterized constructor: creates an array of size n, initialized to 0
    DynamicArray(int n) : len(n) {
        if (n > 0) {
            arr = new int[n](); // Allocate memory and default-initialize to 0
        } else {
            arr = nullptr;
        }
    }

    // Copy constructor: deep copy
    DynamicArray(const DynamicArray& other) : len(other.len) {
        if (len > 0) {
            arr = new int[len]; // Allocate memory for the new array
            for (int i = 0; i < len; ++i) {
                arr[i] = other.arr[i]; // Copy data
            }
        } else {
            arr = nullptr;
        }
    }

    // Move constructor: transfers ownership of the array
    DynamicArray(DynamicArray&& other) noexcept : arr(other.arr), len(other.len) {
        other.arr = nullptr;  // Leave the moved-from object in a valid state
        other.len = 0;
    }

    // Copy assignment operator: deep copy
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {  // Self-assignment check
            delete[] arr;  // Deallocate any existing memory

            len = other.len;
            if (len > 0) {
                arr = new int[len];  // Allocate new memory
                for (int i = 0; i < len; ++i) {
                    arr[i] = other.arr[i];  // Copy data
                }
            } else {
                arr = nullptr;
            }
        }
        return *this;
    }

    // Move assignment operator: transfers ownership of the array
    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {  // Self-assignment check
            delete[] arr;  // Deallocate any existing memory

            arr = other.arr;   // Transfer ownership
            len = other.len;
            other.arr = nullptr;  // Leave the moved-from object in a valid state
            other.len = 0;
        }
        return *this;
    }

    // Destructor: deallocates the dynamic array
    ~DynamicArray() {
        delete[] arr;
    }

    // Member function to return the current size of the array
    int size() const {
        return len;
    }

    // Member function to access elements with bounds checking
    int& at(int index) {
        if (index < 0 || index >= len) {
            throw std::out_of_range("Index out of range.");
        }
        return arr[index];
    }

    const int& at(int index) const {
        if (index < 0 || index >= len) {
            throw std::out_of_range("Index out of range.");
        }
        return arr[index];
    }

    // Member function to resize the dynamic array
    void resize(int newSize) {
        if (newSize == len) return;  // No change if the size is the same

        int* newArr = nullptr;
        if (newSize > 0) {
            newArr = new int[newSize]();  // Allocate new memory with default initialization
            for (int i = 0; i < std::min(len, newSize); ++i) {
                newArr[i] = arr[i];  // Copy old data
            }
        }

        // Deallocate the old array
        delete[] arr;
        arr = newArr;
        len = newSize;
    }
};

// Sample usage
int main() {
    DynamicArray arr1(5); // Create an array of size 5

    // Fill the array with values
    for (int i = 0; i < arr1.size(); ++i) {
        arr1.at(i) = i * 2;  // Assign values: 0, 2, 4, 6, 8
    }

    // Print values
    std::cout << "Array elements: ";
    for (int i = 0; i < arr1.size(); ++i) {
        std::cout << arr1.at(i) << " ";  // Output: 0 2 4 6 8
    }
    std::cout << std::endl;

    // Test copy constructor
    DynamicArray arr2 = arr1;  // Copy constructor
    std::cout << "Copied array elements: ";
    for (int i = 0; i < arr2.size(); ++i) {
        std::cout << arr2.at(i) << " ";  // Output: 0 2 4 6 8
    }
    std::cout << std::endl;

    // Test move constructor
    DynamicArray arr3 = std::move(arr1);  // Move constructor
    std::cout << "Moved array elements: ";
    for (int i = 0; i < arr3.size(); ++i) {
        std::cout << arr3.at(i) << " ";  // Output: 0 2 4 6 8
    }
    std::cout << std::endl;

    // Test resize
    arr3.resize(7);  // Resize to 7
    std::cout << "Resized array elements: ";
    for (int i = 0; i < arr3.size(); ++i) {
        std::cout << arr3.at(i) << " ";  // Output: 0 2 4 6 8 0 0
    }
    std::cout << std::endl;

    return 0;
}

