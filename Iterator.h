/*
Doubly Linked List - v 0.1
Iterator.h
October 25th, 2013
*/


struct Node 
{
    int data;
    Node* prev;
    Node* next;
};


class Iterator
{
    Node* currN;

public:
    Iterator();
    Iterator(Node* n);
    void goNext();
    void operator++();
    void goPrev();
    void operator--();
    Iterator operator+(int);
    Iterator operator-(int);
    int getVal();
    int getVal(const Iterator&);
    int getDistance(const Iterator&);
    int getDistance(const Iterator&, const Iterator&);
    void setPos(Node* n) { currN = new Node(); currN = n;}
    Node* currNode() { return currN; }
    int dToEnd();
    int dToBegin();
};