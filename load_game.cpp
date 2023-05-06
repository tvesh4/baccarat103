#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "detect_invalid_input.h"
#include "load_game.h"
using namespace std;

void load_game(double status[], string &file_name){
    ifstream load;
    load.open("gameFiles.txt");
    if (load.fail()){
        cout << "Error in opening the file!" << endl;
    }
    double choice;
    int count=0;
    string name;
    vector<string> names;  // Vector is used as it has a dynamic size to store the variable numbers of game files created by the user
    while(getline(load, name))
    {
        count++;
        cout << count << " " << name << endl;
        names.push_back(name);
    }
    detect_invalid_input("Choose the game file you want to load: ", "Invalid choice.", choice);
    while (true){
        if (choice>0 && choice<=names.size()){
            file_name = names[choice-1];
            break;
        }
        else{
            cout << "Invalid choice." << endl;
            detect_invalid_input("Choose the game file you want to load: ", "Invalid choice.", choice);
        }
    }
    load.close();
    names.clear(); // Size of the vector "names" is set to 0
    vector<string>().swap(names); // Capacity of the vector "names" is set to 0 as well to release the memory completely.
    file_name.append(".txt");
    string line, datum;
    load.open(file_name.c_str());
    if (load.fail()){
        cout << "Error in opening the file!" << endl;
    }
    count = 0;
    while (getline(load, line)){
        istringstream data(line);
        while (data >> datum){
            if (count == 0){
                int int0 = stoi(datum); // convert the datum (string type) to int
                status[0] = int0; // retrieve the initial money set by the user from the loaded file
            }
            else if (count == 1){
                int int1 = stoi(datum);
                status[1] = int1; // retrieve the current balance from the loaded file
            }
            else if (count == 2){
                int int2 = stoi(datum);
                status[2] = int2; // retrieve the total number of games played from the loaded file
            }
            else if (count == 3){
                int int3 = stoi(datum);
                status[3] = int3; // retrieve the number of wins from the loaded file
            }
            else if (count == 4){
                double double4 = stod(datum);
                status[4] = double4; // retrieve the winning rate from the loaded file
            }
            count++;
        }
    }
    load.close();
}
