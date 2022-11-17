#include <iostream>
#include <string>
#include "card.h"

#ifndef HAND_H
#define HAND_H

using namespace std;

class hand {
public:
        int current_card;
        int match_card;
        hand();
        void increase_size();
        void deal();
        void add_card(card add);
        void print_hand();
        card allocate_space();
        hand get_hand();
        card* get_cards();
        bool compare_top_card(card top_card);
        bool remove_matched_card();
        ~hand();
private:
        int n_cards;
        card* cards;
        card addcard;
};

#endif