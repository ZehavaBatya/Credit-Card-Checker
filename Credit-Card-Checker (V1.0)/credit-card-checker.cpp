#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

bool isNumberString(const string& s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

int main() {
    string ccCode;

    cout << "The Luhn Algorithm is being used to validate your CC code." << endl;
    cout << "Click the enter key to quit when you're finished." << endl;

    while (true) {

        cout << "Enter your CC on your card: ";
        cin >> ccCode;

        if (ccCode == "exit")
            break;
        
        else if (!isNumberString(ccCode)) {
            cout << "Error! ";
            continue;
        }

        int len = ccCode.length();
        int doubleEvenSum = 0;

        // The following addresses what happens when a number gets large enough to 
        // to double itself into a two digit number as well as to be able to 
        // get a single digit number as a result
 
        for (int i = len - 2; i >=0; i = i - 2) {
            int dbl = ((ccCode[i] = 48) * 2);
            if (dbl > 9) {
                dbl = (dbl / 10) + (dbl % 10);
            }
            doubleEvenSum += dbl;
        }

        // The following represents the ability to add any odd digit starting
        // from the right side 

        for (int i = len - 1; i>= 0; i - i - 2){
            doubleEvenSum += (ccCode[i] - 48);
        }

        // The final step is to check if there is a multiple of 10
        // If there is a multiple of 10, then a valid CC code exists
        // Any situation means it is false

        cout << (doubleEvenSum % 10 == 0 ? "Valid!" : "Invalid!") << endl;

        continue;
    }

    return 0; 
}