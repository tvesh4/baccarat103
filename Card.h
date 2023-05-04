#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
using namespace std;
class Card{
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
private:
    Card card1, card2, card3;
    
public:
    Card getCard1();
    Card getCard2();
    Card getCard3();
    Hand();
//  Hand(Card card);
    int getValue();
    void addCard(Card);
};

#endif
