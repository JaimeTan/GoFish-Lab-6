//File Name: card.h
//
//Written by Owen Astrachan and Roger Priebe
// This class represents a playing card, i.e., "ace of spades"
// a Card is constructed from a rank (int in range 1..13)
// and a suit (Card::spades, Card::hearts, Card::diamonds,
// Card::clubs)
//
// Cards should be created by a Deck (see deck.h), a Deck returns
// good cards
// The function toString() converts a card to a string, e.g., to print
//
// Accessor functions include
//
// int GetRank()      -- returns 1, 2, ..., 13 for ace, two, ..., king
//
// bool SameSuitAs(c) -- returns true if same suit as Card c
//
// string suitString() -- returns "s", "h", "d" or "c"
//
// Note that the Ace is represented by 1 and the King by 13

#ifndef _CARD_H
#define _CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card
{
public:

    //Defines the suits of a deck and be able to use them as their actual names
    enum Suit {spades, hearts, diamonds, clubs};

    //Default constructor
    //set the myRank to 1 and mySuit to spades
    Card();          // default, ace of spades


    //Constructor
    //set the myRank to the passed rank and mySuit to passed Suit
    Card(int rank, Suit s);


    /* FUNCTION - string toString
     * returns the rank and suit of a card in string form

     precondition: none

     input parms - rankString and suitString
     output parms -  rankString + suitString); i.e As (Ace of Spades)
    */
    string toString()              const;  // return string version e.g. Ac 4h Js


    /* FUNCTION - bool sameSuitAs
     * returns true if the current hand's suit same as c

     precondition: none

     input parms - passed Card
     output parms - returns true if the suit is same else false.
    */
    bool sameSuitAs(const Card& c) const;  // true if suit same as c


    /* FUNCTION - int  getRank
     * returns the rank of the card

     input parms - none
     output parms - returns the rank of the current card
    */
    int  getRank()                 const;  // return rank, 1..13


    /* FUNCTION - string suitString
     * returns the suit of the card => {s, h, d, c}

     input parms - A Suit
     output parms - returns the suit of a card =>{s, h, d, c}
    */
    string suitString(Suit s)      const;  // return "s", "h",...


    /* FUNCTION - string rankString
     * returns the rank of the card => {"A","2","3","4","5","6","7","8","9","10","J","Q","K"}

     input parms - the integer value of the card
     output parms - returns the rank of a card =>{"A","2","3","4","5","6","7","8","9","10","J","Q","K"}
    */
    string rankString(int r)       const;  // return "A", "2", ..."Q"

    // for != and ==  use the rank and suit to determine if the card is same or not
    // Takes two cards RHS and LHS to compare.
    bool operator == (const Card& rhs) const;
    bool operator != (const Card& rhs) const;

private:

    int myRank;
    Suit mySuit;


};

ostream& operator << (ostream& out, const Card& c);



#endif