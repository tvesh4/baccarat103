#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    Card();
    Card(short int face, std::string suit);
    short int value();
    std::string getFace();
    std::string getSuit();
private:
    short int cardFace;
    std::string cardSuit;
};

class Hand {
public:
    Hand(Card card);
    void addCard(Card card);
    short int value();
    Card card1;
    Card card2;
    Card card3;
};

#endif
