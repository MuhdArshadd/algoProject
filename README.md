## Employee Management System

This C++ program is designed to manage employee data, allowing users to perform various operations such as sorting, searching, displaying, and calculating employee ages and salaries. The system reads employee data from a file and provides a menu-driven interface for interacting with the data.

### Features

1. **Display Employee Data**
   - Displays the current employee data.

2. **Reset Sorted Data**
   - Resets the employee data to its original state by reading from the file again.

3. **Selection Sort**
   - Sorts the employee data by either SSN or salary in ascending order using the Selection Sort algorithm.

4. **Merge Sort**
   - Sorts the employee data by either SSN or salary in ascending order using the Merge Sort algorithm.

5. **Binary Search**
   - Performs a binary search to find employees by SSN. Data must be sorted by SSN before using this feature.

6. **Linear Search**
   - Performs a linear search to find employees by SSN.

7. **Improved Linear Search**
   - Performs an improved linear search to find employees by SSN.

8. **Calculate and Show Age**
   - Calculates and displays the age of each employee based on their birth date.

9. **Calculate Average Salary Earnings**
   - Calculates and displays the average salary of all employees.

### Data Structure

The program uses a struct `Employee` to store employee data, which includes:
- `ssn`: Social Security Number (integer)
- `name`: Name of the employee (string)
- `birthDate`: Birth date of the employee (string, in the format YYYY-MM-DD)
- `employedDate`: Employment date of the employee (string)
- `salary`: Salary of the employee (double)

### Functions

- **`void display(const Employee* emp)`**
  - Displays the first 100 employees' data.

- **`void selectionSort(Employee* emp, int size, int choice)`**
  - Sorts employees by SSN or salary using the Selection Sort algorithm.

- **`void mergeSortController(Employee* emp, int size, int choice)`**
  - Initiates the Merge Sort process.

- **`void mergeSort(Employee* emp, int left, int right, Employee* temp, int& mergeCounter, int& mergeInversion, int choice)`**
  - Recursive Merge Sort function.

- **`void merge(Employee* emp, int left, int mid, int right, Employee* temp, int& mergeCounter, int& mergeInversion, int choice)`**
  - Merges two sorted halves.

- **`int binarySearch(const Employee* arr, int start, int last, int targetId)`**
  - Performs a binary search on the employee array by SSN.

- **`int linearSearch(Employee* arr, int size, int targetId)`**
  - Performs a linear search on the employee array by SSN.

- **`int improvedLinearSearch(Employee* arr, int size, int targetId)`**
  - Performs an improved linear search on the employee array by SSN.

- **`int calculateAge(const string& birthDate)`**
  - Calculates the age of an employee based on their birth date.

- **`void displayAge(Employee* temp, int size)`**
  - Displays the age of each employee.

- **`void totalSalary(Employee* temp, int size)`**
  - Calculates and displays the total and average salary of all employees.

- **`void readDataFromFile(Employee* emp, int size)`**
  - Reads employee data from the file.

### User Interface

The program uses a simple command-line interface to interact with the user. The main menu provides options to display data, reset data, perform sorting and searching operations, calculate ages, and calculate average salaries.

### Requirements

- C++ compiler
- `conio.h` header for capturing key presses (may require adjustments for non-Windows systems)
- Data file `employee_data.csv` in the same directory as the executable

### Running the Program

1. Ensure the `employee_data.csv` file is in the same directory as the executable.
2. Compile the program using a C++ compiler.
3. Run the executable.
4. Use the arrow keys to navigate the menu and press Enter to select an option.

### Notes

- The program uses a fixed array size of 10000 for storing employee data. Adjust the size if needed.
- Ensure the data file follows the expected format to avoid read errors.
