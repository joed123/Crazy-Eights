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

bool hand::compare_top_card(card top_card){
    for (int i = 0; i < current_card; i++){
        if (cards[i].getrank() == top_card.getrank()){
            match_card = i;
            return true;
        }
        else if (cards[i].getsuit() == top_card.getsuit()){
            match_card = i;
            return true;
        }
        else if (cards[i].getrank() == 7){
            int choose_suits = 4;
            while (choose_suits == 4){
            cout << endl;
            cout << "What would you like the new suits for crazy 8 to be (0 for clubs, 1 for diamonds, 2 for hearts, 3 for spades)" << endl;
            cin >> choose_suits;
            if ((choose_suits == 0) or (choose_suits == 1) or (choose_suits == 2) or (choose_suits == 3)){
                cards[i].set_suit(choose_suits);
            }
            else{
                cout << endl;
                cout << "Invalid input please enter again!" << endl;
                choose_suits = 4;
            }
        }
            match_card = i;
            return true;
        }
    }
    return false;
}

hand::hand() {
    current_card = 0;
}

bool hand::remove_matched_card(){
  current_card--;
  if (current_card == 0){
      return false;
  }
  card* temp = new card[current_card];
  for (int i = 0; i < current_card; i++) {
      temp[i] = allocate_space();
  }
  int j = 0;
  for (int i = 0; i < current_card + 1; i++) {
      if (i != match_card){
        temp[j] = cards[i];
        j++;
      }
  }
  delete[] cards;
  cards = nullptr;
  cards = new card[current_card];
  for (int i = 0; i < current_card; i++) {
      cards[i] = allocate_space();
  }
  for (int i = 0; i < current_card; i++) {
   cards[i] = temp[i];
  }
  delete[] temp;
  temp = nullptr;
  return true;
  }

  void hand::add_card(card add){
    cards[current_card] = card(add.getrank(), add.getsuit());
    current_card++;
}

void hand::print_hand(){
    for (int i = 0; i <= current_card - 1; i++){
        cards[i].printrank();
        cards[i].printsuit();
    }

}

card* hand::get_cards(){
    return cards;
}


card hand::allocate_space(){
 card i;
    return i;
}


void hand::increase_size() {
    if (current_card == 0){
    cards = new card[current_card + 1];
    cards[current_card] = allocate_space();
    }
  else {
  card* temp = new card[current_card + 1];
  for (int i = 0; i < current_card + 1; i++) {
      temp[i] = allocate_space();
  }
  for (int i = 0; i < current_card; i++) {  
    temp[i] = cards[i];
  }
  delete[] cards;
  cards = nullptr;
  cards = new card[current_card + 2];
  for (int i = 0; i < current_card + 2; i++) {
      cards[i] = allocate_space();
  }
  for (int i = 0; i < current_card + 1; i++) {
   cards[i] = temp[i];
  }
  delete[] temp;
  temp = nullptr;
  }
}

hand::~hand() {
	if(cards) {
		delete [] cards;
		cards = nullptr;
    }
}