#include "deck.h"
#include "card.h"
#include "player.h"
#include <ctime>
#include <cstdlib>

using namespace std;

//Creates the deck of cards from spades to clubs in order.
Deck::Deck(){
    unsigned int currentTime =  (unsigned)time(NULL);
    srand(currentTime); //Grabs the current time in milliseconds
    myIndex = SIZE;
    int count = 0;

    for(int i = 0; i < 4; i++){
        for (int j = 0; j < 13; j++){
            if (i == 0){
                myCards[count] = Card(j+1, Card::spades);
            }
            if (i == 1){
                myCards[count] = Card(j+1, Card::hearts);
            }
            if (i == 2){
                myCards[count] = Card(j+1, Card::diamonds);
            }
            if (i == 3){
                myCards[count] = Card(j+1, Card::clubs);
            }

            count++;
        }
    }
}

//Shuffles the deck 2n where n is the number of cards which is 52
void Deck::shuffle(){
    int shuffleTimes = 2 * SIZE;

    while(shuffleTimes != 0){

        int randCard1 = (rand() % SIZE);
        int randCard2 = (rand() % SIZE);

        Card temp = myCards[randCard1];
        myCards[randCard1] = myCards[randCard2];
        myCards[randCard2] = temp;

        shuffleTimes--;
    }
}

//Deals the next card on the deck and decreases the index of the deck for the next card
Card Deck::dealCard(){
    Card returnCard(0,Card::Suit(0));

    if(size() > 0){
        returnCard = myCards[myIndex - 1];
        myIndex--;
        return returnCard;
    }
}

//Returns the current number of cards left in the deck
int Deck::size() const{
    return myIndex;
}

