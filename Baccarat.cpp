//Includes several standard libraries and several header files, such as `iostream`, `iomanip`, `string`, `vector`, `algorithm`, `random`, `fstream`, `sstream`, and `cstdlib`. 
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "Card.h"
#include "detect_invalid_input.h"
#include "new_game.h"
#include "load_game.h"
#include "save_game.h"

//The `using namespace std;` statement is a directive that tells the compiler to use the `std` namespace. It contains several standard C++ functions and objects, without `std::`. 
using namespace std;

//Defined the `display()`, `message()`, and `showData()` functions without providing their implementations yet. 
void display(string);
void message(string, string, int, string);
void showData(double, double, double);

//Defines the `declareWinner()`, `checkWin()`, `drawThird()`, `bankDraw()`, and `play()` functions with their implementations. 
void declareWinner(short, short, short);
short checkWin(short, short, short);
bool drawThird(short);
bool bankDraw(short, short);
void play(double &, double &, int &, double &);

//Declares a constant named `LINE_LENGTH` with a value of 30 and a character variable named `LINE_SYMBOL` with a value of `*`.
const int LINE_LENGTH = 30;
const char LINE_SYMBOL = '*';

int main()
{
    double initial, money, total=0.0, rate=0; //rate is still in development.
    double choice;
    int wins=0;
    string file_name;
    ifstream file; //'ifstream' object is used to open a file. 
    file.open("gameFiles.txt");
    display("***** Welcome to Baccarat ****"); //display a welcome message
    if(file.fail()){ //to start a new game or load progress, the application first determines whether the file was successfully opened
        cout << "1. Start New Game" << endl;
        cout << "2. Load Progress (No Progress Detected)" << endl;
    }
    else{
        cout << "1. Start New Game" << endl;
        cout << "2. Load Progress" << endl;
    }
    
    detect_invalid_input("Enter your choice (1 or 2): ", "Invalid choice. Please enter 1 or 2.", choice);
    //continues running until the user selects a legitimate choice after the user's input is validated using the 'detect_invalid_input()' function.
    while (true){
        if (choice == 1){ //runs the 'new_game()' or 'load_game()' function as appropriate depending on whether the user wants to load their progress or begin a new game. 
            new_game(initial, money, total, wins, rate, file_name);
            break;
        } 
        else if ((choice == 2) &&!(file.fail())){
            load_game(initial, money, total, wins, rate, file_name);
            break;
        }
        else if ((choice == 2) && (file.fail())){
            cout << "Cannot Load Progress" << '\n' << "Reason: No progess detected" << endl;
            cout << "------------------------------" << endl;
            detect_invalid_input("Enter your choice (1 or 2): ", "Invalid choice. Please enter 1 or 2.", choice);
        }
        else{
            cout << "Invalid choice. Please enter 1 or 2." << endl;
            detect_invalid_input("Enter your choice (1 or 2): ", "Invalid choice. Please enter 1 or 2.", choice);
        }
    }

    while (true) { // 4 options are provided to the user.
        double choice;
        showData(initial, total, rate);
        cout << "Menu:" << std::endl;
        cout << "1. Start playing game" << std::endl;
        cout << "2. Check the balance" << std::endl;
        cout << "3. Save the game" << std::endl;
        cout << "4. Exit the game" << std::endl;
        detect_invalid_input("Enter your choice (1, 2, 3, or 4): ", "Invalid choice. Please enter 1, 2, 3 or 4.", choice);
        if (choice == 1) { //To begin playing, the program calls the "play()" function after once more validating the user's input. 
            cout << "Starting the game..." << endl;
            play(money, total, wins, rate);
            if (money < 10){
                cout << "You don't have enough money to bet anymore!" << endl;
                cout << "Would you like to restart? (1. Yes/ 2. No and Quit)" << endl;
                double decision;
                detect_invalid_input("Enter your choice (1 or 2): ", "Invalid choice. Please enter 1 or 2.", decision);
                while (true){
                    if (decision == 1){
                        new_game(initial, money, total, wins, rate, file_name);
                        break;
                    }
                    else if (decision == 2){ //shows the current balance if the user decides to check it. 
                        cout << "Goodbye, see you next time!" << endl;
                        exit(0);
                    }
                    else{
                        cout << "Invalid choice. Please enter 1 or 2." << endl;
                        detect_invalid_input("Enter your choice (1 or 2): ", "Invalid choice. Please enter 1 or 2.", decision);
                    }
                } 
            }
        } else if (choice == 2) { //The application tells the user to cancel or resume the game if the user's balance drops below $10. 
            cout << "*************************" << endl;
            cout << "You currently have $" << money << endl;
            cout << "*************************" << endl;
        } else if (choice == 3) {
            save_game(initial, money, total, wins, rate, file_name); //The'save_game()' function is used to save the game's progress if the user choose to save it. 
        } else if (choice == 4) {
            cout << "Exiting the game..." << endl;
            break;
        } else {
            cout << "Invalid choice. Please enter 1, 2, 3 or 4." << endl;
        }
    }
    return 0; //Ends if the user decides to quit the game. The'main()' method concludes by returning 0.
}

/*

It checks whether either the player or the banker has a natural win or needs to draw a third card according to the game rules. If a third card needs to be drawn, the function deals it and displays it using the `message()` function. 
It then determines the winner using the `checkWin()` function and displays the winner using the `declareWinner()` function.
If the user wins the bet, the function adds the payout to their balance, and if the user loses the bet, the function subtracts the bet amount from their balance. If there is a tie, the function returns the bet amount to those who bet on the player or the banker.
Prompts the user to choose a bet and an amount, deals the cards, determines the winner, updates the game statistics, and updates the user's balance based on the outcome of the game.
*/
void play(double &money, double &total, int &wins, double &rate){ //Called when the user chooses to start playing the game.
    double choice; //Choose whether to bet on the player, banker, or tie using the `detect_invalid_input()` function to validate the input.
    detect_invalid_input("Please choose player or banker (1 for player, 2 for banker, 3 for tie): ", "Invalid choice. Please enter 1, 2 or 3.", choice);
    while (true){
        if (choice == 1 || choice == 2 || choice == 3){
            break;
        }
        else{
            cout << "Invalid choice. Please enter 1, 2 or 3." << endl;
            detect_invalid_input("Please choose player or banker (1 for player, 2 for banker, 3 for tie): ", "Invalid choice. Please enter 1, 2 or 3.", choice);
        }
    }
    double playAmount;
    detect_invalid_input("How much money you want to play: $", "Invalid input.", playAmount);
    while(true){ //Checks whether the user has enough money to make the bet, and if not, it displays an error message and prompts the user to enter a valid amount.
        if(playAmount<=money && playAmount>=10){
            break; 
        }
        else if (playAmount<10){
            cout << "Sorry, the minimum bet to play Baccarat is $10." << endl;
        }
        else{
            cout << "Sorry, not enough balance. (Your current balance: $" << money << ")" << endl;
        }
        detect_invalid_input("How much money you want to play: $", "Invalid input.", playAmount);
    }
    vector<Card> deck; //Creates a deck of cards, shuffles them, and deals the first two cards to the player and the banker, displaying them using the `message()` function. 
    for (short x = 0; x < 4; x++)
    {
        string suit;
        switch (x)
        {
        case 0:
            suit = "Hearts";
            break;
        case 1:
            suit = "Diamonds";
            break;
        case 2:
            suit = "Spades";
            break;
        case 3:
            suit = "Clubs";
            break;
        }

        for (short index = 1; index < 14; index++)
        {
            Card temp = Card(index, suit);
            deck.push_back(temp);
        }
    }
 
    //shuffle the deck of cards
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);
    

    //First two cards for each player get dealt and displayed
    Hand player;
    player.addCard(deck.at(51));
    message("Player's first draw", "Player", player.getCard1().getFace(), player.getCard1().getSuit());

    Hand bank;
    bank.addCard(deck.at(50));
    message("Banker's first draw", "Banker", bank.getCard1().getFace(), bank.getCard1().getSuit());

    player.addCard(deck.at(49));
    message("Player's second draw", "Player", player.getCard2().getFace(), player.getCard2().getSuit());

    bank.addCard(deck.at(48));
    message("Banker's second draw", "Banker", bank.getCard2().getFace(), bank.getCard2().getSuit());

    short winner = 0; //win conditions will be 1=player, 2=bank, 3=tie;
    winner = checkWin(player.getValue(), bank.getValue(), 1);

    if (winner == 0)
    {   
        if (drawThird(player.getValue()))
        {
            player.addCard(deck.at(47));
            message("Player's third draw", "Player", player.getCard3().getFace(), player.getCard3().getSuit());
            if ((bankDraw(player.getCard3().getValue(), bank.getValue())))
            {
                bank.addCard(deck.at(46));
                message("Banker's third draw", "Banker", bank.getCard3().getFace(), bank.getCard3().getSuit());
            }
        }
        else if (drawThird(bank.getValue()))
        {
            bank.addCard(deck.at(46));
            message("Banker's third draw", "Banker", bank.getCard3().getFace(), bank.getCard3().getSuit());
        }
        winner = checkWin(player.getValue(), bank.getValue(), 2);
    }

    declareWinner(winner, player.getValue(), bank.getValue());
    total++;
    if(winner == 3 && choice == winner){ 
        money += playAmount*8; // Tie payout 8:1
        wins++;
    }
    else if(choice == winner){
        money += playAmount; // Player or Banker payout 1:1
        wins++;
    }
    else if(winner == 3){
        // A tie returns bet to those who bet on Player or Banker
    }
    else{
        money -= playAmount; // Loses the bet
    }
    rate = (wins/total)*100;
}

/*
If the `winner` variable is `1`, the function displays "Player WINS with a hand of [player] over the Banker's hand of [bank]". If the `winner` variable is `2`, the function displays "Banker WINS with a hand of [bank] over the Player's hand of [player]". If the `winner` variable is `3`, the function displays "Player and Banker TIE with hands of [player]".

Displays a message indicating the winner of the game and the value of the hands of the player and the banker. It uses a `switch` statement to determine the winner based on the value of the `winner` argument.
*/
void declareWinner(short winner, short player, short bank) //Takes three arguments: `winner`, `player`, and `bank`. The `winner` argument is an integer that represents the winner of the game: `1` for the player, `2` for the banker, and `3` for a tie. 
{
    display("AND THE WINNER IS...");

    switch (winner) //Determine the winner and display the appropriate message
    //The `player` and `bank` arguments are integers that represent the value of the player's and the banker's hands, respectively.
    {
    case 1:
        cout << "Player WINS with a hand of " << player << " over the Banker's hand of " << bank << endl;
        break;
    case 2:
        cout << "Banker WINS with a hand of " << bank << " over the Players's hand of " << player << endl;
        break;
    case 3:
        cout << "Player and Banker TIE with hands of " << player << endl;
        break;
    }
}

/*
The `checkWin()` function takes three arguments: `player`, `bank`, and `round`. The `player` and `bank` arguments are integers that represent the value of the player's and the banker's hands, respectively. 
The `round` argument is an integer that represents the round of the game: `1` for the first round and `2` for the second round.
The function first checks if it is the first round of the game. If it is, it checks the value of the player's and the banker's hands to determine if either has a natural win or needs to draw a third card. If the player's hand is greater than 7 and the banker's hand is 7 or less, the player wins. 
If the banker's hand is greater than 7 and the player's hand is 7 or less, the banker wins. 
If both hands are greater than 7, the hand with the higher value wins, and if they have the same value, it is a tie.
If neither hand meets any of these conditions, the function returns 0, indicating that the game is not over yet.
If it is the second round of the game, the function compares the values of the player's and the banker's hands to determine the winner. If the player's hand is greater than the banker's hand, the player wins. If the banker's hand is greater than the player's hand, the banker wins. If both hands have the same value, it is a tie.
*/
short checkWin(short player, short bank, short round) //Checks the value of the player's and the banker's hands to determine the winner of the game.
{
    if (round == 1)
    {
        if (player > 7 && bank <= 7)
        {
            return 1;
        }
        else if (bank > 7 && player <= 7)
        {
            return 2;
        }
        else if (bank > 7 && player > 7)
        {
            if(bank>player){
                return 2;
            }
            else if(bank<player){
                return 1;
            }
            else{
                return 3;
            }
        }
        else
        {
            return 0;
        }
    }
    else //It returns an integer value indicating the winner: `1` for the player, `2` for the banker, and `3` for a tie. 
        //If the game is not over yet, it returns 0. The logic of the function is based on the rules of Baccarat.
    {
        if (player > bank)
        {
            return 1;
        }
        else if (bank > player)
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }
}

/*********************************************************************************************
* Checks whether the player or the banker should draw a third card or not based on the punto blanco casino drawing rules *
*********************************************************************************************/
bool drawThird(short person)
{
    if (person>5){
        return false;
    }
    else{
        return true;
    }
}

/*********************************************************************************************
* Checks whether the banker should draw a third card or not based on the player's third card *
*********************************************************************************************/
bool bankDraw(short player, short banker)
{
    //set rounding toward zero
    // int originalRounding = _controlfp_s(0, 0, 0);
    // _controlfp_s(_RC_CHOP, _MCW_RC, 0);

    if (player == 8)
    {
        player = -2;
    }
    if (player == 9)
    {
        player = -1;
    }

    if ((player / 2) + 3 >= banker)
    {
        return true;
    }
    else
    {
        return false;
    }

    //reset original rounding
    // _controlfp(originalRounding, _MCW_RC);
}

    
    void display(string title)
{
    string line;


    //Set the title
    cout << setw(20) << right << title << endl;

    //display the separator line below the screen title
    cout << line.assign(LINE_LENGTH, LINE_SYMBOL) << "\n"<< endl;
}

void message(string title, string player, int face, string suit)
{

    display(title);
    if(suit == "Clubs"){
        suit = "♣";
    }
    else if(suit == "Hearts"){
        suit = "♥";
    }
    else if(suit == "Diamonds"){
        suit = "♦";
    }
    else{
        suit = "♠";
    }
    
    
    string card_char = (face == 1) ? "A" :
                            (face == 11) ? "J" :
                            (face == 12) ? "Q" :
                            (face == 13) ? "K" :
                            std::to_string(face);

    cout << "┌───────┐" << std::endl;
    cout << "| " << setw(2) << left << card_char << "    |" << endl;
    cout << "| " << suit << " " << suit << " " << suit << " |" << endl;
    cout << "| " << suit << " " << suit << " " << suit << " |" << endl;
    cout << "| " << suit << " " << suit << " " << suit << " |" << endl;
    cout << "|    " << setw(2) << right << card_char << " |" << endl;
    cout << "└───────┘" << std::endl;


    cout << "\n"<< endl;
    cout << "Press [Enter] key to continue..." << endl;
    cin.ignore();
}

/*
Takes three arguments: `initial`, `total`, and `rate`. The `initial` argument is a double that represents the initial balance of the player. The `total` argument is a double that represents the total number of games played by the player. 
The `rate` argument is a double that represents the player's win rate as a percentage.
`cout` that includes the initial balance, the total number of games played, and the win rate. The message is formatted using `<<` operator to concatenate strings with the values of the variables. The message includes the dollar sign before displaying the initial balance. 
The win rate is displayed as a percentage using the `%` symbol.
It formats the message using the `<<` operator to concatenate strings with the values of the variables and displays the win rate as a percentage using the `%` symbol. The purpose of the function is to provide the player with a summary of their game statistics.
*/
void showData(double initial, double total, double rate){ //Displays the player's initial balance, the total number of games played, and the win rate to the console.
    cout << "You started with an initial of $" << initial << ", played a total of " << total << " games and your winning rate so far is " << rate << "%." << endl;
}

