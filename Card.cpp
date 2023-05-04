#include "Card.h"
#include <iostream>
#include <string>
using namespace std;
//class Card{
//private:
//    int cardValue;
//    string suit;
//    int faceValue;
//public:
//    Card();
//    Card(int, string);
//
//    int getFace();
//    int getValue();
//    string getSuit();
//
//};

Card::Card(){
    cardValue = 0;
    suit = "";
    faceValue = 0;
}

Card::Card(int value, string suit1){
    faceValue = value;
    suit = suit1;
    if(value>9){
        cardValue = 0;
    }
    else{
        cardValue = value;
    }
}

int Card::getValue(){
    return cardValue;
}

int Card::getFace(){
    return faceValue;
}

string Card::getSuit(){
    return suit;
}

//class Hand{
//private:
//
//public:
//    Card card1, card2, card3;
//    Hand();
//    int getValue();
//    void addCard(Card);
//};

Hand::Hand(){
    Card card1 = Card();
    Card card2 = Card();
    Card card3 = Card();
}

//Hand::Hand(Card card){
//    Card card1 = card;
//    Card card2 = Card();
//    Card card3 = Card();
//}
Card Hand::getCard1() { return card1; }
Card Hand::getCard2() { return card2; }
Card Hand::getCard3() { return card3; }

void Hand::addCard(Card card){
    if(card1.getFace()==0){
        card1 = card;
    }
    else if(card2.getFace()==0){
        card2 = card;
    }
    else{
        card3 = card;
    }
}

int Hand::getValue(){
    return (card1.getValue()+card2.getValue()+card3.getValue())%10;
}

