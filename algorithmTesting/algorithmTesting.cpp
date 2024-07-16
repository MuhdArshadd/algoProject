#include <iostream>
#include <iomanip>
#include <chrono>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <random>
#include <ctime>
#include <sstream>
#pragma warning(disable : 4996)
using namespace std;
struct Employee {
	int ssn;
	string name;
	string birthDate;
	string employedDate;
	double salary;
};
void display(const Employee* emp);
void selectionSort(Employee* emp, int size, int choice);
void readDataFromFile(Employee* emp, int size);
void merge(Employee* emp, int left, int mid, int right, Employee* temp, int& mergeCounter, int& mergeInversion, int choice);
void mergeSort(Employee* emp, int left, int right, Employee* temp, int& mergeCounter, int& mergeInversion, int choice);
void mergeSortController(Employee* emp, int size, int choice);
int binarySearch(const Employee* arr, int start, int last, int targetId);
int linearSearch(Employee* arr, int size, int targetId);
int improvedLinearSearch(Employee* arr, int size, int targetId);
int calculateAge(const string& birthDate);
void displayAge(Employee* temp, int size);
void totalSalary(Employee* temp, int size);
int calculateAverage(int total, int size);
int main()
{
	//extract dr excell
	const int size = 10000;
	const int numberOfRandomIds = 100;
	const int lowerBound = 100000;
	const int upperBound = 200000;
	Employee* emp = new Employee[size];
	readDataFromFile(emp, size);
	const int numOptions = 9;
	int option = 0;
	int sortedSSN = 0;
	int sortedSalary = 0;
	while (true)
	{
		system("cls");
		cout << "===========================================" << endl;
		cout << " Welcome to Main Menu" << endl << endl;
		cout << "===========================================" << endl;
		for (int i = 0; i < numOptions; i++)
		{
			if (i == option)
			{
				cout << "->";
			}
			else
			{
				cout << " ";
			}
			if (i == 0)
			{
				cout << "\tDisplay Current Data" << endl;
			}
			else if (i == 1)
			{
				cout << "\tReset Sorted Data" << endl;
			}
			else if (i == 2)
			{
				cout << "\tSelection Sort" << endl;
			}
			else if (i == 3)
			{
				cout << "\tMerge Sort" << endl;
			}
			else if (i == 4)
			{
				cout << "\tBinary Search" << endl;
			}
			else if (i == 5)
			{
				cout << "\tLinear Search" << endl;
			}
			else if (i == 6)
			{
				cout << "\tImproved Linear Search" << endl;
			}
			else if (i == 7)
			{
				cout << "\tCalculate and Show Age" << endl;
			}
			else if (i == 8)
			{
				cout << "\tCalculate Average Salary Earnings" << endl;
			}
			else if (i == 9)
			{
				cout << "\tExit " << endl;
			}
		}
		cout << "=========================================== " << endl;
		char input = _getch();
		switch (input)
		{
		case 72:
			option = (option - 1 + numOptions) % numOptions;
			break;
		case 80:
			option = (option + 1) % numOptions;
			break;
		case 13:
			system("cls");
			if (option == 0)
			{
				display(emp);
				system("pause");
			}
			else if (option == 1)
			{
				sortedSalary = 0;
				sortedSSN = 0;
				readDataFromFile(emp, size);
				cout << "Data Has Been Reset " << endl << endl;
				system("pause");
			}
			else if (option == 2)
			{
				const int numOptions = 3;
				int option = 0;
				int back = 0;
				while (back == 0)
				{
					system("cls");
					cout << "=====================================" << endl;
					cout << " Select Selection Sort Choice" << endl << endl;
					cout << "=====================================" << endl;
					for (int i = 0; i < numOptions; i++)
					{
						if (i == option)
						{
							cout << "->";
						}
						else
						{
							cout << " ";
						}
						if (i == 0)
						{
							cout << "\tSort by SSN (ascending)" << endl;
						}
						else if (i == 1)
						{
							cout << "\tSort by Salary (ascending)" << endl;
						}
						else if (i == 2)
						{
							cout << "\tBack " << endl;
						}
					}
					cout << "=====================================" << endl;
					char input = _getch();
					switch (input)
					{
					case 72:
						option = (option - 1 + numOptions) % numOptions;
						break;
					case 80:
						option = (option + 1) % numOptions;
						break;
					case 13:
						system("cls");
						if (option == 0)
						{
							if (sortedSSN == 0)
							{
								selectionSort(emp, size, 1);
								sortedSSN = 1;
								sortedSalary = 0;
							}
							else
								cout << "PLEASE RESET DATA FIRST !" << endl;
							system("pause");
							back = 1;
						}
						else if (option == 1)
						{
							if (sortedSalary == 0)
							{
								selectionSort(emp, size, 2);
								sortedSalary = 1;
								sortedSSN = 0;
							}
							else
								cout << "PLEASE RESET DATA FIRST !" << endl;
							system("pause");
							back = 1;
						}
						else if (option == 2)
						{
							back = 1;
						}
						break;
					}
				}
			}
			else if (option == 3)
			{
				const int numOptions = 3;
				int option = 0;
				int back = 0;
				while (back == 0)
				{
					system("cls");
					cout << "=====================================" << endl;
					cout << " Select Merge Sort Choice" << endl << endl;
					cout << "=====================================" << endl;
					for (int i = 0; i < numOptions; i++)
					{
						if (i == option)
						{
							cout << "->";
						}
						else
						{
							cout << " ";
						}
						if (i == 0)
						{
							cout << "\tSort by SSN (ascending)" << endl;
						}
						else if (i == 1)
						{
							cout << "\tSort by Salary (ascending)" << endl;
						}
						else if (i == 2)
						{
							cout << "\tBack " << endl;
						}
					}
					cout << "=====================================" << endl;
					char input = _getch();
					switch (input)
					{
					case 72:
						option = (option - 1 + numOptions) % numOptions;
						break;
					case 80:
						option = (option + 1) % numOptions;
						break;
					case 13:
						system("cls");
						if (option == 0)
						{
							if (sortedSSN == 0)
							{
								mergeSortController(emp, size, 1);
								sortedSSN = 1;
								sortedSalary = 0;
							}
							else
								cout << "PLEASE RESET DATA FIRST !" << endl;
							system("pause");
							back = 1;
						}
						else if (option == 1)
						{
							if (sortedSalary == 0)
							{
								mergeSortController(emp, size, 2);
								sortedSalary = 1;
								sortedSSN = 0;
							}
							else
								cout << "PLEASE RESET DATA FIRST !" << endl;
							system("pause");
							back = 1;
						}
						else if (option == 2)
						{
							back = 1;
						}
						break;
					}
				}
			}
			else if (option == 4)
			{
				// Seed the random number generator
				random_device rd;
				mt19937 gen(rd());
				uniform_int_distribution<int> distribution(lowerBound, upperBound);
				//1st search
				if (sortedSSN == 1) {
					auto start = chrono::high_resolution_clock::now();
					for (int i = 0; i < numberOfRandomIds; ++i) {
						int randomId = distribution(gen);//generated id number
						int index = binarySearch(emp, 0, size - 1, randomId);
						if (index != -1) {
							cout << "Random ID " << randomId << " found at index " << index << endl;
						}
						else {
							cout << "Random ID " << randomId << " not found" << endl;
						}
					}
					auto end = chrono::high_resolution_clock::now();
					chrono::duration<double> duration = end - start;
					double timeTaken = duration.count();
					cout << "Time taken for search is " << fixed << setprecision(5) << timeTaken << " seconds." << endl;
					system("pause");
				}
				else {
					cout << "PLEASE SORT THE DATA BY SSN IN ASCENDING ORDER FIRST!" << endl;
					system("pause");
				}
			}
			else if (option == 5)
			{
				// Seed the random number generator
				random_device rd;
				mt19937 gen(rd());
				uniform_int_distribution<int> distribution(lowerBound, upperBound);
				//2nd search
				if (sortedSSN == 1) {
					auto start = chrono::high_resolution_clock::now();
					for (int i = 0; i < numberOfRandomIds; ++i) {
						int randomId = distribution(gen); //generated id number
						int index = linearSearch(emp, size, randomId);
						if (index != -1) {
							cout << "Random ID " << randomId << " found at index " << index << endl;
						}
						else {
							cout << "Random ID " << randomId << " not found" << endl;
						}
					}
					auto end = chrono::high_resolution_clock::now();
					chrono::duration<double> duration = end - start;
					double timeTaken = duration.count();
					cout << "Time taken for search is " << fixed << setprecision(5) << timeTaken << " seconds." << endl;
					system("pause");
				}
				else {
					cout << "PLEASE SORT THE DATA BY SSN IN ASCENDING ORDER FIRST!" << endl;
					system("pause");
				}
			}
			else if (option == 6)
			{
				// Seed the random number generator
				random_device rd;
				mt19937 gen(rd());
				uniform_int_distribution<int> distribution(lowerBound, upperBound);
				//2nd search
				if (sortedSSN == 1) {
					auto start = chrono::high_resolution_clock::now();
					for (int i = 0; i < numberOfRandomIds; ++i) {
						int randomId = distribution(gen); //generated id number
						int index = improvedLinearSearch(emp, size, randomId);
						if (index != -1) {
							cout << "Random ID " << randomId << " found at index " << index << endl;
						}
						else {
							cout << "Random ID " << randomId << " not found" << endl;
						}
					}
					auto end = chrono::high_resolution_clock::now();
					chrono::duration<double> duration = end - start;
					double timeTaken = duration.count();
					cout << "Time taken for search is " << fixed << setprecision(5) << timeTaken << " seconds." << endl;
					system("pause");
				}
				else {
				}
			}
			else if (option == 7)
			{
				displayAge(emp, size);
				system("pause");
			}
			else if (option == 8)
			{
				totalSalary(emp, size);
				system("pause");
			}
			else if (option == 9)
			{
				exit(99);
			}
			break;
		}
	}
	delete[] emp;
}
void readDataFromFile(Employee* emp, int size) {
	ifstream inputFile("employee_data.csv");
	if (!inputFile.is_open()) {
		cerr << "Error opening the file." << endl;
		exit(1);
	}
	// Skip the header line
	string header;
	getline(inputFile, header);
	for (int i = 0; i < size; ++i) {
		inputFile >> emp[i].ssn;
		inputFile.ignore(); // Ignore the comma
		getline(inputFile, emp[i].name, ',');
		getline(inputFile, emp[i].birthDate, ',');
		getline(inputFile, emp[i].employedDate, ',');
		inputFile >> emp[i].salary;
		// Skip the newline character at the end of each line
		inputFile.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	inputFile.close();
}
void display(const Employee* emp) {
	cout << "========================================================" << endl;
	cout << " EMPLOYEE DETAILS " << endl;
	cout << "========================================================" << endl;
	cout << setw(12) << left << "|EmployeeSSN"
		<< setw(11) << "|Name"
		<< setw(11) << "|Birth Date"
		<< setw(14) << "|Employed Date"
		<< setw(7) << "|Salary|" << endl;
	for (int i = 0; i < 100; i++) {
		cout << "========================================================" << endl;
		cout << "|" << setw(11) << emp[i].ssn
			<< "|" << setw(10) << emp[i].name
			<< "|" << setw(10) << emp[i].birthDate
			<< "|" << setw(13) << emp[i].employedDate
			<< "|" << fixed << setprecision(0) << setw(6) << emp[i].salary << "|" << endl;
	}
	cout << "========================================================" << endl;
}
void selectionSort(Employee* emp, int size, int choice) { // this function accept array of struct employee , together with the size of index and choice of sort either ssn or salary
	int i, j, imin, swapCounter = 0; // variable declaratio
	auto start = chrono::high_resolution_clock::now(); // to start the time for sorting
	if (choice == 1) // by ssn
	{
		for (i = 0; i < size - 1; i++) { // this loop will try to sort until the second last of the index
			imin = i; // the start of index meaning the first element
			for (j = i + 1; j < size; j++) // the second element will sort until last of index
				if (emp[j].ssn < emp[imin].ssn) // if the before is bigger than the next
					imin = j; // then the new i min will be the index of j
			if (emp[i].ssn != emp[imin].ssn) {
				swapCounter++;
			}
			Employee tempSwap = emp[i];
			emp[i] = emp[imin];
			emp[imin] = tempSwap;
		}
	}
	else
	{
		for (i = 0; i < size - 1; i++) {
			imin = i;
			for (j = i + 1; j < size; j++)
				if (emp[j].salary < emp[imin].salary)
					imin = j;
			if (emp[i].ssn != emp[imin].ssn) {
				swapCounter++;
			}
			Employee tempSwap = emp[i];
			emp[i] = emp[imin];
			emp[imin] = tempSwap;
		}
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> duration = end - start;
	double timeTaken = duration.count();
	cout << "After sorting by ID in ascending order:" << endl;
	display(emp);
	cout << "Number of swaps: " << swapCounter << endl;
	cout << "Time taken for sorting is " << fixed << setprecision(5) << timeTaken << " seconds." << endl;
}
void merge(Employee* emp, int left, int mid, int right, Employee* temp, int& mergeCounter, int& mergeInversion, int choice) {
	mergeCounter++;
	int i = left;
	int j = mid + 1;
	int k = left;
	if (choice == 1)
	{
		while (i <= mid && j <= right) {
			if (emp[i].ssn <= emp[j].ssn) {
				temp[k++] = emp[i++];
			}
			else {
				temp[k++] = emp[j++];
				mergeInversion += (mid - i + 1); // Count the number of inversions
			}
		}
	}
	else
	{
		while (i <= mid && j <= right) {
			if (emp[i].salary <= emp[j].salary) {
				temp[k++] = emp[i++];
			}
			else {
				temp[k++] = emp[j++];
				mergeInversion += (mid - i + 1); // Count the number of inversions
			}
		}
	}
	while (i <= mid) {
		temp[k++] = emp[i++];
	}
	while (j <= right) {
		temp[k++] = emp[j++];
	}
	for (i = left; i <= right; i++) {
		emp[i] = temp[i];
	}
}
void mergeSort(Employee* emp, int left, int right, Employee* temp, int& mergeCounter, int& mergeInversion, int choice) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(emp, left, mid, temp, mergeCounter, mergeInversion, choice);
		mergeSort(emp, mid + 1, right, temp, mergeCounter, mergeInversion, choice);
		merge(emp, left, mid, right, temp, mergeCounter, mergeInversion, choice);
	}
}
void mergeSortController(Employee* emp, int size, int choice) {
	Employee* temp = new Employee[size];
	int mergeCounter = 0, mergeInversion = 0;
	auto start = chrono::high_resolution_clock::now();
	mergeSort(emp, 0, size - 1, temp, mergeCounter, mergeInversion, choice);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> duration = end - start;
	double timeTaken = duration.count();
	cout << "After sorting by ID in ascending order:" << endl;
	display(emp);
	cout << "Number of inversions : " << mergeInversion << endl;
	cout << "Number of merge : " << mergeCounter << endl;
	cout << "Time taken for sorting is " << fixed << setprecision(5) << timeTaken << " seconds." << endl;
	delete[] temp;
}
int binarySearch(const Employee* arr, int start, int last, int targetId) {
	while (start <= last) {
		int mid = (start + last) / 2;
		if (arr[mid].ssn == targetId)
			return mid;
		if (arr[mid].ssn < targetId)
			start = mid + 1;
		else
			last = mid - 1;
	}
	return -1;
}
// Linear search function
int linearSearch(Employee* arr, int size, int targetId) {
	int result = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i].ssn == targetId)
			result = arr[i].ssn;
	}
	if (result == 0) {
		// Target not present in array
		return -1;
	}
	else {
		return result;
	}
}
//improved linear search
int improvedLinearSearch(Employee* arr, int size, int targetId) {
	// Save the last element's SSN and replace it with the targetId
	int lastSsn = arr[size - 1].ssn;
	arr[size - 1].ssn = targetId;
	// Start the search with the targetId
	int i = 0;
	while (arr[i].ssn != targetId) {
		++i;
	}
	// Restore the last element's SSN
	arr[size - 1].ssn = lastSsn;
	// If we found the targetId before reaching the last element, return the index
	if (i < size - 1) {
		return i;
	}
	// Target not present in array
	return -1;
}
int calculateAge(const std::string& birthDate) {
	// Get the current time
	tm birthDate1 = {};
	istringstream ss(birthDate);
	ss >> get_time(&birthDate1, "%Y-%m-%d");
	// Get the current date
	auto currentTime = chrono::system_clock::now();
	time_t now = chrono::system_clock::to_time_t(currentTime);
	tm* currentTM = localtime(&now);
	// Calculate the age
	int age = currentTM->tm_year - birthDate1.tm_year;
	// Adjust for the case where the birthday hasn't occurred yet this year
	if (currentTM->tm_mon < birthDate1.tm_mon || (currentTM->tm_mon == birthDate1.tm_mon && currentTM->tm_mday < birthDate1.tm_mday)) {
		age--;
	}
	// Output age
	return age;
}
void displayAge(Employee* emp, int size) {
	cout << "=======================================" << endl;
	cout << " EMPLOYEE DETAILS " << endl;
	cout << "=======================================" << endl;
	cout << setw(12) << left << "|EmployeeSSN"
		<< setw(11) << "|Name"
		<< setw(11) << "|Birth Date"
		<< setw(5) << "|Age|" << endl;
	int age;
	for (int i = 0; i < 100; i++) {
		age = calculateAge(emp[i].birthDate);
		cout << "=======================================" << endl;
		cout << "|" << setw(11) << emp[i].ssn
			<< "|" << setw(10) << emp[i].name
			<< "|" << setw(10) << emp[i].birthDate
			<< "|" << setw(3) << age << "|" << endl;
	}
	cout << "=======================================" << endl << endl;
}
void totalSalary(Employee* emp, int size) {
	int total = 0;
	for (int i = 0; i < size; i++) {
		total = total + emp[i].salary;
	}
	cout << endl << "Average salary is RM " << calculateAverage(total, size) << endl;
}
int calculateAverage(int total, int size) {
	return total / size;
}