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

game::game() {
    num_cards_on_pile = 0;
    cards.shuffle();
    deal(cards, players[0], 7);
    deal(cards, players[1], 7);
    string fisrtname = players[0].get_name();
    cout << endl;
    cout << "This is " << fisrtname << "'s hand." << endl;
    players[0].get_hand()->print_hand();
    cout << endl;
    cout << "This is the computers hand." << endl;
    players[1].get_hand()->print_hand();
    cout << endl;
    add_to_pile();
    string name1 = players[0].return_name();
    play_game();
    if (players[1].get_hand()->current_card < players[0].get_hand()->current_card){
    cout << "Game over! Computer won!" << endl;
}
    else{
        cout << "Game over! " << name1 << " won!" << endl;
    }
}

void game::add_match_to_pile(card add){
    increase_pile_size();
    pile[num_cards_on_pile] = card(add.getrank(), add.getsuit());
    num_cards_on_pile++;
}

void game::play_game(){
bool win = false;
int i = 0;
bool second_time;
bool first_time;
bool compare1;
bool compare2;
string name1 = players[0].return_name();
    while (win == false){
        first_time = true;
        while (first_time == true){
        cout << endl;
        cout << "This is the top card before " << name1 << "'s turn: " << endl;
        print_top_card();
        cout << endl;
        cout << name1 << "'s printed hand before turn is: " << endl;
        players[0].get_hand()->print_hand();
        compare1 = players[0].get_hand()->compare_top_card(pile[num_cards_on_pile - 1]);
        if (compare1){
            add_match_to_pile(players[0].get_hand()->get_cards()[players[0].get_hand()->match_card]);
            if (players[0].get_hand()->remove_matched_card()){
            first_time = false;
            }
            else{
                cout << endl;
                cout << name1 <<"'s out of cards! " << endl;
                return;
            }
        }
        else{
            if (cards.last_card == false){
            deal(cards, players[0], 1);
            first_time = true;
            }
            else{
                cout << "Deck is out of cards on " << name1 << "'s turn." <<  endl;
                first_time = false;
                win = true;
            }
        }
        cout << endl;
        cout << name1 << "'s printed hand after turn is: " << endl;
        players[0].get_hand()->print_hand();
        }
        second_time = true;
        while (second_time == true){
        cout << endl;
        cout << "This is the top card before the computer's turn: " << endl;
        print_top_card();
        cout << endl;
        cout << "Computer's printed hand before turn is: " << endl;
        players[1].get_hand()->print_hand();
        compare2 = players[1].get_hand()->compare_top_card(pile[num_cards_on_pile - 1]);
        if (compare2){
            add_match_to_pile(players[1].get_hand()->get_cards()[players[1].get_hand()->match_card]);
            if (players[1].get_hand()->remove_matched_card()){
            second_time = false;
            }
            else{
                cout << endl;
                cout << "The computer is out of cards!" << endl;
                return;
            }
        }
        else{
            if (cards.last_card == false){
                deal(cards, players[1], 1);
            second_time = true;
            }
            else{
                cout << endl;
                cout << "Deck is out of cards on the computers turn." << endl;
                second_time = false;
                win = true;
            }
        }
        cout << endl;
        cout << "Computer's printed hand after turn is: " << endl;
        players[1].get_hand()->print_hand();
        }
        i++;
    }

}

void game::print_top_card(){
    pile[num_cards_on_pile - 1].printrank();
    pile[num_cards_on_pile - 1].printsuit();
}

card game::allocate_space(){
 card i;
    return i;
}



void game::increase_pile_size(){
    if (num_cards_on_pile == 0){
    pile = new card[num_cards_on_pile + 1];
    pile[num_cards_on_pile] = allocate_space();
    }
  else {
  card* temp = new card[num_cards_on_pile + 1];
  for (int i = 0; i < num_cards_on_pile + 1; i++) {
      temp[i] = allocate_space();
  }
  for (int i = 0; i < num_cards_on_pile; i++) { 
    temp[i] = pile[i];
  }
  delete[] pile;
  pile = nullptr;
  pile = new card[num_cards_on_pile + 2];
  for (int i = 0; i < num_cards_on_pile + 2; i++) {
      pile[i] = allocate_space();
  }
  for (int i = 0; i < num_cards_on_pile + 1; i++) {
   pile[i] = temp[i];
  }
  delete[] temp;
  temp = nullptr;
  }
}
void game::add_to_pile(){
    increase_pile_size();
    card add = cards.remove_top_card();
    pile[num_cards_on_pile] = card(add.getrank(), add.getsuit());
    num_cards_on_pile++;
}

void game::deal(deck &d, player &p, int num_cards){
    for (int i = 0; i < num_cards; i++){
        p.card_adder(d.remove_top_card());
    }
}