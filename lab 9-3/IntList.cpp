#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
    if (!head) {
        head = new IntNode(val);
    } else {
        IntNode *temp = new IntNode(val);
        temp->next = head;
        head = temp;
    }
}

ostream & operator<<(ostream &out, IntNode *node) {
    if (node == nullptr) {
        return out;
    }
    out << node->value;
    if (node->next != nullptr) {
        out << " ";
    }
    return operator<<(out, node->next);
}

// operator<< function
ostream & operator<<(ostream &out, const IntList &list) {
    return operator<<(out, list.head);
}
bool IntList::exists(int value) const {
   return exists(head, value);
};

bool IntList::exists(IntNode* node, int value) const {
    if (node == nullptr) {
        return false;
    } else if (node->value == value) {
        return true;
    } else {
        return exists(node->next, value);
    }
}