#include "Card.h"
#include <iostream>
#include <string>
using namespace std;

Card::Card(){ //The `Card` class has a default constructor that initializes the `cardValue` to 0, the `suit` to an empty string, and the `faceValue` to 0. 
    cardValue = 0;
    suit = "";
    faceValue = 0;
}

Card::Card(int value, string suit1){
    faceValue = value; //Also has a parameterized constructor that sets the `faceValue` and `suit` based on the input values. 
    suit = suit1;
    if(value>9){
        cardValue = 0;
    }
    else{
        cardValue = value;
    }
}

//The `getValue()`, `getFace()`, and `getSuit()` member functions return the `cardValue`, `faceValue`, and `suit`, respectively.
int Card::getValue(){ 
    return cardValue;
}

int Card::getFace(){
    return faceValue;
}

string Card::getSuit(){
    return suit;
}

Hand::Hand(){ //The `Hand` class has a default constructor that initializes three `Card` objects with default `cardValue`, `suit`, and `faceValue`.
    
    //The `Card` class represents a playing card and has member functions to get the card's value, face value, and suit. 
    Card card1 = Card();
    Card card2 = Card();
    Card card3 = Card();
}

//The `getCard1()`, `getCard2()`, and `getCard3()` member functions return the first, second, and third `Card` objects in the hand, respectively. 
Card Hand::getCard1() { return card1; } 
Card Hand::getCard2() { return card2; }
Card Hand::getCard3() { return card3; }

//The `Hand` class represents a hand of cards and has member functions to get the cards in the hand, add a card to the hand, and calculate the value of the hand.

void Hand::addCard(Card card){ //The `addCard()` member function adds a `Card` object to the hand. 
    if(card1.getFace()==0){ //If the first `Card` object in the hand has a `faceValue` of 0, the new `Card` object is added to that position. 
        card1 = card;
    }
    else if(card2.getFace()==0){ //Otherwise, if the second `Card` object in the hand has a `faceValue` of 0, the new `Card` object is added to that position. 
        card2 = card;
    }
    else{
        card3 = card; ////Otherwise, the new `Card` object is added to the third position. 
    }
}

int Hand::getValue(){ //The `getValue()` member function calculates and returns the total value of the hand, which is the sum of the `cardValue` of each `Card` object in the hand modulo 10.
    return (card1.getValue()+card2.getValue()+card3.getValue())%10;
}

