/*
Doubly Linked List - v 0.1
main.cpp
October 25th, 2013
*/

#include <iostream>
#include "dll.h"
using namespace std;

int main(int a, char* args[])

{
    Dll* dll = new Dll();
    Iterator b;
    b = dll->getBegin();
    int i;

    cout << "----Testing pushFront " << endl;
    for (i = 5; i > 0; i--)
    {
        dll->pushFront(i);
    }
    dll->printMe();

    cout << "----Testing pushBack " << endl;
    for (i = 6; i <= 10; i++)
    {
        dll->pushBack(i);
    }
    dll->printMe();


    cout << "----Testing removeNode, pop Front&Back " << endl;
    b.setPos(dll->getBegin());
    dll->removeNode(b);
    b.goNext();
    b.goNext(); 
    dll->removeNode(b);
    dll->popBack(b);
    dll->popFront(b);
    dll->printMe();

    cout << "----Testing pushNode " << endl;
    dll->pushNode(b, 1, 3);
    dll->pushNode(b, 0, dll->getLength());
    dll->pushNode(b, 4, 3);
    dll->printMe();

    cout << "----Testing getDistance and operators overloads" << endl;
    b.setPos(dll->getBegin());
    b.goNext();
    b++;
    b++;
    b--;
    b++;
    b = b-2;
    b = b+2;


    Iterator e = dll->end();

    cout << "Distance between iterators b and e is : " << e.getDistance(b, e) << endl;


    cout << "----Testing reset method" << endl;
    b.setPos(dll->getBegin());
    dll->reset(b);
    dll->printMe();
//    dll->pushBack(12);


    cout << "----Testing list building via command parms" << endl;
    if (a > 1) {
        b.setPos(dll->getBegin());
        dll->reset(b);
        b.setPos(dll->getBegin());
        cout << args[0] << " received these parms: ";
        for (i = 1; i < a; i++)
        {
            cout << atoi(args[i]) << " ";
            dll->pushBack(atoi(args[i]));
        }
        cout << endl;
        dll->printMe();
    }

    int pause;
    cin >> pause;
    return 0;
}