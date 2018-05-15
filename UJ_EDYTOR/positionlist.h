// Joanna Ziobrowska

#ifndef POSITIONLIST_H
#define POSITIONLIST_H

struct Node {
    Node(int position) : next(0), position(position) {}

    Node * next;
    int position;
};

class PositionList{

public:
    PositionList() : head(0) {}
    ~PositionList();

    void append(int position);

    Node * getHead() const { return head; }

private:
    Node * head;
};


class PositionListIterator {

public:
    PositionListIterator(const PositionList & list) : node(list.getHead()) {}
    PositionListIterator() : node(0) {}

    bool hasNext() {
        return node != 0;
    }

    int getValue() {
        return node->position;
    }

    void next() {
        node = node->next;
    }

private:
    Node * node;
};

#endif // POSITIONLIST_H
