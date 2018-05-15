// Joanna Ziobrowska

#include "positionlist.h"

PositionList::~PositionList() {
    Node * node = head;
    Node * tmp = 0;
    while (node) {
        tmp = node->next;
        delete node;
        node = tmp;
    }
}

void PositionList::append(int position){
    Node * node = new Node(position);

    if (head == 0) {
        head = node;
    }
    else {
        Node * current_node = head;
        while (current_node->next) {
            current_node = current_node->next;
        }
        current_node->next = node;
    }
}
