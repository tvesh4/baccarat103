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

using namespace std;

void display(string);
void message(string, string, int, string);
void showData(double, double, double);

void declareWinner(short, short, short);
short checkWin(short, short, short);
bool drawThird(short);
bool bankDraw(short, short);
void play(double &, double &, int &, double &);

const int LINE_LENGTH = 30;
const char LINE_SYMBOL = '*';


void play(double &money, double &total, int &wins, double &rate){
    double choice;
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
    while(true){
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
    vector<Card> deck;
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
