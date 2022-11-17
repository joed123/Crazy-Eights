#include <iostream>
#include <string>

#ifndef CARD_H
#define CARD_H

using namespace std;

class card {
public:
        card();
        card(int ranks, int suits);
        void printsuit();
        void printrank();
        int getsuit();
        int getrank();
        void set_suit(int choose_suit);
private:
        int suit;
        int rank;
};

#endif
