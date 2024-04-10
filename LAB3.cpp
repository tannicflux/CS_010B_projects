#include <iostream>
#include <vector>
// FIXME include vector library
using namespace std;

// parameter order will always be jersey #s then ratings
void outputRoster(const vector<int> &jerseyNumbers, const vector<int> &ratings){
    cout << "ROSTER\n";
    for (unsigned int i = 0; i < jerseyNumbers.size(); i++){
        cout << "Player " << i+1 << " -- Jersey number: " << jerseyNumbers.at(i) << ", Rating: " << ratings.at(i) << endl;
    }
}
void addPlayer(vector<int> &jerseyNumbers, vector<int> &ratings){
    int jerseyNumber;
    int rating;
    cout << "Enter another player's jersey number: \n";
    cin >> jerseyNumber;

    jerseyNumbers.push_back(jerseyNumber);

    cout << "Enter another player's rating: \n";
    cin >> rating;

    ratings.push_back(rating);

}
void removePlayer(vector<int> &jerseyNumbers, vector<int> &ratings){
    int jersey;
    int index;
    cout << "Enter a jersey number: \n";
    cin >> jersey;

    for(unsigned int i =0; i < jerseyNumbers.size(); i++){
        if (jersey == jerseyNumbers.at(i)){
            index = i;
        }
    }
    // 1,2,3
    for(unsigned int j = index; j < jerseyNumbers.size()-1; j++)
    {
            jerseyNumbers.at(j) = jerseyNumbers.at(j+1);
            ratings.at(j) = ratings.at(j+1);
        }
    jerseyNumbers.pop_back();
    ratings.pop_back();
}


void updatePlayerRating(const vector<int> &jerseyNumbers, vector<int> &ratings){
    int jersey;
    int rating;
    cout << "Enter a jersey number: \n";
    cin >> jersey;
    cout << "Enter a new rating for player: \n";
    cin >> rating;

    for (unsigned int i = 0;  i < jerseyNumbers.size(); i++){
        if(jersey == jerseyNumbers.at(i)){
            ratings.at(i) = rating;
        }
    }
}
void outputPlayersAboveRating(const vector<int> &jerseyNumbers, const vector<int> &ratings){
    int rating;
    cout << "Enter a rating: \n\n";
    cin >> rating;
    cout << "ABOVE " << rating << endl;
    for (unsigned int i = 0; i < ratings.size(); i++){
        if(ratings.at(i) > rating){
            cout << "Player " << i+1 << " -- Jersey number: "<< jerseyNumbers.at(i) << ", Rating: " << ratings.at(i) << endl; 
        }
    }
}


int main() {
    vector<int> jerseyNumbers;
    vector<int> ratings;
    int jerseyNumber;
    int rating;
    char userInput;


   for (unsigned int i = 1; i < 6; i++){
       cout << "Enter player " << i << "'s jersey number: \n";
       cin >> jerseyNumber;
       jerseyNumbers.push_back(jerseyNumber);
       cout << "Enter player " << i << "'s rating: \n";
       cin >> rating;
       ratings.push_back(rating);
       cout << endl;
    }

    cout << "ROSTER\n";
    for (unsigned int i = 0; i < jerseyNumbers.size(); i++){
        cout << "Player " << i+1 << " -- Jersey number: " << jerseyNumbers.at(i) << ", Rating: " << ratings.at(i) << endl;
    }

    cout << "\nMENU\na - Add player\nd - Remove player\nu - Update player rating\nr - Output players above a rating\no - Output roster\nq - Quit\n\nChoose an option: \n";
    cin >> userInput;

    while (userInput != 'q'){
        if (userInput == 'o'){
            outputRoster(jerseyNumbers, ratings);
        }

        else if (userInput == 'a'){
            addPlayer(jerseyNumbers, ratings);
        }

        else if(userInput == 'd'){
            removePlayer(jerseyNumbers, ratings);
        }

        else if (userInput == 'u'){
            updatePlayerRating(jerseyNumbers, ratings);
        }
        else if(userInput == 'r'){
            outputPlayersAboveRating(jerseyNumbers, ratings);
        }
        cout << "\nMENU\na - Add player\nd - Remove player\nu - Update player rating\nr - Output players above a rating\no - Output roster\nq - Quit\n\nChoose an option: \n";
        cin >> userInput;
    }


   return 0;
}
