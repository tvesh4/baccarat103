#include <iostream>
#include <fstream>
#include <string>
#include "save_game.h"
using namespace std;

void save_game(double initial, double current, double total, int wins, double rate, string file_name){
    ofstream save;
    save.open(file_name.c_str());
    if (save.fail()){
        cout << "Error in opening the file!" << endl;
    }
    else{
        save << initial << " " << current  << " " << total << " " << wins << " " << rate << endl;
    }
    cout << "Saving..." << endl;
    cout << "******************" << endl;
    cout << "Save Successful!" << endl;
    cout << "******************" << endl;
    save.close();
}
