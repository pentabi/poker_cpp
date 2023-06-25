/*
 * Course: CS216
 * Project: Project 2
 * Purpose: to decide the best FIVE-card poker hand out of SEVEN cards according to poker hand ranking
 *          the testing cases are created for the purpose of testing your definition of PokerHand class
 *
 */
#include <iostream>
#include <vector>
#include "pokerhand.h" //includes card.h and rank.h
#include "SortedLinkedList.h"
#include "deck.h"

using namespace std;

// avoid magic numbers
const int TOTALCARDS = 7; // each player gets TOTALCARDS=7 cards
const int HANDS = 5;      // each player plays HANDS=5 cards in hand

// decide the best five cards out of seven cards
// best means the highest ranking of five-card poker hand defined in the poker game
// pass in a vector of seven cards
// (const call by reference: safe for the arugment and no copy is made for efficiency)
// return the best PokerHand object which represents the best five-card poker hand
PokerHand best_FIVE_out_of_SEVEN(const vector<Card> &cards);

int main()
{
    // initialization
    string still_play;
    Deck playDeck;
    // player card, computer card and shared card
    vector<Card> p_card(7), com_card(7), s_card(5);

    do
    {
        // create and shuffle deck
        playDeck.createDeck();
        playDeck.shuffleDeck();

        // push 2 card into each of the player's card
        for (int i = 0; i < 2; i++)
        {
            p_card[i] = (playDeck.deal_a_card());   // push 2 card into vector
            com_card[i] = (playDeck.deal_a_card()); // push 2 card into vector
        }
        // push 5 shared cards
        for (int i = 0; i < 5; i++)
        {
            s_card[i] = (playDeck.deal_a_card());
        }

        for (int i = 0; i < 5; i++)
        {
            p_card[i + 2] = s_card[i];
            com_card[i + 2] = s_card[i];
        }

        // print player, shared, and computer's hand
        cout << "The cards in your hand are: " << endl;
        cout << "  " << p_card[0] << endl;
        cout << "     " << p_card[1] << endl;

        cout << "The FIVE cards on the deck to share are:" << endl;
        cout << "  *************************" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "  *  " << s_card[i] << "        *" << endl;
        }
        cout << "  *************************" << endl;

        cout << "The cards in computer's hand are: " << endl;
        cout << "  " << com_card[0] << endl;
        cout << "     " << com_card[1] << endl;
        cout << endl;

        PokerHand testH[2];
        cout << "Player 1: You" << endl;
        testH[0] = best_FIVE_out_of_SEVEN(p_card);
        cout << "Player 2: Computer" << endl;
        testH[1] = best_FIVE_out_of_SEVEN(com_card);

        // determine who won
        if (testH[0].compareHand(testH[1]) < 0)
            cout << "Sorry, the computer wins the game!" << endl;
        else if (testH[0].compareHand(testH[1]) > 0)
            cout << "Congratulations, you win the game!" << endl;
        else if (testH[0].compareHand(testH[1]) == 0)
            cout << "It is a tie game!" << endl;

        cout << "Do you want to play poker game again (Press \"q\" or \"Q\" to quit the program)" << endl;
        getline(cin, still_play);
        for (int i = 0; i < still_play.length(); i++)
            still_play[i] = tolower(still_play[i]);
    } while (still_play != "q");

    cout << "Thank you for using this program!" << endl;
    return 0;
}

PokerHand best_FIVE_out_of_SEVEN(const vector<Card> &cards)
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
    for (int i = 0; i < TOTALCARDS; i++)
    {
        for (int j = i + 1; j < TOTALCARDS; j++)
        {
            Card pick[HANDS];
            int index = 0;

            // Iterate over all seven cards and assign them to the pick[] array
            // exclude cards with index numbers of #i and #j.
            for (int k = 0; k < TOTALCARDS; k++)
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
                bestH = cardsH;
            }
        }
    }

    // Now bestH holds the best poker hand among all 21 poker hands
    cout << "*** Best five-card hand ***" << endl;
    bestH.print();
    cout << endl
         << endl;
    return bestH;
}
