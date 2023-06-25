/* File: rank.cpp
 * Course: CS216-00x
 * Project: Lab 10 (as part of Project 2)
 * Purpose: the implementation of member functions for the Rank class.
 *
 */
#include <iostream>
#include <sstream>
#include <iomanip>
#include "rank.h"

using namespace std;

// Default constructor.
Rank::Rank()
{
    kind = hRanks::NoRank;
    point = 0;
}

// Alternate constructor.
// Create a Rank object with specified ranking name and points.
Rank::Rank(hRanks r, rPoints p)
{
    kind = r;
    point = p;
}

// access the hand ranking kind
Rank::hRanks Rank::getKind() const
{
    return kind;
}

// access the card point value of the corresponding ranking kind
Rank::rPoints Rank::getPoint() const
{
    return point;
}

// Display a description of the hand-ranking category to standard output.
// The output should look like:
//   FourOfAKind( 4)
//   FullHouse(10)
//   Flush( A)
//   ...
void Rank::print() const
{
    const int POINTMIN = 2;
    const int POINTMAX = 14;
    const int POINTLETTER = 10;
    if (point < POINTMIN || point > POINTMAX)
    {
        cout << "Invalid card value!" << endl;
        return;
    }

    // your code start here...
    string num = to_string(int(point));
    if(num == "14") num = "A";
    else if(num == "11") num = "J";
    else if(num == "12") num = "Q";
    else if(num == "13") num = "K";
    cout << RANK_NAMES[int(kind)] << "(" << num << ")" << endl;








}

