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
    auto t = new Node();

    t->next = nullptr;
    t->prev = back;
    t->data = val;

    if (back == nullptr) 
    {
        front = back = t;
        back->next = nullptr;
    } else {
        back->next = t;
        back = t;
    }



    length++;
}


void Dll::pushNode(const Iterator& iter, int val, int pos)
{
    Iterator it;
    it = iter;
    it.setPos(front);
    
    if (length == 0)
    {
        //cout << "Pushing from back" << endl;
        pushBack(val);
        return;
    }

    for(int i = 0; i < pos-1; i++)
    {
       it.goNext();
    }
 
    if (it.currNode() == front)
    {
        pushFront(val);
        return;
    } else if (it.currNode() == back)
    {
        pushBack(val);
        return;
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


void Dll::popFront(Iterator& it)
{
    it.setPos(front);
    removeNode(it);
    length--;
}

void Dll::popBack(Iterator& it)
{
    it.setPos(back);
    removeNode(it);
    length--;
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
        it.setPos(front);
        delete t;
    } else if (it.currNode() == back)
    {
        auto t = new Node();
        t = back;
        back = back->prev;
        back->next = nullptr;
        it = it.currNode()->prev;
        it.setPos(back);
        delete t;
    } else {
        auto t = new Node();
        t = it.currNode();
        it.currNode()->prev->next = it.currNode()->next;
        it.currNode()->next->prev = it.currNode()->prev;
        if (it.currNode()->next) 
        {
            it.setPos(it.currNode()->next);
        } else if (it.currNode()->prev)
        {
            it.setPos(it.currNode()->prev);
        } else {
            it = nullptr;
        }
        delete t;
    }
//    itBegin->setPos(front);
    length--;

}

void Dll::printMe()
{
    Iterator t;
    t.setPos(front);

    if (length >= 1)
    {
        for (int i = 0; i < length; i++)
        {
            cout << "Node value at position " << i << " is: " << t.getVal() << endl;
            t.goNext();
        }
    } else cout << "List is empty" << endl;
}

void Dll::reset(Iterator& t)
{

    while (!isEmpty()) {
        popFront(t);
    }
    front = back = nullptr;
}

bool Dll::isEmpty()
{
    if (length <=0)
    {
        length = 0;
        return true;
    } else {
        return false;
    }
}
