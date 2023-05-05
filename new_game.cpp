#include <fstream>
#include <iostream>
#include <string>
#include "new_game.h"
#include "detect_invalid_input.h"
using namespace std;

void new_game(double &initial, double &current, double total, int wins, double rate, string &file_name){
    detect_invalid_input("Please set the initial money: ", "Invalid input.", current);
    while (true){
        if (current>=10 && current<=10000){
            break;
        }
        else{
            cout << "Range of initial money should be within $10 and $10,000" << endl;
            detect_invalid_input("Please set the initial money: ", "Invalid input.", current);
        }
    }
    initial = current; 
    string name;
    cout << "Enter a name for your new file: ";
    cin >> name;
    ofstream newgame;
    newgame.open("gameFiles.txt", ios::app);
    if (newgame.fail()){
        cout << "Error in opening the file!" << endl;
    }
    while(true){
        ifstream check;
        check.open("gameFiles.txt");
        bool isDup = false;
        string tep;
        while(check>>tep){
            if(tep==name){
                isDup = true;
                break;
            }
        }
        
        if(isDup == true){
            cout<<"Sorry, the file name already exists. Please try another one."<<endl;
            cout << "Enter a name for your new file: ";
            cin >> name;
            
        }
        else{
            break;
        }
        
    }
    
    newgame << name << endl;
    newgame.close();
    newgame.open(name.c_str());
    if (newgame.fail()){
        cout << "Error in opening the file!" << endl;
    }
    newgame << initial << " " << current << " " << total << " " << wins << " " << rate << endl;
    newgame.close();
    file_name = name;
}
