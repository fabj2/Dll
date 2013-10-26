/*
Doubly Linked List - v 0.1
Iterator.cpp
October 25th, 2013
*/

#include "Iterator.h"
#include <iostream>
using namespace std;

Iterator::Iterator()
{
    currN = nullptr;
}

Iterator::Iterator(Node* n)
{
    currN = new Node();
    currN = n;
}


void Iterator::goNext()
{
    if (currN->next) currN = currN->next;
}

void Iterator::goPrev()
{
    if (currN->prev) currN = currN->prev; 
}

int Iterator::getVal()
{
    return currN->data;
}

int Iterator::getVal(Iterator& it)
{
    return it.currN->data;
}

int Iterator::getDistance(Iterator& it)
{
    return getDistance(*this, it);    
}

int Iterator::getDistance(Iterator& it1, Iterator& it2)
{

    int distance = 0;
    bool done = false;

    if (&it1 == &it2) return distance;

    if (it1.currNode()->next == nullptr) return end();
    if (it2.currNode()->next == nullptr) return end();
    if (it1.currNode()->prev == 0) 
    {
            return begin();
    }
    if (it2.currNode()->next == nullptr) return begin();

    while ((&it1 != &it2) && !done )
    {
        it1.goNext();
        distance++;
        
        if (it1.currNode()->next == 0)
        {
            if (&it1 != &it2) 
            {
                done = true;
                distance = 0;
            }
        }
    }

    for (int n = distance; n > 0; n--) 
        it1.goPrev();

    done = false;
    if (distance == 0)
    {
        while (&it1 != &it2 && !done )
        {
            it1.goPrev();
            distance++;
        
            if (it1.currNode()->prev == 0)
            {
                if (&it1 != &it2) 
                {
                    done = true;
                    distance = 0;
                }
            }
        }
    }

    return distance;      
}

int Iterator::end()
{
    Iterator* tempI = new Iterator();
    tempI->setPos(this->currNode());
    if (this->currNode()->next == 0) return 0;

    int distance = 0;

    do
    {
        tempI->goNext();
        distance++;
    } while (tempI->currNode()->next != nullptr );
    return distance;

}

int Iterator::begin()
{
    Iterator* tempI = new Iterator();
    tempI->setPos(this->currNode());
    if (this->currNode()->prev == 0) return 0;

    int distance = 0;

    do 
    {
        tempI->goPrev();
        distance++;
    } while (tempI->currNode()->prev != nullptr);
    return distance;
}