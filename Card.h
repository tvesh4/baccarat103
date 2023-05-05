//Ensure that the code inside the file is only compiled once.
#ifndef CARD_H
#define CARD_H

//This is a header file for the `Card` and `Hand` classes. 

#include <iostream>
#include <string>
using namespace std;
class Card{ //It has a default constructor that initializes the member variables to default values and a parameterized constructor that takes in two arguments and sets the `faceValue` and `suit` based on the input values. 
private:
    int cardValue;
    string suit;
    int faceValue;
public:
    Card();
    Card(int, string);
    int getFace();
    int getValue();
    string getSuit();
};

class Hand{
private: //Default constructor that initializes the three member variables to default `Card` objects. 
    Card card1, card2, card3;
    
public: //The `getCard1()`, `getCard2()`, and `getCard3()` member functions return the first, second, and third `Card` objects in the hand, respectively. 
    Card getCard1();
    Card getCard2();
    Card getCard3();
    Hand();
//  Hand(Card card);
    int getValue(); //The `getValue()` member function calculates and returns the total value of the hand, which is the sum of the `cardValue` of each `Card` object in the hand modulo 10.
    void addCard(Card); //The `addCard(Card)` member function adds a `Card` object to the hand. 
};

#endif
