#include "card.h"

using namespace std;

// Default constructor.
// We allow uninitialized Cards to be created.
// This allows arrays of Cards.
// Uninitialized cards should have Invalid for its suit
// and 0 for its points.
Card::Card()
{
    this->suit = cSuits::Invalid;
    this->point = 0;
}

// Alternate constructor
// Create a Card with specified suit and points.
Card::Card(cSuits s, cPoints p)
{
    this->suit = s;
    this->point = p;
}

// access the card point value
Card::cPoints Card::getPoint() const
{
    return this->point;
}

// access the card suit value
Card::cSuits Card::getSuit() const
{
    return this->suit;
}

// compare with another Card object passed in as parameter: other
// if the object your are working on has higher point than other, return 1;
// if the object your are working on has lower point than other, return -1;
// otherwise, return 0
bool operator<(Card C1, Card C2)
{
    if (C1.getPoint() < C2.getPoint())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Display a description of the Card object to standard output.
// The output should look like:
//   the sign of suit, followed by the point, then followed by the sign of suit again
ostream &operator<<(ostream &out, const Card &C)
{
    Card::cSuits suit = C.getSuit();
    Card::cPoints point = C.getPoint();
    switch (suit)
    {
    case Card::cSuits::Spade:
        out << SPADE;
        break;
    case Card::cSuits::Club:
        out << CLUB;
        break;
    case Card::cSuits::Heart:
        out << HEART;
        break;
    case Card::cSuits::Diamond:
        out << DIAMOND;
        break;
    }
    if (point == 13)
        out << "K";
    else if (point == 12)
        out << "Q";
    else if (point == 11)
        out << "J";
    else if (point == 14)
        out << "A";
    else
        out << point;
    switch (suit)
    {
    case Card::cSuits::Spade:
        out << SPADE;
        break;
    case Card::cSuits::Club:
        out << CLUB;
        break;
    case Card::cSuits::Heart:
        out << HEART;
        break;
    case Card::cSuits::Diamond:
        out << DIAMOND;
        break;
    }
    return out;
}
