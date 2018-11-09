#include "player.h"
#include "card.h"
#include "deck.h"
#include <algorithm>
#include <iterator>

using namespace std;

//Default constructor: Set the name to null
Player::Player(){
    myName = "";
}

//Adds the card into the player's hand
void Player::addCard(Card c){
    myHand.push_back(c);
}

//books the two passed cards into the player's Books and removes them from hand
void Player::bookCards(Card c1, Card c2){
    myBook.push_back(c1);
    myBook.push_back(c2);
    removeCardFromHand(c1);
    removeCardFromHand(c2);
}

//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
bool Player::checkHandForBook(Card &c1, Card &c2){
    vector<Card>::iterator iter1;
    vector<Card>::iterator iter2;

    //Uses two iterators to check the hand.
    for (iter1 = myHand.begin() ; iter1 != myHand.end() - 1; iter1++){
        for (iter2 = iter1 + 1; iter2 != myHand.end(); iter2++){
            if ((*iter1).getRank() == (*iter2).getRank())
            {
                c1 = *iter1;
                c2 = *iter2;
                return true;
            }
        }
    }
    return false;
}

//returns true if the same rank is in the hand, false otherwise using vector loops
bool Player::rankInHand(Card c) const{
    vector<Card>::const_iterator iter;

    for (iter = myHand.begin(); iter != myHand.end(); iter++){
        if (c.getRank() == (*iter).getRank()){
            return true;
        }
    }

    return false;
}

//Randomizes a number from the hand size to choose a card from the hand and returns that card
Card Player::chooseCardFromHand() const{
    int randIndex = (rand() % getHandSize());
    return myHand.at(randIndex);
}

//returns true of the card is in the player's hand, false otherwise
bool Player::cardInHand(Card c) const{
    vector<Card>::const_iterator iter;

    for (iter = myHand.begin(); iter != myHand.end(); iter++){
        if ((*iter) == c){
            return true;
        }
    }

    return false;
}

//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c){
    vector<Card>::iterator iter;
    Card removedCard;

    for (iter = myHand.begin(); iter != myHand.end(); iter++){
        if ((*iter).getRank() == c.getRank()) {
            removedCard = (*iter);
            myHand.erase(iter);
            return removedCard;
        }
    }

}

//displays the player's hand with a vector loop
string Player::showHand() const{
    string handString = "";
    string cardString = "";
    vector<Card>::const_iterator iter;

    for(iter = myHand.begin(); iter != myHand.end(); iter++) {
        cardString = (*iter).toString();
        handString = handString + cardString + " ";
    }

    return handString;
}

//displays the player's books with a vector loop
string Player::showBooks() const{
    string bookString = "";
    string cardString = "";
    vector<Card>::const_iterator iter;

    for(iter = myBook.begin(); iter != myBook.end(); iter++) {
        cardString = (*iter).toString();
        bookString = bookString + cardString + " ";
    }

    return bookString;
}

//returns the number of cards in the player's hand
int Player::getHandSize() const{
    return myHand.size();
}

//returns the number of books in the player's books
int Player::getBookSize() const{
    return (myBook.size()/2);
}

//If a pair is found, it returns true, otherwise false
bool Player::sameRankInHand(Card c) const{
    vector<Card>::const_iterator iter;

    for (iter = myHand.begin(); iter != myHand.end(); iter++){
        if ((*iter).getRank() == (c.getRank())){
            return true;
        }
    }

    return false;
}
