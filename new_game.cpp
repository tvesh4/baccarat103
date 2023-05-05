//It checks that the input is within the range of $10 to $10,000. It then prompts the user to enter a name for the new file.

#include <fstream>
#include <iostream>
#include <string>
#include "new_game.h"
#include "detect_invalid_input.h"
using namespace std;

// This function is used to start a new game and save it to a file
void new_game(double &initial, double &current, double total, int wins, double rate, string &file_name){
    // Prompt the user to set the initial amount of money
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
    // Check for duplicate file names and prompt the user to enter a different name if necessary
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
    newgame.open(name.c_str()); // Write the game data to the new file
    if (newgame.fail()){
        cout << "Error in opening the file!" << endl;
    }
    newgame << initial << " " << current << " " << total << " " << wins << " " << rate << endl;
    newgame.close();
    file_name = name; // Set the file name to the user-provided name
}
