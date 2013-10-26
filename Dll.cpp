/*
Doubly Linked List - v 0.1
Dll.cpp
October 25th, 2013
*/
#include "Dll.h"
#include <iostream>
using namespace std;

Dll::Dll()
{
    front = 0;
    back = 0;
    length = 0;

    //itBegin = new Iterator(front);
    //itEnd = new Iterator(back);

}

Iterator Dll::end() 
{
    return Iterator(back);
}

Iterator Dll::begin() 
{
    return Iterator(front);
}

void Dll::pushFront(int val)
{
    Node* t = new Node();
    t->next = front;
    t->prev = nullptr;
    t->data = val;

    if (front == nullptr) 
    {
        back = front = t;
        front->prev = nullptr;
        back->next = nullptr;
    } else {
        front->prev = t;
        front = t;

    }



    length++;
}

void Dll::pushBack(int val)
{
    Node* t = new Node();
    back->next = t;
    t->next = nullptr;
    t->data = val;
    back = t;


    length++;
}
void Dll::pushNode(Iterator& it, int val, int pos)
{
    it.setPos(front);
    
    for(int i = 0; i < pos-1; i++)
    {
       it.goNext();
    }

    if (it.currNode() == front)
    {
        pushFront(val);
    } else if (it.currNode() == back)
    {
        pushBack(val);
    } else 
    {
        Node* t = new Node();
        t->data = val;
        t->next = it.currNode();
        t->prev =  it.currNode()->prev;
        it.currNode()->prev->next = t;
        it.currNode()->prev = t;

    }    

    length++;

}


void Dll::removeNode(Iterator& it)
{
    if (it.currNode() == front)
    {
        auto t = new Node();
        t = front;
        front = front->next;
        front->prev = nullptr;
        it = it.currNode()->next;
        delete t;
    } else if (it.currNode() == back)
    {
        auto t = new Node();
        t = back;
        back = back->prev;
        back->next = nullptr;
        it = it.currNode()->prev;
        delete t;
    } else {
        it.currNode()->prev->next = it.currNode()->next;
        it.currNode()->next->prev = it.currNode()->prev;
        //it = it.currNode()->next;
    }
//    itBegin->setPos(front);
    length--;

}

void Dll::printMe()
{
    Iterator t;
    t.setPos(front);


    for (int i = 0; i < length; i++)
    {
        cout << "Node value at position " << i << " is: " << t.getVal() << endl;
        t.goNext();
    }


}
