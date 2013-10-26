/*
Doubly Linked List - v 0.1
main.cpp
October 25th, 2013
*/

#include <iostream>
#include "Dll.h"
using namespace std;

int main()

{
    Dll dll;
    Iterator* t = new Iterator(dll.getBegin());
    int i;

    cout << "----Testing pushFront " << endl;
    for (i = 5; i > 0; i--)
    {
        dll.pushFront(i);
    }
    dll.printMe();

    cout << "----Testing pushBack " << endl;
    for (i = 6; i <= 10; i++)
    {
        dll.pushBack(i);
    }
    dll.printMe();


    cout << "----Testing removeNode " << endl;
    t->setPos(dll.getBegin());
    dll.removeNode(*t);
    t->goNext();
    t->goNext(); 
    dll.removeNode(*t);
    dll.printMe();

    cout << "----Testing pushNode " << endl;
    dll.pushNode(*t, 1, 3);
    dll.printMe();

    cout << "----Testing getDistance " << endl;
    t->setPos(dll.getBegin());
    t->goNext();
    t->goNext();
    t->goNext();

    cout << "Distance from end is : " << t->end() << endl;
    cout << "Distance from begin is : " << t->begin() << endl;

    Iterator* v = new Iterator();
    v->setPos(dll.getBegin());
    //v->goNext();

    cout << "Distance between iterators v and t is : " << t->getDistance(*v, *t) << endl;


    int pause;
    cin >> pause;
    return 0;
}