#include "SortedSet.h"
#include <iostream>

using namespace std;

SortedSet::SortedSet() : IntList() { }

SortedSet::SortedSet(const SortedSet &set) : IntList(set) {}

SortedSet::SortedSet(const IntList &list) : IntList(list) {
    remove_duplicates();
    selection_sort();
}

SortedSet::~SortedSet() {
    clear();
}

bool SortedSet::in(int value) const {
    IntNode *temp = head;
    while (temp != nullptr) {
        if (temp->value == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

SortedSet SortedSet::operator|(const SortedSet &rhs) const {
    SortedSet set(*this);
    for (IntNode *temp = rhs.head; temp != nullptr; temp = temp->next) {
        set.add(temp->value);
    }
    return set;
}

SortedSet SortedSet::operator&(const SortedSet &rhs) const {
    SortedSet set;
    for (IntNode *temp = head; temp != nullptr; temp = temp->next) {
        if (rhs.in(temp->value)) {
            set.add(temp->value);
        }
    }
    return set;
}

void SortedSet::add(int value) {
    if (!in(value)) {
        if (empty() || value <= head->value) {
            push_front(value);
        }
        else if (value >= tail->value) {
            push_back(value);
        }
        else {
            IntNode *temp = new IntNode(value);
            IntNode *prev = nullptr;
            IntNode *curr = head;
            while (curr != nullptr && value > curr->value) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = temp;
            temp->next = curr;
        }
    }
}

void SortedSet::push_front(int value) {
    add(value);
}

void SortedSet::push_back(int value) {
    add(value);
}

void SortedSet::insert_ordered(int value) {
    add(value);

}

SortedSet& SortedSet::operator|=(const SortedSet &rhs) {
    *this = *this | rhs;
    return *this;
}

SortedSet& SortedSet::operator&=(const SortedSet &rhs) {
    *this = *this & rhs;
    return *this;
}




