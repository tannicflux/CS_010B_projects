#include "IntVector.h"
#include <iostream>


using namespace std;



int main() {
    // Test Constructor
    IntVector v1( 10);  // Create IntVector with size 5, all elements initialized to 10

    // Destructor, Mutators, & Private Helper Functions
    v1.expand();
    v1.expand(5);
    v1.insert(2, 3);
    cout << v1.at(2) << endl;
    v1.erase(2);
    cout << v1.at(2) << endl;
    v1.push_back(5);
    v1.pop_back();
    v1.clear();
    v1.resize(5, 3);
    v1.reserve(5);
    v1.assign(5, 4);
    v1.at(2);
    cout << v1.front() << endl;
    cout << v1.back() << endl;

    // Accessors

    cout << v1.size() << endl;
    cout << v1.capacity() << endl;
    cout << v1.empty() << endl;
    cout << v1.at(2) << endl;
    cout << v1.front() << endl;
    cout << v1.back() << endl;

    return 0;
}
