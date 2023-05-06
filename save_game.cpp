#include <iostream>
#include <fstream>
#include <string>
#include "save_game.h"
using namespace std;

void save_game(double status[], string file_name){
    ofstream save;
    save.open(file_name.c_str());
    if (save.fail()){
        cout << "Error in opening the file!" << endl;
    }
    else{
        for (int i=0; i<5; i++){
            save << status[i] << " ";
        }
        save << endl;
    }
    cout << "Saving..." << endl;
    cout << "******************" << endl;
    cout << "Save Successful!" << endl;
    cout << "******************" << endl;
    save.close();
}
