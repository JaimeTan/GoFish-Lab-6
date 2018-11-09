GoFish
Jaime Tan Leon

I. Program Description
----------------------
The program will stimulate a Go Fish game between two players

II. File list
------------
go_fish.cpp
card.h
card.cpp
deck.h
deck.cpp
player.h
player.cpp
makefile
README.txt	Instructions and comments on the program

III. How to run the driver:
--------------------------
After you unzip the file, you will have 8 files in which you will need 7 of them in order to run the program.

You need the file to be in the same directory. While in Kamek, you use the command "make" without the quotes. 
This will create an executable file named gofish.

You can type the following command line (requires the executable name):

  ./gofish

There will be two players named Joe and Jane playing the game. 

Each player will be dealt seven cards. Each player will look at their hands and see if they can book any pairs. Joe
will go first. 

Joe will randomly pick a card from his hand to ask the other player if they have the asked card.
If Jane has the card, Joe will put it in his hand and book it. This ends his turn. If Jane does not have the card, 
she will tell Joe to Go Fish and Joe will be dealt a card. If the dealt card matches the rank of another card in his 
hand, he will book it. This will end Joe's turn. 

Jane will randomly pick a card from herhand to ask the other player if they have the asked card.
If Joe has the card, Jane will put it in his hand and book it. This ends her turn. If Joe does not have the card, 
he will tell Jane to Go Fish and Jane will be dealt a card. If the dealt card matches the rank of another card in her
hand, she will book it. This will end Jane's turn. 

Any time in which either player has zero cards in their hands, they will draw a card. These scenarios include when
the player books their pair either from the deck or player and have no cards. When the player takes the other player's last card, 
leaving them with no cards.

The game will end when all cards are dealt and there is a total of 26 books. 
