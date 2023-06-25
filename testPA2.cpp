/*
 * Course: CS216-00x
 * Project: Project 2
 * Purpose: to decide the best FIVE-card poker hand out of SEVEN cards according to poker hand ranking
 *          the testing cases are created for the purpose of testing your definition of PokerHand class
 *          
 */
#include <iostream>
#include <vector>
#include "pokerhand.h"

using namespace std;

// avoid magic numbers
const int TOTALCARDS = 7;  // each player gets TOTALCARDS=7 cards
const int HANDS = 5;       // each player plays HANDS=5 cards in hand

// decide the best five cards out of seven cards
// best means the highest ranking of five-card poker hand defined in the poker game
// pass in a vector of seven cards 
// (const call by reference: safe for the arugment and no copy is made for efficiency)
// return the best PokerHand object which represents the best five-card poker hand
PokerHand best_FIVE_out_of_SEVEN(const vector<Card>& cards); 

int main() 
{
    // creating five different testing cases
    // in order to test your definition of PokerHand class 
    vector<Card> Test0, Test1, Test2, Test3, Test4;
    
    Test0.push_back(Card(Card::cSuits::Diamond, 12));
    Test0.push_back(Card(Card::cSuits::Heart,   13));
    Test0.push_back(Card(Card::cSuits::Spade,    7));
    Test0.push_back(Card(Card::cSuits::Heart,   12));
    Test0.push_back(Card(Card::cSuits::Club,    7));
    Test0.push_back(Card(Card::cSuits::Diamond,  7));
    Test0.push_back(Card(Card::cSuits::Heart,   10));

    Test1.push_back(Card(Card::cSuits::Spade,   10));
    Test1.push_back(Card(Card::cSuits::Diamond,  6));
    Test1.push_back(Card(Card::cSuits::Heart,   12));
    Test1.push_back(Card(Card::cSuits::Heart,   11));
    Test1.push_back(Card(Card::cSuits::Diamond, 13));
    Test1.push_back(Card(Card::cSuits::Club,     6));
    Test1.push_back(Card(Card::cSuits::Heart,   14));

    Test2.push_back(Card(Card::cSuits::Spade,   12));
    Test2.push_back(Card(Card::cSuits::Heart,    7));
    Test2.push_back(Card(Card::cSuits::Heart,   10));
    Test2.push_back(Card(Card::cSuits::Heart,    8));
    Test2.push_back(Card(Card::cSuits::Heart,   12));
    Test2.push_back(Card(Card::cSuits::Heart,    9));
    Test2.push_back(Card(Card::cSuits::Heart,    6));

    Test3.push_back(Card(Card::cSuits::Diamond, 14));
    Test3.push_back(Card(Card::cSuits::Spade,    6));
    Test3.push_back(Card(Card::cSuits::Club,     6));
    Test3.push_back(Card(Card::cSuits::Club,     3));
    Test3.push_back(Card(Card::cSuits::Club,    10));
    Test3.push_back(Card(Card::cSuits::Club,     2));
    Test3.push_back(Card(Card::cSuits::Club,     7));
    
    Test4.push_back(Card(Card::cSuits::Club,     3));
    Test4.push_back(Card(Card::cSuits::Heart,   11));
    Test4.push_back(Card(Card::cSuits::Diamond,  9));
    Test4.push_back(Card(Card::cSuits::Club,    11));
    Test4.push_back(Card(Card::cSuits::Diamond, 11));
    Test4.push_back(Card(Card::cSuits::Spade,   10));
    Test4.push_back(Card(Card::cSuits::Spade,   11));
    
    PokerHand testH[HANDS];
    testH[0]= best_FIVE_out_of_SEVEN(Test0);
    testH[1]= best_FIVE_out_of_SEVEN(Test1);
    testH[2]= best_FIVE_out_of_SEVEN(Test2);
    testH[3]= best_FIVE_out_of_SEVEN(Test3);
    testH[4]= best_FIVE_out_of_SEVEN(Test4);
    PokerHand bestH;

    for (int i = 0; i < HANDS; i++)
    {
        if (bestH.compareHand(testH[i]) < 0)
            bestH = testH[i];
    }
    
    // Now bestH holds the best five-card hand from all testing cases 
    cout << "The Best five-card hand from all testing cases is: " << endl;
    bestH.print();
    return 0;
}

PokerHand best_FIVE_out_of_SEVEN(const vector<Card>& cards)
{    

    PokerHand bestH;
    PokerHand cardsH;

    // check if the parameter is valid
    if (cards.size() != TOTALCARDS)
    {
        cout << "Invalid Cards, we need SEVEN cards!" << endl;
        return cardsH; // return a PokerHand object by default constructor
    }

    // Consider all possible ways of dropping two cards
    // from all seven cards 
    // i is the index of the first card dropped
    // and j is the index of the second card dropped.
    // There are 21 different ways to pick 5 cards out of 7
    for (int i=0; i < TOTALCARDS; i++) 
    {
        for (int j=i+1; j < TOTALCARDS; j++) 
        {
            Card pick[HANDS];
            int index = 0;

            // Iterate over all seven cards and assign them to the pick[] array
            // exclude cards with index numbers of #i and #j.
            for (int k=0 ; k < TOTALCARDS ; k++) 
            {
                if (k == i || k == j) 
                    continue;
                pick[index] = cards[k];
                index++;
            }
            
            // create a PokerHand with pick[]
            cardsH.setPokerHand(pick, HANDS);

            // Check to see if current pick is better than
            // the best you have seen so far
            if (bestH.compareHand(cardsH) < 0)
            {
                bestH = cardsH ;
            }
        }
    }

    // Now bestH holds the best poker hand among all 21 poker hands
    cout << "*** Best five-card hand ***" << endl;
    bestH.print();
    cout << endl << endl;
    return bestH;
}

