#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;
class Card {
public:
    Card();
    Card(short int face, string suit);
    short int value();
    string getFace();
    string getSuit();
    
private:
    short int cardValue;
    short int face;
    string suit;
};

class Hand {
public:
    Hand();
    Hand(Card card);
    void addCard(Card card);
    short int value();
    Card card1;
    Card card2;
    Card card3;
};

#endif
