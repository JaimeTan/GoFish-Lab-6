#include "card.h"
#include <iostream>
#include <string>

using namespace std;

//Default constructor
Card::Card(){
    myRank = 1;
    mySuit = spades;
}

//Constructor set by the passed rank and suit into their corresponding fields
Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

//Returns the card with its rank and suit. i.e. As is Ace of Spades
string Card::toString() const{
    return rankString(myRank) + suitString(mySuit);
}

//Checks if the suits are the same
bool Card::sameSuitAs(const Card& c) const{
    return mySuit == c.mySuit;
}

//returns the rank of the card
int Card::getRank() const{
    return myRank;
}

//Changes the suits into the first letter of each suit depending on the passed suit.
string Card::suitString(Suit s)      const{
    string suit;
    if(s == spades) {
        suit = 's';
    }
    else if(s == hearts) {
        suit = 'h';
    }
    else if(s == diamonds) {
        suit = 'd';
    }
    else if(s == clubs) {
        suit = 'c';
    }
    return suit;
}

//Changes the integer value of the card to a rank.
string Card::rankString(int r) const{
    string rankArray[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    string rank = rankArray[r - 1];
    return rank;
}

//Checks if the cards are the same card.
bool Card::operator == (const Card& rhs) const{
    if(mySuit == rhs.mySuit && myRank == rhs.myRank)
        return true;
    else
        return false;
}

//Checks if the cards are not the same.
bool Card::operator != (const Card& rhs) const{
    if(mySuit != rhs.mySuit || myRank != rhs.myRank)
        return true;
    else
        return false;
}

//Overload for output
ostream& operator << (ostream& out, const Card& c){
    out << c.toString();
    return out;
}
