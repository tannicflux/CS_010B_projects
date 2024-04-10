#include "SortedSet.h"
#include <iostream>
using namespace std;

int main() {
    // test the default constructor
    SortedSet s1;
    cout << "s1: " << s1 << endl;

    // test the copy constructor IntList
    IntList l1;
    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);
    l1.push_front(4);
    SortedSet s2(l1);
    cout << "s2: " << s2 << endl;


    // test the copy constructor SortedSet

    SortedSet s3(s2);
    cout << "s3: " << s3 << endl;

    // test the assignment operator
    s1 = s2;
    cout << "s1: " << s1 << endl;

    // test the add function
    s1.add(6);
    cout << "s1: " << s1 << endl;

    // test the push_front function
    s1.push_front(0);
    cout << "s1: " << s1 << endl;

    // test the push_back function
    s1.push_back(7);
    cout << "s1: " << s1 << endl;

    // test the insert_ordered function
    s1.insert_ordered(3);
    cout << "s1: " << s1 << endl;

    // test the operator|= function
    s1 |= s2;
    cout << "s1: " << s1 << endl;

    // test the operator&= function
    s1 &= s2;
    cout << "s1: " << s1 << endl;

}