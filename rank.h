/* File: rank.h
 * Course: CS216-00x
 * Project: Lab 10 (as part of Project 2)
 * Purpose: the declaration for the Rank class.
 *** DO NOT CHANGE THIS FILE ***
 *
 */

#ifndef RANK_H
#define RANK_H

#include <iostream>

using namespace std;

// define the static array of the names of ranking categories for display purpose
static const char* const RANK_NAMES[] ={"NoRank", "HighCard", "Pair", "ThreeOfAKind","Straight",
   "Flush", "FullHouse", "FourOfAKind", "StraightFlush" };

// class declaration of Rank class
class Rank
{
    public:
        // Type definition for the hand-ranking categories in poker.
        // A rank of NoRank means the Rank object has not been initialized.
        //
        // Note: outside Rank member functions, refer this type using Rank::hRanks, 
        // and use constants Rank::hRanks::HighCard, Rank::hRanks::Pair, ...
        //
        enum class hRanks { NoRank, HighCard, Pair, ThreeOfAKind,Straight,
            Flush, FullHouse, FourOfAKind, StraightFlush };

        // Type definition for the point value of a hand-ranking categories
        // A point value of 0 means the Rank object has not been initialized.
        // Jack = 11, Queen = 12, King = 13, Ace = 14.
        // A point value of 1 is not used.
        // 
        // Note: outside Rank member functions, refer this type using Rank::rPoints
        //
        typedef unsigned int rPoints;

        // Default constructor.
        Rank(); 

        // Alternate constructor.
        // Create a Rank object with specified ranking name and points.
        // The alternate constructor should make sure that
        // the values of the arguments are valid.
        // If invalid arguments are given, a Rank object should
        // be created with NoRank for its ranking name and 0 for its points.
        //
        Rank(hRanks r, rPoints p);

        // access the hand ranking kind
        hRanks getKind() const;

        // access the card point value of the corresponding ranking kind
        rPoints getPoint() const;

        
        // Display a description of the hand-ranking category to standard output.
        // The output should look like:
        //   StraightFlush( J)
        //   FourOfAKind( 4)
        //   FullHouse( K)
        //   Flush( A)
        //   ThreeOfAKind(10)
        //   ...
        //
        void print() const;

        // Assign friendship to class named PokerHand
        friend class PokerHand;

    private:
        hRanks  kind;   // hand-ranking kind
        rPoints point;  // card value of each ranking category
};
#endif  /* RANK_H */
