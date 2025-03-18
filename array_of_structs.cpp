// Luis Amaro, Adrian Romero
#include <iostream>
#include <fstream>
using namespace std;


// TODO: Step 1 - Define the struct TemperatureRecord
// It should contain two integer fields: day and temperature.
struct TemperatureRecord
{
    int day;
    int temperature;
};

// Constants
const int MAX_DAYS = 31;

// Function Prototypes
void readTemperatures(TemperatureRecord arr[MAX_DAYS], int& size); // TODO: Fix the parameters
void printTemperatures(const TemperatureRecord arr[], int& size);
//TemperatureRecord findMin(const TemperatureRecord arr[], int& size);
//TemperatureRecord findMax(const TemperatureRecord arr[], int& size);
double findAverage(const TemperatureRecord arr[], int& size);

int main() {
    // TODO: Step 2 - Declare an array of TemperatureRecord structs (MAX_DAYS size)
    TemperatureRecord arr[MAX_DAYS]{};
    int size = 0;  // Actual number of records read
    
    // TODO: Step 3 - Call readTemperatures() to load data from file
    readTemperatures(arr, size);
    // TODO: Step 4 - Print the temperatures
    printTemperatures(arr, size);
    // TODO: Step 5 - Compute and display min, max, and average temperature
    //findMin();
    //findMax();
    findAverage(arr, size);
    
    return 0;
}

// TODO: Step 6 - Implement readTemperatures()
// Read from "temps.txt" and store data in the array

void readTemperatures(TemperatureRecord arr[MAX_DAYS], int& size)
{
    ifstream dataIn;
    dataIn.open("temps.dat");
    if (!dataIn)
        cout << "Error\n\n";
    
    while (size < MAX_DAYS && dataIn >> arr[size].day >> arr[size].temperature)
    {
        size++;
    }
    dataIn.close();
}

// TODO: Step 7 - Implement printTemperatures()
// Print all stored temperatures in a formatted table
void printTemperatures(const TemperatureRecord arr[], int& size)
{
    int i;
    cout << "Day            Temp\n"
        << "-------------------\n";
    for (i = 0; i < size; i++)
    {
        cout << arr[i].day << "             " 
            << arr[i].temperature << endl << endl;
    }
}
// TODO: Step 8 - Implement findMin()
// Return the TemperatureRecord with the lowest temperature

// TODO: Step 9 - Implement findMax()
// Return the TemperatureRecord with the highest temperature

// TODO: Step 10 - Implement findAverage()
// Compute and return the average temperature
double findAverage(const TemperatureRecord arr[], int& size)
{
    int i;
    double average, sum = 0;
    for (i = 0; i < size; i++)
    {
        sum += arr[i].temperature;
    }
    average = sum / size;
    cout << "The average temperature is: " << average << endl;
    return average;
}