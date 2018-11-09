// FILE: deck.h
// written by Owen Astrachan and Roger Priebe
// this class respresents a deck of cards
// When a Deck is constructed, it contains 52 cards
// in a "regular" order (aces, twos, threes, ... , kings)
//
// Shuffling a deck will randomize whatever cards are in the deck
// Do not shuffle if you have less than 2 cards
//
// dealCard() returns a card from the deck and decreases the
// number of cards in the deck (returned by size())
// The idea is that after shuffling, calling dealCard() 52 times
// returns each card in the deck after shuffling.
//

#ifndef _DECK_H
#define _DECK_H

#include "card.h"


class Deck
{
    static const int SIZE = 52;

public:

    //Default constructor that creates 52 cards
    //It creates the 13 cards for spades, hearts, diamonds, and clubs, respectively
    Deck();           // pristine, sorted deck

    /* FUNCTION - void shuffle
    *  shuffles the cards into random order

      input parms - none
      output parms - none, just shuffles the desk
   */

    void shuffle();   // shuffle the cards in the current deck

    /* FUNCTION - Card dealCard
    *  Deals the current card according to myIndex, does not return a
     *  card if the deck is empty (myIndex is at 0)

      input parms - none
      output parms - returns the dealt card from the deck
   */
    Card dealCard();   // get a card, after 52 are dealt, fail

    /* FUNCTION - int  size
    *  returns the size of the deck

      input parms - none
      output parms - returns myIndex
   */
    int  size() const; // # cards left in the deck


private:

    Card myCards[SIZE]; //The Deck
    int myIndex;  // current card to deal
};

#endif