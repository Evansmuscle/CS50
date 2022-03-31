#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;


// The Naive Way of Looking The Phone Up
// int findPhone(int phoneNumbers[], int searchNumber, int idx) {
    
//     if (phoneNumbers[idx] == searchNumber)
//     {
//         return idx;
//     }
//     idx++;
//     return findPhone(phoneNumbers, searchNumber, idx);
// }

// Better Way
int findPhone(int max, int min, int phoneNumbers[], int searchNumber, int half) {
    // Half is the the middle most member of the array between min and max
    half = floor((max - min) / 2) + min;
    cout << "Max " + to_string(max) + " " + "Min " + to_string(min) << endl;

    // If we found then number, return it
    if (phoneNumbers[half] == searchNumber) {
        cout << "Number found! It was on index: " + to_string(half) << endl;
        cout << "Please enter any input to exit the program." << endl;
        cin >> half;
        return phoneNumbers[half];
    }
    
    // If half number is bigger than searched number, set minimum to half
    if (phoneNumbers[half] < searchNumber) {
        min = half;
        return findPhone(max, min, phoneNumbers, searchNumber, half);
    }
    
    // If half number is smaller than searched number, set max to half
    max = half;
    return findPhone(max, min, phoneNumbers, searchNumber, half);
}

int main(int argc, char const *argv[]) {
    int phoneNumbers[9] = {0, 1, 2 ,3, 4, 5, 6, 7 ,8};
    int min = 0;
    int max = sizeof(phoneNumbers) / sizeof(phoneNumbers[0]) - 1;
    int half;
    int searchNumber;
    
    cout << "Please enter a phone number you want to search for" << endl;
    cin >> searchNumber;
    
    // Number Found With Naive Way
    // int foundPhone = findPhone(phoneNumbers, 4, idx);
    
    // The Efficient Halving Way With A BigO of Log2n
    int foundPhone = findPhone(max, min, phoneNumbers, searchNumber, half);
    
    if (foundPhone) {
        return 0;
    } else {
        cout << "Number was not found!" << endl;
        throw 505;
    }
}
