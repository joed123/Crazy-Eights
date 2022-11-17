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

string player::get_name(){
    cout << endl;
    cout << "What would you like your name to be?" << endl;
    cin >> name;
return name;
}
string player::return_name(){
return name;
}

hand* player::get_hand(){
    return &Hand;
}


player::player() {
}

void player::card_adder(card add){
    Hand.increase_size();
    Hand.add_card(add);
}