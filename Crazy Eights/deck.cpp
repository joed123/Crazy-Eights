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

deck::deck(){
int ranks[] = {0,1,2,3,4,5,6,7,8,9,10,11,12};
int suits[] = {0,1,2,3};
n_cards = 52;
current_card = 52;
for(int i = 0; i < n_cards; i++){
        cards[i] = card(ranks[i % 13], suits[i / 13]);
        }
}


void deck::shuffle(){
    for (int f = 0; f < n_cards; f++){
        int s = (rand() + time(0)) % 52;
        card temp = cards[f];
        cards[f] = cards[s];
        cards[s] = temp;
    }
    cout << endl;
    cout << "Number of cards in the deck: " << n_cards << endl;
    cout << "This is the shuffled deck." << endl;
    for (int i = 0; i < n_cards; i++){
        cards[i].printrank();
        cards[i].printsuit();
    }
}

card deck::remove_top_card(){
    current_card = current_card - 1;
    if (current_card == 0){
        last_card = true;
    }
    else{
        last_card = false;
    }
    return cards[current_card];
}