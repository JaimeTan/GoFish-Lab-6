// FILE:  player.h
// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>
#include <vector>


#include "card.h"
using namespace std;


class Player
{
public:
    //Default constructor
    //    //Set the name to null
    Player();

    //Constructor
    //Set the name to passed name
    Player(string name) {
        myName = name;
    }

    /* FUNCTION - string getName
     * returns the name of the player

     input parms - none
     output parms -  returns the name of the player
    */
    string getName() const {
        return myName;
    }

    /* FUNCTION - addCard(Card c)
    * returns the passed card into the player's hand

    input parms - none
    output parms -  none, the card is added to the hand
   */
    void addCard(Card c);  //adds a card to the hand

    /* FUNCTION - bookCards(Card c1, Card c2);
    * books the two passed cards into the player's Books and removes from hand

    input parms - none
    output parms -  none, books the two cards into the player's books
   */
    void bookCards(Card c1, Card c2);


    // FUNCTION - checkHandForBook(Card &c1, Card &c2);
    //this function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

    //input parms - addresses of two temp cards
    //output parms - returns true if there is a pair, false otherwise

    bool checkHandForBook(Card &c1, Card &c2);

    // FUNCTION -  bool rankInHand(Card c) const;
    //Does the player have a card with the same rank as c in her hand?
    //returns true the same rank is in their hand, false otherwise

    //input parms - a Card
    //output parms - returns true if the same rank is in the hand, false otherwise
    bool rankInHand(Card c) const;

    //FUNCTION -  Card chooseCardFromHand()
    //Randomizes a number to choose a card from the hand and returns that card

    //input parms - none
    //output parms - returns the randomized card
    Card chooseCardFromHand() const;


    //FUNCTION -  bool cardInHand(Card c) const;
    //returns true of the card is in the player's hand, false otherwise

    //input parms - a Card
    //output parms - returns true of the card is in the player's hand, false otherwise
    bool cardInHand(Card c) const;

    //FUNCTION -  Card removeCardFromHand(Card c)
    //removes the card from the player's hand and returns the removed card

    //input parms - a Card
    //output parms - removes the card from the player's hand and returns the removed card
    Card removeCardFromHand(Card c);

    //FUNCTION -  string showHand() const
    //displays the player's hand with vector

    //input parms - none
    //output parms - displays the player's hand with vector
    string showHand() const;


    //FUNCTION -  string showBooks() const
    //displays the player's books with vector

    //input parms - none
    //output parms - displays the player's books with vector
    string showBooks() const;

    //FUNCTION -  int getHandSize() const
    //returns the number of cards in the player's hands

    //input parms - none
    //output parms - returns the number of cards in the player's hands
    int getHandSize() const;

    //FUNCTION -  int getBookSize() const
    //returns the number of pair of books in the player's book

    //input parms - none
    //output parms - returns the number of pair of books in the player's book
    int getBookSize() const;

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

//    bool checkHandForPair(Card &c1, Card &c2);

    //OPTIONAL
    // comment out if you decide to not use it
    //Does the player have a card with the same rank as c in her hand?
    //e.g. will return true if the player has a 7d and the parameter is 7c

    bool sameRankInHand(Card c) const;

private:

    vector <Card> myHand;
    vector <Card> myBook;

    string myName;

};


#endif