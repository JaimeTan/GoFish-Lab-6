// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides outFile and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);
void winner(Player &p1,  Player &p2, ofstream &outFile);

int main( ) {
    ofstream outFile;
    outFile.open("gofish_results.txt");

    int numCards = 7;

    Player p1("Joe");
    Player p2("Jane");

    Card c1, c2;
    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    outFile << p1.getName() << " has : " << p1.showHand() << endl;
    outFile << p2.getName() << " has : " << p2.showHand() << endl << endl;

    //Book cards from the initial deal
    while (p1.checkHandForBook(c1, c2)) {
        p1.bookCards(c1, c2);
    }

    while (p2.checkHandForBook(c1, c2)) {
        p2.bookCards(c1, c2);
    }

    outFile << p1.getName() << "'s Books : " << p1.showBooks() << endl;
    outFile << p2.getName() << "'s Books : " << p2.showBooks() << endl << endl;


    //Actual game engine
    while (p1.getBookSize() + p2.getBookSize() != 26) {
        //PLAYER 1'S TURN
        outFile << p1.getName() << " has : " << p1.showHand() << endl;
        outFile << p2.getName() << " has : " << p2.showHand() << endl << endl;

        if(p1.getHandSize() == 0 && d.size() != 0){ //Checks if their hand is empty
            Card temp = d.dealCard();
            p1.addCard(temp);
            outFile << p1.getName() << "'s hand is empty and draws a " << temp.toString() << endl << endl;
        }

        Card askedCard = p1.chooseCardFromHand(); //Player 1 asks for the card
        Card receivedCard;
        outFile << p1.getName() << " asked - Do you have a " << askedCard.rankString(askedCard.getRank()) << "?" << endl;

        //If the other player has the same rank card, take it from their hand and book it.
        if (p2.rankInHand(askedCard)) {
            outFile << p2.getName() << " says - Yes. I have a " << askedCard.rankString(askedCard.getRank()) << "."
                 << endl;
            outFile << p1.getName() << " books the " << askedCard.rankString(askedCard.getRank()) << " . . ." << endl << endl;
            receivedCard = p2.removeCardFromHand(askedCard);
            p1.addCard(receivedCard);
            p1.checkHandForBook(c1, c2);
            p1.bookCards(c1, c2);
            if(p1.getHandSize() == 0 && d.size() != 0){ //Checks if their hand is empty
                Card temp = d.dealCard();
                p1.addCard(temp);
                outFile << p1.getName() << "'s hand is empty and draws a " << temp.toString() << endl << endl;
            }
        } else {//If the other player does not have the card, Go Fish, get dealt another card and book it if there is a pair
            outFile << p2.getName() << " says - Go Fish" << endl;

            Card temp = d.dealCard();
            p1.addCard(temp);
            outFile << p1.getName() << " draws " << temp.toString() << endl << endl;
            if (p1.checkHandForBook(c1, c2)) {
                p1.bookCards(c1, c2);
                outFile << "***** " << p1.getName() << " books the " << temp.rankString(temp.getRank()) << " . . ." << " *****" << endl << endl;
                if(p1.getHandSize() == 0 && d.size() != 0){ //Checks if their hand is empty
                    Card temp = d.dealCard();
                    p1.addCard(temp);
                    outFile << p1.getName() << "'s hand is empty and draws a " << temp.toString() << endl << endl;
                }
            }
        }
        //PLAYER 2'S TURN
        if(d.size() != 0){
            if(p2.getHandSize() == 0 && d.size() != 0){ //Checks if their hand is empty
                Card temp = d.dealCard();
                p2.addCard(temp);
                outFile << p2.getName() << "'s hand is empty and draws a " << temp.toString() << endl << endl;
            }

            //If the other player has the same rank card, take it from their hand and book it.
            askedCard = p2.chooseCardFromHand();
            outFile << p2.getName() << " asked - Do you have a " << askedCard.rankString(askedCard.getRank()) << "?" << endl;

            if (p1.rankInHand(askedCard)) {
                outFile << p1.getName() << " says - Yes. I have a " << askedCard.rankString(askedCard.getRank()) << "."
                     << endl;
                outFile << p2.getName() << " books the " << askedCard.rankString(askedCard.getRank()) << " . . ." << endl << endl;
                receivedCard = p1.removeCardFromHand(askedCard);
                p2.addCard(receivedCard);
                p2.checkHandForBook(c1, c2);
                p2.bookCards(c1, c2);
                if(p2.getHandSize() == 0 && d.size() != 0){ //Checks if their hand is empty
                    Card temp = d.dealCard();
                    p2.addCard(temp);
                    outFile << p2.getName() << "'s hand is empty and draws a " << temp.toString() << endl << endl;
                }
            } else { //If the other player does not have the card, Go Fish, get dealt another card and book it if there is a pair
                outFile << p1.getName() << " says - Go Fish" << endl;

                Card temp = d.dealCard();
                p2.addCard(temp);
                outFile << p2.getName() << " draws " << temp.toString() << endl << endl;
                if (p2.checkHandForBook(c1, c2)) {
                    p2.bookCards(c1, c2);
                    outFile << "***** " << p2.getName() << " books the " << temp.rankString(temp.getRank()) << " . . ." << " *****" << endl << endl;
                    if(p2.getHandSize() == 0 && d.size() != 0){ //Checks if their hand is empty
                        Card temp = d.dealCard();
                        p2.addCard(temp);
                        outFile << p2.getName() << "'s hand is empty and draws a " << temp.toString() << endl << endl;
                    }
                }
            }

        }

        outFile << p1.getName() << "'s Books : " << p1.showBooks() << endl;
        outFile << p2.getName() << "'s Books : " << p2.showBooks() << endl << endl;

    }

    winner(p1, p2, outFile);
    return EXIT_SUCCESS;
}

//Deal cards to the players
void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

//Checks which player has the most books and declared them the winner
void winner(Player &player1, Player &player2, ofstream &outFile){
    outFile << player1.getName() << " has " << player1.getBookSize() << " books" << endl;
    outFile << player2.getName() << " has " << player2.getBookSize() << " books" << endl;

    if(player1.getBookSize() > player2.getBookSize()){
        outFile << endl << player1.getName() << " wins!" << endl;
    }else if(player1.getBookSize() < player2.getBookSize()){
        outFile << endl << player2.getName() << " wins!" << endl;
    }else if(player1.getBookSize() == player2.getBookSize()){
        outFile << endl << "The game is a tie!" << endl;
    }
}