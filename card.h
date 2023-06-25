/* File: card.h
 * Course: CS216-00x
 * Project: Lab 10 (as part of Project 2)
 * Purpose: the declaration for the Card class.
 *** DO NOT CHANGE THIS FILE ***
 *
 */

#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

// define the unicode for four suits for display purpose
const char SPADE[] = "\e[0;30;47m\xe2\x99\xa0\e[0;37;40m";
const char CLUB[] = "\e[0;30;47m\xe2\x99\xa3\e[0;37;40m";
const char HEART[] = "\e[0;31;47m\xe2\x99\xa5\e[0;37;40m";
const char DIAMOND[] = "\e[0;31;47m\xe2\x99\xa6\e[0;37;40m";

class Card 
{
    public:
        // Type definition for the suits of a playing card.
        // Invalid means the Card object has not been initialized.
        // Note: outside Card member functions, refer this type using Card::cSuits, 
        // Card::cSuits::Spades, Card::cSuits::Hearts, ...
        //
        enum class cSuits {Invalid, Spade, Club, Heart, Diamond};

        // Type definition for the point value of a playing card.
        // A point value of 0 means the Card object has not been initialized.
        // J = 11, Q = 12, K = 13, A = 14.
        // A point value of 1 is not used.
        // Note: outside Card member functions, refer this type using Card::cPoints
        //
        typedef unsigned int cPoints;

        // Default constructor.
        // We allow uninitialized Cards to be created.
        // This allows arrays of Cards.
        // Uninitialized cards should have Invalid for its suit
        // and 0 for its points.
        Card(); 

        // Alternate constructor
        // Create a Card with specified suit and points.
        Card(cSuits s, cPoints p);

        // access the card point value
        cPoints getPoint() const;

        // access the card suit value
        cSuits getSuit() const;

        // define the operator "<" for Card class
        // C1 < C2 if and only if the point of C1 is less than the point of C2 
        friend bool operator<(Card C1, Card C2);

        // define the operator "<<" for Card class
        // directly send the Card object to the cout, in the following format:
        //   the sign of suit, followed by the point, then followed by the sign of suit again
        friend ostream& operator<<(ostream& out, const Card& C);

        // Assign friendship to class named PokerHand
        friend class PokerHand;
        
    private:
        cSuits suit;        // suit of the card
        cPoints point;    // point value of the card
};
#endif  /* CARD_H */
