#include "deck.h"

using namespace std;


// create a standard 52-card deck
void Deck::createDeck()
{
    this->deck.clear();
    for (int s= (int)Card::cSuits::Spade; s < (int)Card::cSuits::Spade+SUITS; s++)
    {    
        for (Card::cPoints val = CARD_START; val < CARD_START+POINTS; val++)
        {
            Card::cSuits suit = static_cast<Card::cSuits>(s);
            Card newcard(suit, val);
            this->deck.push_back(newcard);
        }
    }
}

// shuffle the cards in 52-card deck
void Deck::shuffleDeck()
{
    srand(time(0));
    Card temp;  // for swapping
    for (int i = this->deck.size()-1; i>= 1; i--)
    {
        int j = rand() % (i+1);
        temp = this->deck[j];
        this->deck[j] = this->deck[i];
        this->deck[i] = temp;
    }
}

// return a card from the tail of the deck
Card Deck::deal_a_card()
{
    Card card = deck.back();
    deck.pop_back();
    return card;
}