#include <iostream>
#include <string>
#include "hand.h"

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class player {
  private:
    hand Hand;
    string name;
  public:
    player();
    void card_adder(card add);
    void print_hand();
    string get_name();
    hand* get_hand();
    string return_name();
};

#endif
