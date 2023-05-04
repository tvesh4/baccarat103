#include <iostream>
#include <string>
#include "detect_invalid_input.h"
using namespace std;

void detect_invalid_input(string prompt, string message, double &data){
    while (cout << prompt && !(cin >> data)) {
        cin.clear(); //clear bad input flag
        cin.ignore(10000, '\n'); //discard input
        cout << message << endl;
    }
}
