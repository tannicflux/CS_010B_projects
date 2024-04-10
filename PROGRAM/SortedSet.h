//
// Created by danis on 2/28/2024.
//

#ifndef LAB_7__INTLIST_INTRO_SORTEDSET_H
#define LAB_7__INTLIST_INTRO_SORTEDSET_H

#include "IntList.h"
#include <ostream>

using namespace std;

class SortedSet : public IntList {
public:
    SortedSet();
    SortedSet(const SortedSet &set);
    SortedSet(const IntList &list);
    ~SortedSet();

    bool in(int value)const;
    SortedSet operator|(const SortedSet &rhs) const;
    SortedSet operator&(const SortedSet &rhs) const;

    void add(int value);
    void push_front(int value);
    void push_back(int value);
    void insert_ordered(int value);
    SortedSet& operator|=(const SortedSet &rhs);
    SortedSet& operator&=(const SortedSet &rhs);
};


#endif //LAB_7__INTLIST_INTRO_SORTEDSET_H
