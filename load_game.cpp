#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "detect_invalid_input.h"
#include "load_game.h"
using namespace std;

void load_game(double &initial, double &current, double &total, int &wins, double &rate, string &file_name){
    ifstream load;
    load.open("gameFiles.txt");
    if (load.fail()){
        cout << "Error in opening the file!" << endl;
    }
    double choice;
    int count=0;
    string name;
    vector<string> names;
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
    names.clear();
    string line, datum;
    load.open(file_name.c_str());
    if (load.fail()){
        cout << "Error in opening the file!" << endl;
    }
    count = 1;
    while (getline(load, line)){
        istringstream data(line);
        while (data >> datum){
            if (count == 1){
                int int1 = stoi(datum); // convert the datum (string type) to int
                initial = int1; // retrieve the initial money set by the user from the loaded file
            }
            else if (count == 2){
                int int2 = stoi(datum);
                current = int2; // retrieve the current balance from the loaded file
            }
            else if (count == 3){
                int int3 = stoi(datum);
                total = int3; // retrieve the total number of games played from the loaded file
            }
            else if (count == 4){
                int int4 = stoi(datum);
                wins = int4; // retrieve the number of wins from the loaded file
            }
            else if (count == 5){
                double double5 = stod(datum);
                rate = double5; // retrieve the winning rate from the loaded file
            }
            count++;
        }
    }
    load.close();
}
