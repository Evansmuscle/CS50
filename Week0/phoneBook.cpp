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

int main(int argc, char const *argv[])
{
    int idx = 0;

    int phoneNumbers[9] = {0, 1, 2 ,3, 4, 5, 6, 7 ,8};
    int min = 0;
    int max = sizeof(phoneNumbers) / sizeof(phoneNumbers[0]);
    int half;
    int searchNumber;
    
    cout << "Please enter a phone number you want to search for" << endl;
    cin >> searchNumber;
    
    // Number Found With Naive Way
    // int foundPhone = findPhone(phoneNumbers, 4, idx);
    
    // The Efficient Halving Way With A BigO of Log2n
    for (int i = 0; i < max; i++)
    {
        half = floor((max - min) / 2);
        cout << to_string(max) + "-" + to_string(min) << endl;

        if (phoneNumbers[half] == searchNumber)
        {
            cout << "Number found! It was on index: " + i << endl;
            cout << "Please enter any input to exit the program." << endl;
            cin >> idx;
            return 0;
        }
        
        if (phoneNumbers[half] <= searchNumber)
        {
            min = half;
            continue;
        }
        
        if (phoneNumbers[half] >= searchNumber)
        {
            max = half;
            continue;
        }
    }
    
    cout << "Number was not found!" << endl;
    throw 505;
}
