#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "Deck.h"
#include "Card.h"

Deck::Deck() {
    vector<char> cardSuit = {'s', 'h', 'd', 'c'};
    for (auto &suit : cardSuit) {
        for (int i = 13; i > 0; i--) {
            theDeck.push_back(Card(suit, i));
        }
    }
}

Card Deck::dealCard() {
    Card c = theDeck.back();
    theDeck.pop_back();
    dealtCards.push_back(c);
    return c;
}

void Deck::shuffleDeck() {

    for(unsigned int i = 0; i < dealtCards.size(); i++){
        theDeck.push_back(dealtCards.at(i));
    }
    dealtCards.clear();  // Clear the dealt cards instead of moving them back
    random_shuffle(theDeck.begin(), theDeck.end());

    


}

unsigned Deck::deckSize() const {
    return theDeck.size();
}
