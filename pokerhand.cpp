
/* File: pokerhand.cpp
 * Course: CS216-00x
 * Project 2
 * Purpose: the implementation of member functions for the pokerhand class.
 *
 */
#include <iostream>
#include <sstream>
#include <iomanip>
#include "pokerhand.h"
using namespace std;

static const int HANDS = 5;
// Default constructor.
// We allow a blank PokerHand to be created.
// However, the default constructor should make sure
// that hand_rank is (Rank::hRanks::NoRank, 0).
PokerHand::PokerHand()
{
    for (int i = 0; i < HANDS; i++)
    {
        cards[i] = Card();
    }
    hand_rank = Rank(Rank::hRanks::NoRank, 0);
}

// It should store the HANDS cards
// given as parameters in the cards[] array.
// if size is not HANDS, display "Invalid number of cards!"
// It should also immediately evaluate the hand, determine
// its rank: ranking kind and the card value
void PokerHand::setPokerHand(Card in_hand[], int size)
{
    if (size != HANDS)
    {
        cout << "Invalid number of cards!" << endl;
        return;
    }
    for (int i = 0; i < HANDS; i++)
    {
        cards[i] = in_hand[i];
    }
    // evaluate the hand, determine its rank
    if (isStraightFlush())
        return;
    if (isFourOfAKind())
        return;
    if (isFullHouse())
        return;
    if (isFlush())
        return;
    if (isStraight())
        return;
    if (isThreeOfAKind())
        return;
    if (isPair())
        return;
    if (isHighCard())
        return;
}

// Compare this hand versus otherHand according
// to the rules of poker.
// Returns a negative number (< 0)
// if this hand loses to the otherHand.
// Returns a positive number (> 0)
// if this hand beats the otherHand.
// Returns zero if it's a tie.
//
// An invalid hand loses to any hand. If both hands
// are invalid, the result is undefined (could be
// negative, zero or positive).
//
int PokerHand::compareHand(const PokerHand &otherHand) const
{
    if (hand_rank.kind != otherHand.hand_rank.kind)
    {
        return hand_rank.kind > otherHand.hand_rank.kind ? 1 : -1;
    }
    else
    {
        if (hand_rank.getPoint() > otherHand.hand_rank.getPoint())
            return 1;
        else if (hand_rank.getPoint() < otherHand.hand_rank.getPoint())
            return -1;
        else
            return 0;
    }
    return 0;
}

// Prints out the five cards and its rank to standard output.
// It should look like:
// Five cards:
// one card per line
// then followed by "Its rank is: rank"
void PokerHand::print() const
{
    cout << "Five cards in order:" << endl;
    for (int i = 0; i < HANDS; i++)
    {
        cout << cards[i] << " ";
    }
    cout << endl;
    string num = to_string(hand_rank.point);
    if (num == "14")
        num = "A";
    else if (num == "11")
        num = "J";
    else if (num == "12")
        num = "Q";
    else if (num == "13")
        num = "K";
    cout << "Its rank is: " << RANK_NAMES[int(hand_rank.kind)] << "(" << num << ")" << endl;
}

// Return the rank of this hand
Rank PokerHand::getRank() const
{
    return hand_rank;
}

// Returns true if the hand is a StraightFlush
// and set the hand_rank (StraightFlush, highest point of the sequential five cards)
// otherwise returns false
bool PokerHand::isStraightFlush()
{
    sort();
    if (!isAllOneSuit())
        return false;
    if (!isSequence())
        return false;
    Rank result(Rank::hRanks::StraightFlush, cards[0].point);
    hand_rank = result;
    return true;
}

// Returns true if the hand is a Four of a Kind
//              and set the hand_rank (FourOfAKind, highest point of the same four cards)
// otherwise returns false
bool PokerHand::isFourOfAKind()
{
    sort();
    if (isStraightFlush())
        return false;
    if (cards[0].point == cards[3].point)
    {
        Rank result(Rank::hRanks::FourOfAKind, cards[0].point);
        hand_rank = result;
        return true;
    }
    if (cards[1].point == cards[4].point)
    {
        Rank result(Rank::hRanks::FourOfAKind, cards[1].point);
        hand_rank = result;
        return true;
    }
    return false;
}

// Returns true if the hand is a Full House
// and set the hand_rank (FullHouse, highest point of the same three cards)
// otherwise returns false
bool PokerHand::isFullHouse()
{
    sort();
    if (cards[0].point == cards[1].point && cards[2].point == cards[4].point)
    {
        Rank result(Rank::hRanks::FullHouse, cards[2].point);
        hand_rank = result;
        return true;
    }
    if (cards[0].point == cards[2].point && cards[3].point == cards[4].point)
    {
        Rank result(Rank::hRanks::FullHouse, cards[0].point);
        hand_rank = result;
        return true;
    }
    return false;
}

// Returns true if the hand is a Flush
// and set the hand_rank (Flush, highest point of the five cards)
// otherwise returns false
bool PokerHand::isFlush()
{
    sort();
    if (!isAllOneSuit())
        return false;
    Rank result(Rank::hRanks::Flush, cards[0].point);
    hand_rank = result;
    return true;
}

// Returns true if the hand is a Straight
// and set the hand_rank (Straight, highest point of the sequential five cards)
// otherwise returns false
bool PokerHand::isStraight()
{
    sort();
    if (!isSequence())
        return false;
    Rank result(Rank::hRanks::Straight, cards[0].point);
    hand_rank = result;
    return true;
}

// Returns true if the hand is a Three of a Kind
// and set the hand_rank (ThreeOfAKind, highest point of the same three cards)
// otherwise returns false
bool PokerHand::isThreeOfAKind()
{
    sort();
    for (int i = 0; i < HANDS - 2; ++i)
    {
        if (cards[i].point == cards[i + 1].point && cards[i + 1].point == cards[i + 2].point)
        {
            Rank result(Rank::hRanks::ThreeOfAKind, cards[i].point);
            hand_rank = result;
            return true;
        }
    }
    return false;
}

// Returns true if the hand is a Pair (we consider either one pair or two pairs is a Pair)
// and set the hand_rank (Pair, highest point of any pair)
// otherwise returns false
bool PokerHand::isPair()
{
    sort();
    for (int i = 0; i < HANDS - 1; i++)
    {
        if (cards[i].point == cards[i + 1].point)
        {
            Rank result(Rank::hRanks::Pair, cards[i].point);
            hand_rank = result;
            return true;
        }
    }
    return false;
}

// Returns true if the hand is a High Card
// and set the hand_rank (High Card, highest point of the five cards)
// otherwise returns false
bool PokerHand::isHighCard()
{
    sort();
    Rank result(Rank::hRanks::HighCard, cards[0].point);
    hand_rank = result;
    return true;
}

// helper functions (private)
// they are helpful for the public member functions of this class
// however they cannot be called outside of the class

// to help sort the HANDS=5 cards in decreasing order by card points
void PokerHand::sort()
{
    for (int i = 0; i < HANDS - 1; i++)
    {
        for (int j = i + 1; j < HANDS; j++)
        {
            if (cards[i].point < cards[j].point)
            {
                std::swap(cards[i], cards[j]);
            }
        }
    }
}

// to help decide if HANDS=5 cards are all of one suit
// return true if they are
// otherwise return false
bool PokerHand::isAllOneSuit() const
{
    for (int i = 1; i < HANDS; i++)
        if (cards[i].suit != cards[0].suit)
            return false;
    return true;
}

// to help decide if HANDS=5 cards are in a continuous sequence
// return true if they are
// otherwise return false
bool PokerHand::isSequence() const
{
    for (int i = 0; i < HANDS - 1; i++)
        if (cards[i].point - cards[i + 1].point != 1)
            return false;
    return true;
}
