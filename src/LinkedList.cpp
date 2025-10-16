#include "LinkedList.hpp"
#include <sstream>

LinkedList::LinkedList() : head_(nullptr) {}
LinkedList::~LinkedList() {
    Node* p = head_;
    while (p) { Node* n = p->next; delete p; p = n; }
}
void LinkedList::push_front(int v) { head_ = new Node(v, head_); }
void LinkedList::remove_evens() {
    Node dummy(0, head_);
    Node* prev = &dummy;
    Node* curr = head_;

    while (curr) {
        if ((curr->value % 2) == 0) {
            prev->next = curr->next;
            Node* doomed = curr;
            curr = curr->next;
            delete doomed;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    head_ = dummy.next;
}

std::string LinkedList::to_string() const {
    std::ostringstream oss;
    oss << "[";
    Node* p = head_;
    bool first = true;
    while (p) {
        if (!first) oss << ", ";
        first = false;
        oss << p->value;
        p = p->next;
    }
    oss << "]";
    return oss.str();
}
