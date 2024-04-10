#include <iostream>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards passed in contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &hand){
    for (unsigned i = 0; i < hand.size(); i++) {
        for (unsigned int j = i + 1; j < hand.size(); j++) {
            if (hand[i].getRank() == hand[j].getRank()) {
                return true;
            }
        }
    }
    return false;

}

// Sends to output stream a hand of Cards on a single line,
// each Card separated by a comma.
// If the vector is empty, do not output anything.
// Example (vector size of 3): Ace of Spades, Two of Hearts, King of Clubs 
ostream & operator<<(ostream &out, const vector<Card> &handOfCards) {
    
    if (handOfCards.size() == 0) {
        return out;
    }
    else{
        for (unsigned int i = 0; i < handOfCards.size()-1; i++) {
            out << handOfCards.at(i) << ", ";
        }
        out << handOfCards.at(handOfCards.size()-1);
    }
    return out;
}

int main() {
    srand(2222);
    string outputToFile;
    cout << "Do you want to output all hands to a file?(Yes/No) ";
    cin >> outputToFile;

    ofstream outFile;
    if (outputToFile == "Yes") {
        string fileName;
        cout << "Enter name of output file: ";
        cin >> fileName;
        outFile.open(fileName);
    }

    int numCards, numDeals;
    cout << "Enter number of cards per hand: ";
    cin >> numCards;
    cout << "Enter number of deals (simulations): ";
    cin >> numDeals;

    int pairCount = 0;
    Deck d;

    for (int i = 0; i < numDeals; i++) {
        
        
        d.shuffleDeck();
        vector<Card> hand;
        for (int j = 0; j < numCards; j++) {
            hand.push_back(d.dealCard());
        }
        if (hasPair(hand)) {
            pairCount++;
            if(outputToFile == "Yes"){
                outFile << "Found Pair!! ";
            }
        }
        else{
            if(outputToFile == "Yes"){
            outFile << "             ";
            }
        }
        if (outputToFile == "Yes") {

            outFile << hand << endl;
        }
    }
    

    cout << "Chances of receiving a pair in a hand of " << numCards << " cards is: " << (static_cast<double> (pairCount) / numDeals)*100 << "%" << endl;
    if (outputToFile == "Yes") {
        outFile.close();
    }

    return 0;
}