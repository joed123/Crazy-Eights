#include <iostream>
#include <string>
#include "card.h"

#ifndef DECK_H
#define DECK_H

using namespace std;

class deck {
public:
        bool last_card;
        deck();
        void shuffle();
        card remove_top_card();
        int current_card;
        void print_top_card();
private:
        int n_cards;
        card cards[52];
};

#endif