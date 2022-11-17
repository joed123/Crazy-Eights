#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "game.h"

using namespace std;

card::card() {
}


card::card(int ranks, int suits) {
        rank = ranks;
        suit = suits;
}


int card::getsuit(){
    return suit;
}
int card::getrank(){
    return rank;
}



void card::printsuit(){
    string currentsuit;
	if (suit == 0){
		currentsuit = " clubs.";
        cout << " of" << currentsuit << endl;
    }
	else if (suit == 1){
		currentsuit = " diamonds.";
         cout << " of" << currentsuit << endl;
    }	
	else if (suit == 2){
		currentsuit = " hearts.";
         cout << " of" << currentsuit << endl;
    }	
    else if (suit == 3){
		currentsuit = " spades.";
        cout << " of" << currentsuit << endl;
    }	
    else {
        cout << "This is a bad value at suit: " << suit << endl;
    }
}

void card::printrank(){
      string currentrank;
	if (rank == 0){
		currentrank = "Ace";
        cout << currentrank;
    }
	else if (rank == 1){
		currentrank = "2";
         cout << currentrank;
    }	
	else if (rank == 2){
		currentrank = "3";
         cout << currentrank;
    }	
	else if (rank == 3){
		currentrank = "4";
         cout << currentrank;
    }	
	else if (rank == 4){
		currentrank = "5";
         cout << currentrank;
    }	
	else if (rank == 5){
		currentrank = "6";
         cout << currentrank;
    }	
	else if (rank == 6){
		currentrank = "7";
         cout << currentrank;
    }	
	else if (rank == 7){
		currentrank = "8";
         cout << currentrank;
    }	
	else if (rank == 8){
		currentrank = "9";
         cout << currentrank;
    }	
	else if (rank == 9){
		currentrank = "10";
         cout << currentrank;
    }	
	else if (rank == 10){
		currentrank = "Jack";
        cout << currentrank;
    }	
	else if (rank == 11){
		currentrank = "Queen";
         cout << currentrank;
    }
	else if (rank == 12){
		currentrank = "King";
        cout << currentrank;
	}
    else {
        cout << "This is a bad value at rank: " << rank << endl;
    }
}


void card::set_suit(int choose_suit){
    suit = choose_suit;
}