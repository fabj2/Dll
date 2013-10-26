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
    //Iterator(Iterator&);
    void goNext();
    void goPrev();
    int getVal();
    int getVal(Iterator&);
    int getDistance(Iterator&);
    int getDistance(Iterator&, Iterator&);
    void setPos(Node* n) { currN = new Node(); currN = n;}
    Node* currNode() { return currN; }
    int end();
    int begin();
};