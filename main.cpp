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
    Iterator b;
    b = dll.getBegin();
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
    b.setPos(dll.getBegin());
    dll.removeNode(b);
    b.goNext();
    b.goNext(); 
    dll.removeNode(b);
    dll.printMe();

    cout << "----Testing pushNode " << endl;
    dll.pushNode(b, 1, 3);
    dll.printMe();

    cout << "----Testing getDistance " << endl;
    b.setPos(dll.getBegin());
    b.goNext();
    b.goNext();
    b.goNext();


    Iterator e = dll.end();

    cout << "Distance between iterators b and e is : " << e.getDistance(b, e) << endl;


    int pause;
    cin >> pause;
    return 0;
}