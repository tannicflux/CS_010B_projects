#include <iostream>
#include <cmath>
using namespace std;

#include "Card.h"//

Card::Card() {
    suit = 'c';
    rank = 2;
}

Card::Card(char s, int r) {
    if (s == 'c' || s == 'C'){
        suit = 'c';
    }
    else if (s == 'd' || s == 'D'){
        suit = 'd';
    }
    else if (s == 'h' || s == 'H'){
        suit = 'h';
    }
    else if (s == 's' || s == 'S'){
        suit = 's';
    }
    else {
        suit = 'c';
    }
    if (r >= 1 && r <= 13) {
        rank = r;
    } else {
        rank = 2;
    }
}

char Card::getSuit() const {
    return suit;
}

int Card::getRank() const {
    return rank;
}

ostream & operator<<(ostream & out, const Card & c) {
    if (c.rank == 1) {
        out << "Ace";
    }
    else if (c.rank == 11) {
        out << "Jack";
    }
    else if (c.rank == 12) {
        out << "Queen";
    }
    else if (c.rank == 13) {
        out << "King";
    }
    else {
        out << c.rank;
    }
    out << " of ";
    if (c.suit == 'c') {
        out << "Clubs";
    } else if (c.suit == 'd') {
        out << "Diamonds";
    } else if (c.suit == 'h') {
        out << "Hearts";
    } else if (c.suit == 's') {
        out << "Spades";
    }
    return out;
}
