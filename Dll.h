/*
Doubly Linked List - v 0.1
Dll.h
October 25th, 2013
*/
#include "Iterator.h"

class Dll
{
private:
    Node* front;
    Node* back;
    int length;
protected:
public:
    Dll(); 
    Iterator begin();
    Iterator end();
    void pushFront(int);
    void pushBack(int);
    void pushNode(Iterator&, int val, int pos);
    void removeNode(Iterator&);
    Node* getBegin() { return front; }
    Node* getEnd() { return back; }
    int getLength() { return length; }
    void printMe();

};