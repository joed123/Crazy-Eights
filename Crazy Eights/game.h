#include <iostream>
#include <string>
#include "deck.h"
#include "player.h"

#ifndef GAME_H
#define GAME_H

using namespace std;

class game {
  private:
    deck cards;
    player players[2];

  public:
    card* pile;
    int num_cards_on_pile;
    game();
    void deal(deck &d, player &p, int num_cards);
    void increase_pile_size();
    card allocate_space();
    void add_to_pile();
    void compare_top_card(player &p);
    void print_top_card();
    void play_game();
    void add_match_to_pile(card add);
};

#endif
