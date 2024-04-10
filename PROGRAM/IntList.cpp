#include "IntList.h"

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList() {
    clear();
}

void IntList::clear() {
    while (!empty()) {
        pop_front();
    }
    head = nullptr;
    tail = nullptr;
}

void IntList::push_front(int value) {
    IntNode *temp = new IntNode(value);
    if (empty()) {
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void IntList::pop_front() {
    if (!empty()) {
        IntNode *temp = head;
        head = head->next;
        delete temp;
    }
}

bool IntList::empty() const {
    return head == nullptr;
}

const int & IntList::front() const {
    return head->value;
}

const int & IntList::back() const {
    return tail->value;
}

ostream & operator<<(ostream &out, const IntList &rhs) {
    IntNode *temp = rhs.head;
    while (temp != nullptr) {
        out << temp->value;
        if (temp->next != nullptr) {
            out << " ";
        }
        temp = temp->next;
    }
    return out;
}

IntList::IntList(const IntList &cpy) {
    head = nullptr;
    tail = nullptr;
    IntNode *temp = cpy.head;
    while (temp != nullptr) {
        push_back(temp->value);
        temp = temp->next;
    }
}

void IntList::push_back(int value) {
    IntNode *temp = new IntNode(value);
    if (empty()) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void IntList::selection_sort() {
    for (IntNode *i = head; i != nullptr; i = i->next) {
        IntNode *min = i;
        for (IntNode *j = i->next; j != nullptr; j = j->next) {
            if (j->value < min->value) {
                min = j;
            }
        }
        int temp = i->value;
        i->value = min->value;
        min->value = temp;
    }
}

void IntList::insert_ordered(int value) {
    if (empty() || value <= head->value) {
        push_front(value);
    } else if (value >= tail->value) {
        push_back(value);
    } else {
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

void IntList::remove_duplicates() {
    for (IntNode *i = head; i != nullptr; i = i->next) {
        IntNode *prev = i;
        IntNode *curr = i->next;
        while (curr != nullptr) {
            if (i->value == curr->value) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
                if (curr == nullptr){
                    tail = prev;
                }
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }
}

IntList & IntList::operator=(const IntList &rhs) {
    // Check for self-assignment
    if (this == &rhs) {
        return *this;
    }

    // Clear the current list
    clear();

    // Copy elements from rhs to this
    for (IntNode *temp = rhs.head; temp != nullptr; temp = temp->next) {
        push_back(temp->value);
    }

    return *this;
}

int pas_neg_count_diff(const int* arr, int size) {
    // Base case: if size is 0, return 0
    if (size == 0) {
        return 0;
    }
    if (arr[0] > 0) {
        return 1 + pas_neg_count_diff(arr + 1, size - 1);
    } else if (arr[0] < 0) {
        return -1 + pas_neg_count_diff(arr + 1, size - 1);
    } else {
        return pas_neg_count_diff(arr + 1, size - 1);
    }
}
